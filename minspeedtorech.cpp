#using binary search
class Solution {
public:
    bool is_pos(double speed,vector<int>&dist,double hour)
    {
        double ans=0;
        for(int i=0;i<dist.size();i++)
        {
            double cal=dist[i]*1.0/speed;
            if(i!=dist.size()-1)
            {
                ans=ans+ceil(cal);
            }
            else ans+=cal;
             if(ans>hour) return false;
        }
           
            
            if(ans<=hour) return true;
            return false;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int i=1;
        int j=1e7;
        int min_s=-1;
        while(i<=j)
        {
            int mid=i+(j-i)/2;
            if(is_pos(mid,dist,hour))
               {
                   min_s=mid;
                   j=mid-1;
               }
            else i=mid+1;
        }
        return min_s;
    }
};
/* double ans=0;
        for(int i=0;i<dist.size();i++){
            double d=dist[i]*1.0/speed;
            if(i!=dist.size()-1)
            ans=ans+ceil(d);
            else
            ans+=d;
            if(ans>hour)
            return false;
        }
       if(ans<=hour)
       return true;
       return false;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int i=1;
        int j=1e7;
        int minspeed=-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(ispossible(dist,mid,hour)){
               minspeed=mid;
               j=mid-1;
            }
            else
            i=mid+1;
        }
        return minspeed;
    }
};*/
