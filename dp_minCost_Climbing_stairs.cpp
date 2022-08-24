// //recursive-
// class Solution {
// public:
    
//     int solve(vector<int>& cost, int n){
//         if(n==0||n==1)
//             return cost[n];
//         int ans=cost[n]+ min(solve(cost,n-1), solve(cost, n-2));
//         return ans;
//     }
    
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n=cost.size();
//         int ans=        min(solve(cost,n-1), solve(cost, n-2));

//         return ans;
        
//     }
// };



//dp
class Solution {
public:
    
    int solve(vector<int>& cost, int n, vector<int>&dp){
        if(n==0||n==1)
            return cost[n];
        if(dp[n]!=-1)
            return dp[n];
        dp[n]=cost[n]+ min(solve(cost,n-1, dp), solve(cost, n-2, dp));
        return dp[n];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        int ans=        min(solve(cost,n-1,dp), solve(cost, n-2, dp));

        return ans;
        
    }
};



//tabulation

// class Solution
// {
// public:
//     int solve3(vector<int> &cost, int n)
//     {
//         // 1. creating dp array
//         vector<int> dp(n + 1);

//         // 2. handling base conditions of recursion
//         dp[0] = cost[0];
//         dp[1] = cost[1];

//         // 3. recursive calls ko dp se replace krdo
//         for (int i = 2; i < n; i++)
//         { // isme explicitly last stair ki cost nhi leni he so, not <=n
//             dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
//         }
//         return min(dp[n - 1], dp[n - 2]);
//     }
//     int minCostClimbingStairs(vector<int> &cost)
//     {
//         int n = cost.size();
//         return solve3(cost, n);
//     }
// };


//Space optimization 
class Solution
{
public:
    int solve5(vector<int> &cost, int n)
    {
        // 1. creating dp array
        vector<int> dp(n + 1);

        // 2. handling base conditions of recursion
        int prev1 = cost[0];
        int prev2 = cost[1];

        // 3. recursive calls ko dp se replace krdo
        int cur=0;
        for (int i = 2; i < n; i++)
        { // isme explicitly last stair ki cost nhi leni he so, not <=n
            cur = cost[i] + min(prev1, prev2);
            prev1=prev2;
            prev2=cur;
        }
        return min(prev1, prev2);
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        return solve5(cost, n);
    }
};



// link: https://leetcode.com/problems/min-cost-climbing-stairs/submissions/
