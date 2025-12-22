/*

https://leetcode.com/problems/find-the-town-judge/description/

997. Find the Town Judge

hwo to check if everyone trusts this guy x

trustingOn
1 : {2,3,4}
1 trusts 2,3, and 4

beingTrusted
2: {1}
2 is being trusted by 1

- we can populate these 2 hashtables in single iteration of the trust list
- now we can check if there is any person that does NOT exist in trustingOn
    - if there are multiple such people: return false (condition 1 violated)
- if we are here, that means there exists ONE person that trusts nobody
- so now we have to check if everybody trusts that person
    - so all we have to do is check if the beingTrusted[key].size() is n-1





*/
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        unordered_map<int, vector<int>> trustingOn;
        unordered_map<int, vector<int>> beingTrusted;

        // traverse turst list
        for(vector<int>& t : trust) {
            int t1 = t[0];
            int t2 = t[1];
            
            cout << "t1, t2: " << t1 << ", " << t2 << endl;

            trustingOn[t1].push_back(t2);
            beingTrusted[t2].push_back(t1);
        }

        // Checking condition1
        // check for a person NOT present in trustingOn
        bool found = false;
        int potentialJudge;
        for(int i = 1; i <= n; i++) {
            
            if(trustingOn.find(i) == trustingOn.end()) {
                cout << "here for i: " << i << endl;
                if(found) return -1; // condition3 check
                potentialJudge = i;
                found = true;
            }
        }

        // return -1 if no potentialJudge found
        // Check Example3 in problem statement: for why we need this condition
        if(!found) return -1;

        // now that we have potential jude, check condition2
        if(beingTrusted[potentialJudge].size() != n-1) return -1;

        return potentialJudge;
    }
};