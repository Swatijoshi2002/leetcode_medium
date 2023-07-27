class Solution {
public:
    long long maxRunTime(int n, vector<int>& b) {
        long long low=1;
        long long high=accumulate(begin(b),end(b),0LL)/n;
        while(low<high)
        {
           long long mid=(low+high+1)/2;
            long long time=0;
            for(int i=0;i<b.size();i++)
            {
                time=time + min(mid,(long long)b[i]);
            }
            if(time>=mid*n)
            {
                low=mid;
            }
            else high=mid-1;
        }
        return low;
    }
};
