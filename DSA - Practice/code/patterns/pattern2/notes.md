#Notes

# TRIANGULAR PATTERNS: Numbers & Characters

---

# A]

@
@ @
@ @ @
@ @ @ @

### Observation:

number of times printing is equal to `row+1`

so `col` loop will run for 0 to `row+1` number of times

---

# B]

1
2 2
3 3 3
4 4 4 4

### Observation:

every value is equal to value of `row+1`

---

# C]

1
2 3
4 5 6
7 8 9 10

### Observation:

every value is equal to a count

---

# D]

1
2 3
3 4 5
4 5 6 7

### Observation:

start displaying every row elements from `row+1`

`col` loop will run from 0 to `row`

which means that every value will be equal to
`row+1 + col`

---

# E]

1
2 1
3 2 1
4 3 2 1

### Observation:

in each row, start from last value
last value in `row+1`
keep reducing `row+1`

which means
value is
`row+1 - col`

---

F]

A
B B
C C C

display `letter+row`

---

G]

A
B C
D E F
G H I J

Assuming `letter` starts from 'A' & `count` starts from 0

display `letter+count`

---

H]

A
B C
C D E
D E F G

every row elements start from `letter+row`

as we go ahead, increment element with `col`

I]
D
D C
D C B
D C B A

start from `letter + n-1`
decrease `col` every time

display `letter+n-1 - col`

J]

D
C D
B C D
A B C D

start from `letter +n-1 -row`
increment `col`

display `letter +n-1 -row +col`
