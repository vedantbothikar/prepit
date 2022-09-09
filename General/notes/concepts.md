# NOTES - CONCEPTS

---

**CONCEPT 1:**

**FUNCTION CALL STACK**

![func call stack image](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/57734faf-c92f-430b-9754-23458265f07e/Screenshot_from_2022-09-04_15-06-32.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20220904%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20220904T093757Z&X-Amz-Expires=86400&X-Amz-Signature=6c8a87b0a14c03ef26613e9bd6394564599ff2aa4f7f85add46c851adc842994&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22Screenshot%2520from%25202022-09-04%252015-06-32.png%22&x-id=GetObject)

![code](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/134b6526-13ac-480e-a3ed-822866e96872/Screenshot_from_2022-09-04_15-07-44.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20220904%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20220904T094018Z&X-Amz-Expires=86400&X-Amz-Signature=76ac3cfded159cdffda48b91b5298d76c77cd9a255170455b9e8e473bfed254c&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22Screenshot%2520from%25202022-09-04%252015-07-44.png%22&x-id=GetObject)

---

**CONCEPT 2:**

**PASS BY VALUE**

int fun (int n){

    // change n
    // this `n` is a copy... it is not the same as the n of
    // main function
    n++;
    cout<<n;  // prints 6

}

int main(){

    int n = 5;

    cout<<n;  // prints 5
    fun(n);
    cout<<n; // prints 5

}

BUT BUT BUT

int fun(int arr[]){

    // update 1st element of array

}

int main(){

    int arr[5] = [1,2,3,4,5]

    fun(arr)

    print array
    // when you print... the array is updated (it doesn't stay as earlier)

}

REASON:
we are passing the address of the array
this is why the array values are changed when we update it in the function

---

**CONCEPT 3:**

Please read the following article:
https://www.geeksforgeeks.org/different-ways-to-initialize-all-members-of-an-array-to-the-same-value-in-c/#:~:text=int%20num%5B5%5D%20%3D%20%7B,value%201%20at%20all%20index.&text=The%20array%20will%20be%20initialized,0%20in%20the%20initializer%20list.

Initialising an array

`int nums[3] = {1,2,3};`

_// initialises all of the values to zero_
`int nums[100] = {0}; `

**NOTE:**
_// this will **NOT** initialise the entire array to 1_
`int nums[100] = {1}; `

You can use `Designated Initializer` mentioned in the above gfg article

`int num[5]={ [0 . . . 4 ] = 3 }; `

_// initialises with garbage values_
`int nums[100];`

---

**CONCEPT 4:**

How is the T.C. for binary search O(logn) ??

watch https://youtu.be/YJeoQBevNVo?t=2110

we have to find k because that is the number of comparisons that will take place in the worst case

---

**CONCEPT 5:**

https://www.geeksforgeeks.org/internal-details-of-stdsort-in-c/

Best Case – O(N log N)
Average Case- O(N log N)
Worse Case- O(N log N)

The algorithm used by sort() is IntroSort. Introsort being a hybrid sorting algorithm uses three sorting algorithm to minimize the running time, Quicksort, Heapsort and Insertion Sort. Simply putting, it is the best sorting algorithm around. It is a hybrid sorting algorithm, which means that it uses more than one sorting algorithms as a routine.

Standard C library provides qsort() that can be used for sorting an array. As the name suggests, the function uses QuickSort algorithm to sort the given array

It is better to use sort() instead of qsort() because:

sort() does not use unsafe void pointers like qsort().
qsort() makes large number of function calls for comparison function compared to sort().
C++ code with sort() is relatively faster than code with qsort().

---

**CONCEPT 6:**

---

**CONCEPT 7:**

---

**CONCEPT 8:**

---

**CONCEPT 9:**

---

**CONCEPT 10:**
