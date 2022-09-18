#NOTES

---

**POINT 1:**
`int` range is from `(-2^31) to (2^31 - 1)`

-2^31 = -2147483648
to
2^31 - 1 = 2147483647

---

**POINT 2:**

`to_string(var)`

converts integers to strings
_var is an integer_

---

**POINT 3:**

reverse(str.begin(), str.end())

This line modifies str and reverses it

_(NOTE: it doesn't return a new string, it modifies the existing string)_

---

**POINT 4:**

Remainder of a negative number is NEGATIVE only.

eg.
-123%10

is -3

and NOT 3

---

**POINT 5:**

bool is 1 **byte**
float is 4 **bytes**

remember it is **bytes** and not **bits**

---

**POINT 6:**

This will print the minimum value in the vector

`cout<< *min_element(v.begin(),v.end())<<endl;`

for max =>
`*max_element(v.begin(), v.end())`

---

**POINT 7:**

to get the integer value of a character

suppose

char ch = '5';

then
int num = ch - '0';

---

**POINT 8:**

char ch ='a'

string str = ch

will not work

BUT

char ch ='a'

string str;

str = ch

will work

---
