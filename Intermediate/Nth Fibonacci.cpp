int dp[1001];

class Solution {
  public:
  
    long long int nthFibonacci(long long int n){
        if(dp[n]){
            return dp[n];
        }
            if(n<=1)
        {
            dp[n] = n%1000000007;
        }
        else{
            dp[n] = (nthFibonacci(n-1)%1000000007+nthFibonacci(n-2)%1000000007)%1000000007;
        }
        
        return dp[n]%1000000007;
        
    }
};
