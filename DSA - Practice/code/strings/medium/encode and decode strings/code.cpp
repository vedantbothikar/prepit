/*

- https://neetcode.io/problems/string-encode-and-decode
- https://youtu.be/B1k_sxOSgv8

If I put #, then i wont be able to differentiate between the hash 
of the start of the string and the delimeter hash

What if I put # followed by the length of the string?

#4neet#4code#4love#3you
In this case, first I see hash and then the length of string,
so I travel for lenOfStr times, for decoding
Then again look for hash and the number
O(N): decoding

But what if the length is double digit like 12
and the string also starts with 12, then you will get confused of
how many numbers to read

Can we also keep the length of the delimeter?
Like 

1#4neet1#4code1#4love1#3you

So, first we will read the string characters until we reach a hash,
these characters will be the length of the delimeter ahead
So, here initally encountering 1 means than we need to read 1 character 
ahead of hash, for understanding the length of the string
And after that, the actual string will start appearing

*/

class Solution {

    int countNumberOfDigits(int num) {

        int numOfDigits = 0;
        while(num > 0) {

            num = num / 10;
            numOfDigits++;
        }

        return numOfDigits;
    }

public:

    string encode(vector<string>& strs) {

        string ans = "";
        for(string s : strs) {
            
            int numOfDigitsOfStrLen = countNumberOfDigits(s.length());

            ans += to_string(numOfDigitsOfStrLen) + '#' + to_string(s.length()) + s;
        }

        return ans;
    }

    vector<string> decode(string s) { 

        vector<string> ans;
        int lengthOfStringLen = 0;
        bool readingLenOfStrLen = true;

        for(int i = 0; i < s.length(); i++) {
            
            // read characters until you reach '#'. This is lengthOfString
            if(s[i] != '#' and readingLenOfStrLen) {

                lengthOfStringLen = lengthOfStringLen*10 + (s[i] - '0');
                continue;
            }

            // skip the hash character
            if(s[i] == '#') {

                readingLenOfStrLen = false;
                continue;    
            }

            // read lengthOfStringLen characters, this will be the actual lengthOfString
            int currentStrLen = 0;
            int temp = i;
            while(lengthOfStringLen) {

                currentStrLen = currentStrLen*10 + (s[i] - '0');
                
                // i++;
                i++;
                lengthOfStringLen--;
            }
            
            // read lengthOfString characters ahead, put that in the ans vector, then repeat
            string currentStr = "";
            for(int k = 0; k < currentStrLen; k++) {
                
                currentStr += s[i];
                i++;
            }
            i--;    // reduce by 1 because, when we continue the main for loop, the i will be incremented again

            // since we have now completed reading the currentStr, reset to default
            readingLenOfStrLen = true;

            ans.push_back(currentStr);
        }

        return ans;
    }
};
