/*


3043. Find the Length of the Longest Common Prefix
- https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/description/

Watch: https://youtu.be/06dIUJwdHlQ?si=WQ5IHTNI714KK0fb


- we will be inserting all of the prefixes of all numbers of arr1 in a hashset
- then check if the longest prefixes of nums in arr2 exist in the hashset

to get prefix we can do 
num / 10

to get the length of the prefix, we can convert to string and calculate the size


TC: O(n + m)


*/
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        int n = arr1.size();
        int m = arr2.size();

        // optimization: store the prefixes of smaller arr in hashset
        if(n > m) {
            // swap arr1 and arr2
            vector<int> temp = arr1;
            arr1 = arr2;
            arr2 = temp;
        }

        unordered_set<int> prefixList;
        // insert all prefixes of all nums of arr1 in hashset
        for(int num : arr1) {

            while(num) {
                prefixList.insert(num);
                num = num / 10;
            }
        }

        int maxLenPrefix = 0;
        // now check if the prefixes of arr2 exist in hashset
        for(int num : arr2) {

            // optimization: start by checking the entire num
            // then keep reducing the num to check smaller prefixes
            // the first prefix found in hashset, we stop and check len
            // we dont check smaller prefixes because if larger size is found, that is
            // always going to be larger (and we want max len ans)

            while(num) {

                // check if prefix exists in hashset
                if(prefixList.count(num)) {
                    break;  // prefix found in hashset, now check len 
                }

                num = num / 10;
            }

            // edge case: if num is 0 (that means no prefix was found in hashset): ignore
            // and num cant be 0 originally as per problem contraints
            if(num != 0) {
                
                string snum = to_string(num);
                int currNumSize = snum.size();

                maxLenPrefix = max(maxLenPrefix, currNumSize);
            }

        }

        return maxLenPrefix;
    }
};