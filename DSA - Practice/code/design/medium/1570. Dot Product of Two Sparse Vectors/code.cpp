/*

Constructor:
When we get the nums, we store the index and value of the non zero elements in nums. (hashmap)
O(N)
N: len of nums

Dot Product:
For every index in mp, multiply with corresponding element in vec.
O(k)
k: nonZeroElements (k <= N)
k will be min(l1, l2)
l1, l2 correspond to the len of non zero elements in vec1 and vec2


# NOTES:
- If one of the vectors is dense and other is sparse, it makes sense to iterate over the sparse vector and then do the dot product (inside the dot product function)
- This way you will make less number of iterations
- But how to find which one is sparse and which one is dense?
- For this you can store the total number of non zero elements in the constructor
- Since in the constructor you are already traversing all elements, there you can maintain a count of all non zero elements and store it in a variable. And then later you can GET that variable and check which one is sparse and which one is dense.




*/
class SparseVector {

    // index -> value
    unordered_map<int, int> mp;

public:
    
    SparseVector(vector<int> &nums) {
        
        // populate mp
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i]) {
                mp[i] = nums[i];
            }
        }
    }

    unordered_map<int, int> getMapOfNonZeros() {
        return mp;
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        

        // get map of both sparse vectors
        unordered_map<int, int>& mp1 = mp;
        unordered_map<int, int> mp2 = vec.getMapOfNonZeros();

        int sum = 0;

        // travserve one of the maps and check if the index is present in other
        for(auto& [index1, value1] : mp1) {

            // if NOT found
            if(mp2.find(index1) == mp2.end()) continue;

            // else if found, then multiply and store the sum
            sum += (value1 * mp2[index1]);
        }

        return sum;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);