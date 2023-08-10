class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0;
        int n=nums.size();
        int r=n-1;
        while(l<=r)
        {
           int mid=l+(r-l)/2;
            cout<<nums[mid];
            if(nums[mid]==target)
            {
                return true;
            }
            else if(nums[mid]==nums[l] && nums[mid]==nums[r])
            {
                l++;
                r--;
            }
            else if(nums[mid]>=nums[l])
            {
                if(target<nums[mid] && nums[l]<=target)
                {
                    r=mid-1;
                }
                else l=mid+1;
            }
           else if(nums[mid]<=nums[r])
           {
               if(target>nums[mid] && target<=nums[r])
               {
                   l=mid+1;
               }
               else r=mid-1;
           }
        }
        return false;
    }
};

