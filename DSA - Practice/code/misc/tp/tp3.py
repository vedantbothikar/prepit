#!/usr/bin/env python3

import struct
import math
import dpkt
import socket
import numpy
from collections import Counter
from frequency import *

"""
Normalization so that they sum to 1
"""
def normalize_probabilities(replacement_probs):

    total_prob = sum(replacement_probs)
    return [p / total_prob for p in replacement_probs]

"""
Finds the replacement byte from the substitution options
"""
def select_replacement_byte(substitution_options):

    # base condition
    if len(substitution_options) == 1:    
        return substitution_options[0][0]

    # find the replacement bytes and their probabilities
    replacement_bytes = [opt[0] for opt in substitution_options]
    replacement_probs = [opt[1] for opt in substitution_options]

    # Normalization
    replacement_probs = normalize_probabilities(replacement_probs)

    # Randomly select one of the replacement bytes
    return numpy.random.choice(replacement_bytes, p=replacement_probs)

"""
Calculate the XOR value for a given byte
"""
def compute_xor_value(original_byte, replacement_byte):

    return ord(original_byte) ^ replacement_byte

"""
This function will encrypt the attacking payload which will internally use the substitution table.
This will generate a result and the XOR table for it.
"""
def substitute(attack_payload, substitution_table):

    encrypted_payload = []
    xor_table = []

    for attack_byte in attack_payload:
        # Using the current attack byte to search for the substitution options
        substitution_options = substitution_table[attack_byte]

        # choose the replacement for this
        selected_byte = select_replacement_byte(substitution_options)

        # add the selected byte to the encrypted payload
        encrypted_payload.append(selected_byte)

        # calculate the xor
        xor_value = compute_xor_value(attack_byte, selected_byte)
        xor_table.append(xor_value)

    return xor_table, encrypted_payload

"""
Find the byte frequencies for both artificial and attack payloads
"""
def calculate_frequencies(artificial_payload, attack_payload):

    artificial_frequency = frequency(artificial_payload)
    attack_frequency = frequency(attack_payload)

    # structure will be: [(byte, freq)]
    sorted_artificial_frequency = sorting(artificial_frequency)  
    sorted_attack_frequency = sorting(attack_frequency)

    return sorted_artificial_frequency, sorted_attack_frequency

"""
One to one mapping between most frequent attack bytes and most frequent artificial bytes
"""
def perform_one_to_one_mapping(sorted_attack_frequency, sorted_artificial_frequency):

    substitution_table = {}

    for i in range(len(sorted_attack_frequency)):
        attack_byte = sorted_attack_frequency[i][0]
        substitution_table[attack_byte] = [
            (sorted_artificial_frequency[i][0], sorted_artificial_frequency[i][1])
        ]

    return substitution_table

"""
Change to one to many mapping by adding other artificial bytes: use the higher frequency ones
"""
def perform_one_to_many_mappingz(substitution_table, sorted_attack_frequency, sorted_artificial_frequency):

    attack_freq_len = len(sorted_attack_frequency)
    normal_art_freq_len = len(sorted_artificial_frequency)

    for j in range(normal_art_freq_len - attack_freq_len):
        max_ratio = 0
        selected_attack_byte = None

        # find the attack byte which has the highest ratio
        for attack_byte, attack_freq in sorted_attack_frequency:
            total_mapped_freq = sum(freq for _, freq in substitution_table[attack_byte])
            ratio = round(attack_freq / total_mapped_freq, 3)

            if ratio > max_ratio:
                max_ratio = ratio
                selected_attack_byte = attack_byte

        # add the artificial buyte to the currently selected attack byte
        next_artificial_byte, next_freq = sorted_artificial_frequency[attack_freq_len + j]
        substitution_table[selected_attack_byte].append((next_artificial_byte, next_freq))

    return substitution_table

"""
create and save to a file
"""
def save_substitution_table(substitution_table, filename="substitution_table.txt"):

    with open(filename, "w") as file:
        for attack_byte, mappings in substitution_table.items():
            mapped_str = ", ".join([f"({chr(b)}, {round(freq, 3)})" for b, freq in mappings])
            file.write(f"{chr(attack_byte)}: {mapped_str}\n")

    print("Saving Substitution Table to: ", filename)

"""
This function maps the attacking bytes with the artifical butes
and it uses ONE to MANY mapping which is based on the frequency differences.
"""
def getSubstitutionTable(artificial_payload, attack_payload):

    # find the frequencies of both the artificical and attack payloads
    sorted_artificial_frequency, sorted_attack_frequency = calculate_frequencies(
        artificial_payload, attack_payload
    )

    # first do one to one mapping
    substitution_table = perform_one_to_one_mapping(
        sorted_attack_frequency, sorted_artificial_frequency
    )

    # now extend to one-to-many mapping
    substitution_table = perform_one_to_many_mappingz(
        substitution_table, sorted_attack_frequency, sorted_artificial_frequency
    )

    # saving to file
    save_substitution_table(substitution_table)

    print("Substitution Table ->", substitution_table)
    return substitution_table