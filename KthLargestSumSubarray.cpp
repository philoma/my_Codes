#include <bits/stdc++.h>
int getKthLargest(vector<int> &arr, int k)
{
    //    Write your code here.
    priority_queue<int, vector<int>, greater<int>> mini;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (mini.size() < k) //i.e. queue me k elements hi hone chahye
            {
                mini.push(sum);
            }
            else if (sum > mini.top())
            {
                mini.pop();
                mini.push(sum);
            }
        }
    }

    return mini.top();
}
