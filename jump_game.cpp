class Solution {
public:
    bool canJump(vector<int>& nums) {
        int step=nums.size()-1;
        int n=nums.size();
        for(int i=n-1;i>=0;i--)
        {
           if(i+nums[i]>=step)
               step=i;
                
        }
        return step==0;
        
    }
};
