class Solution {
public:
bool dfs(vector<vector<int>>&adj,vector<bool>&vis2,vector<bool>&vis,int s)
{
    vis2[s]=true;
    vis[s]=true;
    for(auto x:adj[s])
    {
      if(vis[x]==false && dfs(adj,vis2,vis,x))
      return true;
      else if(vis2[x]==true)
      {
          return true;
    }
}
vis2[s]=false;
return false;

}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> terminals;
         vector<vector<int>>adj(n);
         for(int i=0;i<n;i++)
         {
             for(int j=0;j<graph[i].size();j++)
             {
                 adj[i].push_back(graph[i][j]);
             }
         }
         vector<bool> vis(n,false);
          vector<bool> vis2(n,false);
          for(int i=0;i<n;i++)
          {
              if(vis[i]==false)
              dfs(adj,vis2,vis,i);
              
          }
          vector<int>v;
          for(int i=0;i<vis2.size();i++)
          {
              if(vis2[i]==false) v.push_back(i);
          }
          return v;
    }
};
