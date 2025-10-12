/*

609. Find Duplicate File in System
Problem Link: https://leetcode.com/problems/find-duplicate-file-in-system/

Please read:
Explanation: https://gist.github.com/vedantbothikar/995cf639083d194cd22277e1fd15f81d


TODO: Read followups here at the solution section:
https://leetcode.com/problems/find-duplicate-file-in-system/solutions/104123/c-clean-solution-answers-to-follow-up/?envType=company&envId=applied-intuition&favoriteSlug=applied-intuition-six-months

*/
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
        // content -> [filepath1, filepath2, ...]
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;

        for(auto path : paths) {

            stringstream ss(path);

            string directory;
            string s;

            // get the directory path
            getline(ss, directory, ' ');

            while(getline(ss, s, ' ')) {

                // get the file name 
                string filename = s.substr(0, s.find('('));
                string filepath = directory + '/' + filename;

                // get the file content
                int startIdx = s.find('(') + 1;
                int endIdx = s.find(')') - 1;
                int lenOfStrFileContent = endIdx - startIdx + 1;
                string fileContent = s.substr(startIdx, lenOfStrFileContent);

                // store in hashmap
                mp[fileContent].push_back(filepath);
            }
        }

        // now check for duplicates
        for(auto x : mp) {
            if(x.second.size() > 1) {
                ans.push_back(x.second);
            }
        }

        return ans;
    }
};