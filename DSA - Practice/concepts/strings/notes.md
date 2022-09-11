## STRINGS

---

at the end of the character array, null is stored
`\0`
this is used as a terminator
this indicates where the string ends

![null character](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/79f949a4-5c36-44bd-ad2e-150f0144ebe1/Screenshot_from_2022-09-10_13-38-44.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20220910%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20220910T080911Z&X-Amz-Expires=86400&X-Amz-Signature=79ff09b7a1c78370c0623a94e40fd5a57b01d81868e90f083272dfa20afd6d43&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D"Screenshot%2520from%25202022-09-10%252013-38-44.png"&x-id=GetObject)

---

your cin for character array will stop entering name when

- you give a space `(" ")`
- a new line is given `(\n)`
- a tab is given `(\t)`

this means that if you enter the name as `vedant bothikar`

it will only take `vedant` as the input
because then it stops

To solve this issue: use `getline`

```
string s;
getline(cin, s);
cout << s << endl;
```

---

```
char ch = 'A';

// this returns true if it is alpha numeric character

isalnum(ch);

// converts to lower case
tolower(ch);

```

---

To find the length of a character array

```
char arr[] = {'a', 'b', 'c', 'd'};

cout<< strlen(arr);
```

---

String compare:

`strcmp(s1, s2);`

**returns 0 when they are equal**

---

string to integer
`stoi('0')`

---

**Read:**
https://www.geeksforgeeks.org/substring-in-cpp/

string str = "vedant";

// substring from index 2 and lenght 4
str.substr(2,4);

---

Insert:

https://www.geeksforgeeks.org/stdstringinsert-in-c/

// Inserts "vedant" at 5th index of str
`str.insert(5, "vedant");`

---

Replace:

https://www.geeksforgeeks.org/stdstringreplace-stdstringreplace_if-c/

// Replaces 7 characters from 0th index by s2
`s1.replace(0, 7, s2);`

---
