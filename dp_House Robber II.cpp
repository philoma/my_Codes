#define ll int long long
ll solve(vector<ll> &nums){
    int n=nums.size();
     ll prev2=0;
    ll prev1=nums[0];
    for(int i=1;i<n;i++){
        ll inc=prev2+nums[i];
        ll excl=prev1+0;
        ll ans=max(inc, excl);
        
        //jab i aage badhta he to
        prev2=prev1;
        prev1=ans;
                  }
    return prev1;
     }
long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    int n=valueInHouse.size();
    if(n==1)
        return valueInHouse[0];
    
    vector<ll>first, second;
    
    for(int i=0;i<n;i++)
    {
        if(i!=n-1)
            first.push_back(valueInHouse[i]);
        if(i!=0)
            second.push_back(valueInHouse[i]);
    }
    
    return max(solve(first), solve(second));
}
//link: https://www.codingninjas.com/codestudio/problems/house-robber_839733?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
