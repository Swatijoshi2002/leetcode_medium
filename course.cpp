class Solution {
public:
bool dfs(vector<vector<int>>&adj, vector<bool>&vis, vector<bool>&vis2, int s)
{
    vis[s]=true;
    vis2[s]=true;
    for(auto x:adj[s])
    {
       if(vis[x]==false && dfs(adj,vis,vis2,x)) return true;
       else if(vis2[x]==true) return true;
    }
    vis2[s]=false;
    return false;

}
    bool canFinish(int numCourses, vector<vector<int>>& graph) {
        int n=numCourses;
        vector<bool>vis(n,false);
        vector<bool>vis2(n,false);
        vector<vector<int>>adj(n);
        for(auto x:graph)
        {
            adj[x[1]].push_back(x[0]);
        }
      for(int i=0;i<n;i++)
      {
          if(vis[i]==false)
          {
              if(dfs(adj,vis,vis2,i))
              { 
                  return false;
              }
          }
      }
return true;
    }
};
