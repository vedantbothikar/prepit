/*

totalZeroes = 0  // counts total zeroes
currentZeroes = 0

left = -1  // position where a non zero item is to be placed
right = 0  // to traverse the array

while(right < n)

    if(arr[right] == 0)
        currentZeroes++
        totalZeroes++
    else if(arr[right] != 0)

        if(currentZeroes > 0)
            // swap the previous zero with this non-zero
            while(left < right) {
                left++;
                if(arr[left] == 0) {
                    arr[left] = arr[right];
                    arr[right] = 0;
                    currentZeroes--;
                    break;
                }
            }

Time: O(N)

*/

class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        
        int n = arr.size();
        int currentZeroes = 0;
        int left = 0;
        int right = 0;

        while(right < n) {

            if(arr[right] == 0) {
                currentZeroes++;
            }
            else {
                    while(left < right) {

                        if(arr[left] == 0) {
                            arr[left] = arr[right];
                            arr[right] = 0;
                            left++;
                            break;
                        }
                        left++;
                    }
            }

            right++;
        }
    }
};