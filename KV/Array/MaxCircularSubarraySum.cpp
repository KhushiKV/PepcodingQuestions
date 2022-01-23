//https://leetcode.com/problems/maximum-sum-circular-subarray/submissions/

class Solution {
public:
    
    int kadane(vector<int> &nums){
        int tmp = nums[0], ans = nums[0];
        for(int i=1;i<nums.size();i++){
            tmp = max(tmp+nums[i],nums[i]);
            ans = max(ans,tmp);
        }
        return ans;
    }
    
    
    int maxSubarraySumCircular(vector<int>& nums) {
    int n=nums.size();

    //kadane's algo for the max subarray sum for straight array
    int maxsubstraight=kadane(nums);//candidate 1
        
    //when all elements are negative
    if(maxsubstraight<0){
        return maxsubstraight;
    }

    //calculating total sum of original array and
    //invert the array now
    int tot = 0;
    for(int i=0;i<n;i++){
        tot += nums[i];
        nums[i]=0-nums[i];
    }
        
    //now calculate minimum subarray sum for the original array == -1 * max subarray sum for the             inverted array, so kadane on inverted array
    int maxsubinv = kadane(nums); //calculating for candidate 2
        
    int minsubstraight = 0-maxsubinv;
    int couldbemaxsub = tot - minsubstraight; //candidate 2
            
        
    //final will be the ((maximum)) of (straight max subarray sum) and (total - min straight subarray         sum) 
    int maxsubcircular = max(maxsubstraight,couldbemaxsub);
        
    return maxsubcircular;
    }
};
