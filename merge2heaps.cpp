class Solution
{
    void heapify(vector<int> &ans, int i, int size)
    {
        int largest = i;
        int left = 2 * largest + 1;
        int right = 2 * largest + 2;
        if (ans[left] > ans[largest] && left < size)
        {
            largest = left;
        }
        if (ans[right] > ans[largest] && right < size)
        {
            largest = right;
        }

        if (largest!=i)
        {
            swap(ans[i], ans[largest]);
            heapify(ans, largest, size);
        }
    }

public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
    {
vector<int>ans;
        for(auto i:a){
            ans.push_back(i);
        }
        for(auto i:b){
            ans.push_back(i);
        }
        int size = ans.size();

        for (int i = (size/2)-1; i>=0;i--)
        {
            heapify(ans, i, size);
        }
//link: https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1
        return ans;
    }
};
