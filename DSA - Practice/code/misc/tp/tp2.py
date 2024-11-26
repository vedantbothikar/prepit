#!/usr/bin/env python3

import struct
import math
import random
from frequency import *
from collections import Counter

# find the max freq distribution difference byte
def find_frequency_difference(artificial_frequency, raw_frequency):
    max_difference = 0
    padding_byte = None

    for curr_byte, art_freq in artificial_frequency.items():
        raw_freq = raw_frequency.get(curr_byte, 0)
        curr_freq_difference = art_freq - raw_freq

        # if the current difference is greater than the maximum difference so far
        if curr_freq_difference > max_difference:
            max_difference = curr_freq_difference
            padding_byte = curr_byte    # udpate the padding_byte that is to be returned

    return padding_byte

'''
The goal of this function is make sure that the raw_payload_frequency's
distribution matches with the artificial one.
So, essentially we will have to add the the byte that is missing the most (this is the one that has
most highest frequency difference)
'''
def padding(artificial_payload, raw_payload):

    # finding frequencies
    artificial_frequency = frequency(artificial_payload)
    raw_payload_frequency = frequency(raw_payload)

    # Find the padding byte: (one with max freq distribution difference)
    padding_byte = find_frequency_difference(artificial_frequency, raw_payload_frequency)

    # add the padding byte to raw_payload
    if padding_byte:
        raw_payload.append(padding_byte)

    return raw_payload