#include<bits/stdc++.h>
using namespace std;


// Function to remove all leading
// zeros from a given string
string removeLeadingZeros(string str)
{
    // Regex to remove leading
    // zeros from a string
    const regex pattern("^0+(?!$)");
 
    // Replaces the matched
    // value with given string
    str = regex_replace(str, pattern, "");
    return str;
}


    int reverse(int x) {

        try
        {
               
        string ans = "";
        int n = x;
        bool neg = 0;


        // check if in range
        if ((n < numeric_limits<int>::lowest()) 
            || (n > numeric_limits<int>::max())) 
        {
            cout<<"not in range";
            return 0;
            
        } 

        // handle negative
        if(n<0){
            n = abs(n);
            neg = 1;
        }
        
        // reverse integer
        while(n!=0){
                
            ans += to_string(n%10);   
            n = n/10;
        
        }


        string result = "";        
        result = removeLeadingZeros(ans);

 
        
        int myans = stoi(result);
        if(neg){
            return (-1)*myans;
        }else{
            return myans;
        }
     
        }
        catch(const std::exception& e)
        {
            return 0;
        }
        
     

        
    }

int main () {



        
        int n;
        cin>>n;
        cout<<reverse(n);

    return 0;
}