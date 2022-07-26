                cout<<"mid"<<mid;
                return mid;
            }
            if(nums[mid]>target)
            {
              return  b_s(nums,s,mid-1,target);
            }
            else  return  b_s(nums,mid+1,e,target);
        }
        
        
       return -1;
    }
    
    int search(vector<int>& nums, int target) {
        if(nums.size()==0)
        {
            return -1;
        }
        if(nums.size()==1 && target==nums[0])
        {
            return 0;
        }
   //finding index from where array is rotated in k
        int k=binary(nums,0,nums.size()-1);
        
        cout<<k;
        //applying binary search o both sorted piece of array with t5he help of k
        int a1=b_s(nums,k,nums.size()-1,target);
        int a2=b_s(nums,0,k-1,target);
        cout<<a1<<" "<<a2;
        if(a1!=-1)
            return a1;
          if(a2!=-1)
            return a2;
        
        return -1;
    }
};
