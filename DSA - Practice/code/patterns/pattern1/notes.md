#Notes

# RECTANGULAR PATTERNS: Numbers & Characters

---

# a]

1 2 3
4 5 6
7 8 9

### Observation

we need to keep a variable
and display its value
this variable will be incremented on every display

---

# b]

1 1 1
2 2 2
3 3 3

### Observation

In every row, we are displaying the `row+1`

---

# A]

1 2 3 4
1 2 3 4
1 2 3 4
1 2 3 4

### Observation:

inside every row, the column's value is `col+1`

---

# B]

4 3 2 1
4 3 2 1
4 3 2 1
4 3 2 1

---

# CHARACTER QUESTIONS

---

# C]

<span style="color:red">IMP QUESTION</span>

A A A
B B B
C C C

### Incrementing a letter:

https://stackoverflow.com/questions/8487255/how-do-i-increment-letters-in-c#:~:text=All%20in%20all%20char%20is,You%20will%20get%20'%5B'%20%3DP

You can use 'a'+((letter - 'a'+n)%26); assuming after 'z' you need 'a' i.e. 'z'+1='a'

(char)('a' + ((letter - 'a' + 1) % 26))

##### NOTE:

Another way
`char ch = 'A' + row - 1;`
`cout<<ch;`

---

# D]

A B C
A B C
A B C

we need to display `letter+col`

---

# E]

A B C
D E F
G H I

display `letter+count`

---

# F]

A B C
B C D
C D E
D E F

starting every row from `letter+row`
then in every iteration of column increment by `col`

so display
`letter+row + col`

---
