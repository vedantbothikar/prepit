#Notes

1910. Remove All Occurrences of a Substring

https://leetcode.com/problems/remove-all-occurrences-of-a-substring/

Find function:
https://cplusplus.com/reference/string/string/find/

Erase function:
https://cplusplus.com/reference/string/string/erase/

```
std::string str ("There are two needles in this haystack with needles.");
std::string str2 ("needle");

// different member versions of find in the same order as above:
std::size_t found = str.find(str2);
if (found!=std::string::npos)
std::cout << "first 'needle' found at: " << found << '\n';

```

for vectors npos might be `v.end()`
(not sure, get it confirmed)
