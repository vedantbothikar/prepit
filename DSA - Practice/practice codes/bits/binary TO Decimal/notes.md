#Notes

TODO:

1. solve for displaying negative numbers in their binary representation

DISPLAY BINARY REPRESENTATION OF A DECIMAL NUMBER

Example:
input: 5
output: 101

---

Solution:

we need to take the bits one by one from right end and then display them

For example:

100101

we will AND it with 1
so that we get the last bit

Now,
last_bit = 1
(this will be in ones place, so multiple it with 10^0)

similarly when we get the second last bit
we need to multiply it with 10^1

and so on...
