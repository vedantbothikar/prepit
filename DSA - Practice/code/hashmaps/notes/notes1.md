## NOTES

---

Watch the video part explaining **why do we need hashmaps**

It is really informative

https://youtu.be/7mUKGHznpfg?t=270

---

Ordered map -> complexities are
O(logn)

Unordered map -> complexities are
O(1)

---

There will only be **unique** keys

- no duplicate keys

if you write

`m["vedant"] = 30;`

And then you write

`m["vedant"] = 300;`

then the value is **updated**

---

when you access a key that has never been inserted

1. when you access it using square brackets
   you get value as `0`

2. when you access it using `at` keyword
   then you get `error out of range`

`terminate called after throwing an instance of 'std::out_of_range'`

Reason:

square brackets initializes the key with a zero value

Now,
Suppose you try to access the unknown value using square brackets first and then access it using at keyword
Then you won't get any error. You will get ans as 0
WHY? because the the key is already created and initialized with value as zero when we access it using square bracket in the first step

**Checkout `illustration3` code**

---

COUNT

it is usually used to check if the key exists or not

if not, it returns 0

---
