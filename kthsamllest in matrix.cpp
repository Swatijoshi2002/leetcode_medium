class Solution {
public:
    int kthSmallest(vector<vector<int>>& a, int k) {
        int n=a.size();
        int ans=0;
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                v.push_back(a[i][j]);
            }
        }
        sort(v.begin(),v.end());
        return v[k-1];
    }
};
