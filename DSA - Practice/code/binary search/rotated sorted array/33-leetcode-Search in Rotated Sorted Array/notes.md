#Notes

---

Explained in babbar dsa Lec #14

---

[7,9,1,2,3]

find 2

suppose we got the pivot (`1` here)
now we have 2 sorted array

7,9
&
1,2,3

check if the `target` is less than arr[last]
if yes:
search in second array
if no:
search in first array

handle case when descending order

if(pivotIndex == last){
search in first array
}
if(pivotIndex == 0){
search in second array
}

first array => 0 to pivotIndex-1
second array => pivotIndex to size-1
