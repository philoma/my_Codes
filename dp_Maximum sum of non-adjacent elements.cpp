//recursion
#include<bits/stdc++.h>
int solve(vector<int> &nums, int n){
    if(n<0)
        return 0;
    if(n==0)
        return nums[0];
    
    int include=solve(nums, n-2)+nums[n];
    int exclude=solve(nums, n-1)+0;
    return max(include, exclude);
    }
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size()-1;
    if(n==0)
        return nums[0];
    
    int ans=solve(nums, n-1);
    return ans;  
}




//dp

#include<bits/stdc++.h>
int solve(vector<int> &nums, int n, vector<int> &dp){
    if(n<0)
        return 0;
    if(n==0)
        return nums[0];
    if(dp[n]!=-1)
        return dp[n];
    int include=solve(nums, n-2, dp)+nums[n];
    int exclude=solve(nums, n-1, dp)+0;
    
    dp[n]=max(include, exclude);
    
    return dp[n];
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    if(n==0)
        return nums[0];
    if(n==1)
        return max(nums[0], nums[1]);
    vector<int>dp(n,-1);
    int ans=solve(nums, n-1, dp);
    return ans;
    
    
}






// tabulation

int solve(vector<int> &nums){
    int n=nums.size();
    vector<int>dp(n,0);
    dp[0]=nums[0];
    for(int i=1;i<n;i++){
        int inc=dp[i-2]+nums[i];
        int exc=dp[i-1]+0;
        dp[i]=max(inc, exc);
    }
    return dp[n-1];
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    return solve(nums);
}










//Optimizing space

int solve(vector<int> &nums){
    int n=nums.size();
     int prev2=0;
    int prev1=nums[0];
    for(int i=1;i<n;i++){
        int inc=prev2+nums[i];
        int excl=prev1+0;
        int ans=max(inc, excl);
        
        //jab i aage badhta he to
        prev2=prev1;
        prev1=ans;
                  }
    return prev1;
     }
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    return solve(nums);
}

//link: https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
