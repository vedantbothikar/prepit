/*

2 numbers given, lowNum and highNum

LCM:
- Need to find between highNum and lowNuk*highNum

GCD:
- Need to find between 1 and lowNum (in reverse order)

*/

/*
 THIS IS SLOW WAY TO SOLVING THIS
 THERE IS A TRICK: REMEMBER THIS EQUATION

For two numbers n1 and n2, the lcm and gcd

lcm * gcd = n1 * n2


REMEMBER THIS IS ALWAYS TRUE


*/

class Solution {
  public:
    vector<long long> lcmAndGcd(long long A , long long B) {
        // code here
        
        vector<long long> ans;
        long long lowNum = A > B ? B : A;
        long long highNum = A > B ? A : B;
        
        long long maxLcm = lowNum*highNum;
        
        long long lcm = highNum;
        while(lcm < maxLcm){
            
            if(lcm % lowNum == 0 and lcm % highNum == 0){
                break;
            }
            
            lcm++;
        }
        
        long long gcd = lowNum;
        while(gcd >= 1){
            
            if(lowNum % gcd == 0 and highNum % gcd == 0){
                break;
            }
            
            gcd--;
        }
        
        ans.push_back(lcm);
        ans.push_back(gcd);
        
        return ans;
    }
};