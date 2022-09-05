#Notes

s: space

# A]

s s s @
s s @ @
s @ @ @
@ @ @ @

### Observation

print spaces `n-row-1` times

loop `n-row-1` times
=> print <space>

loop `row+1` times
=> print @

---

# B]

@ @ @ @
s @ @ @
s s @ @
s s s @

first while loop: for spaces
will run `row` times

second while loop: for @
will run `n-row` times

---

# C]

1 2 3 4
s 2 3 4
s s 3 4
s s s 4

spaces loop:
run `row` times

numbers loop:
run `n-row` times
print `row+1` + `col`

(it is same as B] ... just print `row+1+col` instead of star)

---

# D]

_assuming `col` & `row` start from 0_

s s s 1
s s 1 2 1
s 1 2 3 2 1
1 2 3 4 3 2 1

_divide the problem in 3 parts: spaces, increasing numbers and decreasing numbers_

increasing numbers:
1
1 2
1 2 3

decreasing numbers
\_
1
2 1
3 2 1

### Logic:

col = 0

**spaces loop:**

run `n-row-1` times
print space

col = 0

**numbers part1 (increasing order numbers):**

run `row+1` times
print `col+1`

keep incrementing `col`

col = 0

**numbers part2 (decreasing order numbers):**

run `col` < `row+1` times

_note that every number starts from `row`_

_keep decreasing the start value_
print `row-col`

`col++`

---

# E]

1 2 3 4 4 3 2 1
1 2 3 s s 3 2 1
1 2 s s s s 2 1
1 s s s s s s 1

### Logic:

col = 0

**increasing numbers:**
run `n-row` times
print `row+1 +col`
col++

col = 0

**spaces:**
run for `row` times
print space
print space

_print space two times because first space will be for increasing numbers triangle and second space will be for decreasing numbers triangle_

col = 0

**decreasing numbers:**
run for `n-row` times
print `n-row-col`
