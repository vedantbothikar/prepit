    /*
    For this question ask ChatGPT/Copilot to explain the code and solution explanation in simple terms
    
    
    */
    
    
    long long count(int n) {
        // your code here
        
        long long int edges = (n*(n-1))/2;
        
        return 1LL<<edges;
    }