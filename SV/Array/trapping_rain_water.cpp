//https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& v) {
        int l,r,lm,rm,ans=0;
        l=lm=rm=0;
        r=v.size()-1;
        while(l<r)
        {
            if(v[l]<=v[r])
            {
                if(v[l]>=lm)
                    lm=v[l];
                else
                    ans+=lm-v[l];
                l++;
            }
            else
            {
                if(v[r]>=rm)
                    rm=v[r];
                else
                    ans+=rm-v[r];
                r--;
            }
        }
        return ans;
    }
};
