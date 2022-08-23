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
