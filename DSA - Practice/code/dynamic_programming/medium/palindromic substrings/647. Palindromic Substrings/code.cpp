class Solution {
public:
    int countSubstrings(string s) {

        int n = s.size();

        // base condition
        if(n == 1) return 1;

        int count = 0;

        // CASE 1: Odd palindromes
        for(int i = 0; i < n; i++) {

            count++;

            // expand
            int left = i-1;
            int right = i+1;
            while(left >= 0 and right <= n-1) {

                if(s[left] != s[right]) break;
                
                count++;
                
                left--;
                right++;
            }
        }

        // CASE 2: Even palindromes
        for(int i = 0; i < n; i++) {
            
            int current = i;
            int next = i + 1;
            if(next > n-1 or s[current] != s[next]) continue;

            count++;

            // expand
            int left = current-1;
            int right = next+1;
            while(left >= 0 and right <= n-1) {

                if(s[left] != s[right]) break;
                
                count++;

                left--;
                right++;
            }
        }  

        return count;  
    }
};