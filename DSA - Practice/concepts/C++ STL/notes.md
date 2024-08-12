# NOTES

---

**Things under C++ STL**

Flow chart Link
https://whimsical.com/c-stl-XVxuHHof5GTWA4NXZhXQhx

![Things under C++ STL](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/6b333d8d-e0a2-4ac1-98c1-8edac2159034/Screenshot_from_2022-09-09_15-34-39.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20220909%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20220909T100550Z&X-Amz-Expires=86400&X-Amz-Signature=e1d53040384b5ae064107bf1e4adfcbf9dd052e22f3c5dbb4e7e13b3f2f7f5ab&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D"Screenshot%2520from%25202022-09-09%252015-34-39.png"&x-id=GetObject)

---

**VECTOR**

- Intially the vector's capacity & size both will be 0
- In clear, the size becomes 0 but the capacity stays the same

---

CLEARING all elements of vector

METHOD1:
assign the vector to a new empty vector
TC: O(1)

vec = vector<int>();

_above is best way_

METHOD2:
Using the clear() method:
The clear() method removes all elements from the vector, making its size 0. However, it does not change the capacity of the vector.
Time Complexity: O(n) where n is the number of elements in the vector.

vec.clear(); // vec is now empty
