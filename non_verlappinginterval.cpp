class Solution {
public:
static bool compare(const pair<int,int>&a,const pair<int,int>&b)
{
    auto p1=a;
    auto p2=b;
    return p1.second<p2.second;
}
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    vector<pair<int,int>> v;
    for(int i=0;i<intervals.size();i++)
    {
      v.push_back(make_pair(intervals[i][0],intervals[i][1]));
    }
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<intervals.size();i++)
    {
      cout<<v[i].first<<" "<<v[i].second<<endl;
    }
  

    int end=v[0].second;
    int ans=v.size()-1;
    for(int i=1;i<v.size();i++)
    {
        if(v[i].first>=end)
        {
            ans--;
            end=v[i].second;
        }
    }
    return ans;
    }

};
