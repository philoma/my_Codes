#include<bits/stdc++.h>
using namespace std;

int f(int n, int dp[]){
    if(n==0||n==1)
        return n;
    if(dp[n]!=-1)
        return dp[n];
    dp[n]=f(n-1, dp)+f(n-2, dp);
    return dp[n];
}

int main()
{
        /*
        *  Write your code here. 
         *  Read input as specified in the question.
         *  Print output as specified in the question.
        */
    int n;
    cin>>n;
    int dp[n+1];
    for(int i=0;i<n+1;i++){
        dp[i]=-1;
    }
    cout<<f(n,dp);
}


// //using bottom-up/tabulation method
// class Solution {
// public:
//     int fib(int n) {
//         int dp[n+1];
//         dp[0]=0;
//         if(n>=1)
//             {dp[1]=1;
//         for(int i=2;i<=n;i++){
//             dp[i]=dp[i-1]+dp[i-2];
//         }}
//         return dp[n];        
//     }
// };




//just variable ka kheil
class Solution {
public:
    int fib(int n) {
        int prev1=0;
        int prev2=1;
        if(n==0||n==1)
            return n;
        int cur;
        for(int i=2;i<=n;i++){
            cur=prev1+prev2;
            prev1=prev2;
            prev2=cur;
        }
        return cur;
    }
};
