/*

the problem with simply joining the strings to a single string is that you cannot identify where the separator is.
For separator, we can maintain a # between two strings, but then the problem is that the string itself might have #, so how can we separate those 2 hashes?

what if we keep a string length count as well? at the beginning of the string
    - what if the string length count is of 2 digits or more?

Hello World

5#Hello5#World

all digits until the hash will tell us the length of the string to be read
the hash will tell us that we have to stop reading the length and now onwards the string will start... read the length of the string number of characters ahead and store it in a string, then again follow the same process


*/
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        
        string ans = "";
        for(string s : strs) {

            int n = s.size();
            ans = ans + to_string(n) + "#" + s;
        }

        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        
        vector<string> ans;
        for(int i = 0; i < s.size(); i++) {
            
            // read the length of the string
            string wordLenStr = "";
            while(s[i] != '#') {

                wordLenStr += s[i];
                i++;
            }

            i++;    // ignoring the hash

            // read the current word 
            int wordLen = stoi(wordLenStr);
            string currWord = "";
            while(wordLen) {
                
                currWord += s[i];
                
                i++;
                wordLen--;
            }

            i--;    // bringing back to normal, preparing for next iteration
            
            ans.push_back(currWord);
        }

        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));