#Notes

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
