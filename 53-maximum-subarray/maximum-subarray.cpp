class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size=nums.size();int sum=0,max_subarray_sum=0;
        bool all_neg=true;
        int max_el=INT_MIN;
        for(int i=0;i<size;i++)
        {
            sum+=nums[i];
            if(sum<0) sum=0;
            max_subarray_sum=max(max_subarray_sum,sum);
            if(nums[i]>=0) all_neg=false;
            max_el=max(max_el,nums[i]);
        }
        if(all_neg)
        {
            return max_el;
        }
        else
        {
            return max_subarray_sum;
        }

    }
};