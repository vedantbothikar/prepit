#Notes

---

_here relevant bits mean that ones which we require
it doesn't have any technical definition_

**`code2.cpp`**

When we want to complement the bits
we can use `~` (NOT) operator

But the problem here is that

when
0000 .... 101

is complemented using NOT operator
we get

111 ...11**010**

which means that the required(relevant) bits are complemented
BUT, the irrelevant bits are also complemented

Here the above leading 0 bits are also complemented unnecessarily... this means that the answer will change and not match to correct answer

So, essentially we want just the last x number of bits that are relevant
For this we use a `mask`

suppose we AND (&) the above complemented number with a mask

here mask = 000 ... 00**111**

Then after AND operation, the final answer will be

000 ... 00**010**

which is what we exactly want

NOW,
how can we get this mask?

observe that the mask will have only the last x number of bits set
(only relevant bits are set)

So, we take initially

mask = 000 ... 00000

Now, OR the `mask` with `1` and then `left shift` the `mask`
repeat this for `x` number of times

(actually it should be first left-shift then OR with 1)

---

**How to get x?**

x = 0;
while(n!=0){

    x++;
    n = n>>1;

}

---

**x is the number of times you need to OR mask with 1**

**so essentially we have to do**

---

while(n!=0){

    mask = mask<<1;
    mask = mask | 1;

    n = n>>1;

}

---
