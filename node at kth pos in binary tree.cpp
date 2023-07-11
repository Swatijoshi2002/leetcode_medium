/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
vector<int> res;
void parents(unordered_map<TreeNode*,TreeNode*> &m,TreeNode* root)
{
    if(root==NULL)return ;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode *current=q.front();
        q.pop();
        if(current->left)
        {
             m[current->left]=current;
             q.push(current->left);
        }

        if(current->right)
        {
             m[current->right]=current;
             q.push(current->right);
        }
    }
    return;
}
 vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
      unordered_map<TreeNode*,TreeNode*> m;
      parents(m,root);

      queue<TreeNode*> q;
      q.push(target);
      unordered_map<TreeNode*,bool> visited;
      visited[target]=true;
      int current_level=0;
      while(!q.empty())
      {
          
          int size=q.size();
         
          if(current_level++==k) break;
          for(int i=0;i<size;i++)
          {
              TreeNode*current=q.front();
               q.pop();
              if(current->left && !visited[current->left])
              {
                  visited[current->left]=true;
                  q.push(current->left);
              }
              if(current->right && !visited[current->right])
              {
                  visited[current->right]=true;
                  q.push(current->right);
              }
              if(m[current] && !visited[m[current]])
              {
                  visited[m[current]]=true;
                  q.push(m[current]);
              }
          }

      }
      while(!q.empty())
      {
          TreeNode* f=q.front();
      res.push_back(f->val);
      q.pop();
        
    }
    return res;
    }
};




    
