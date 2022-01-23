//https://leetcode.com/problems/sort-colors/

class Solution {
public:
    void sortColors(vector<int>& v) {
        int n=v.size();
        int low=0,high=n-1,mid=0;
        while(mid<=high)
        {
            if(v[mid]==0)
            {
                swap(v[low],v[mid]);
                low++;
                mid++;
            }
            else if(v[mid]==1)
            {
                mid++;
            }
            else
            {
                swap(v[mid],v[high]);
                high--;
            }
        }
    }
};
