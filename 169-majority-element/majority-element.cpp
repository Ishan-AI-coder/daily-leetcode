class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=1,el=nums[0];
        for(int i=1;i<nums.size();i++)
        {
                if(nums[i]==el) cnt++;
                else
                {
                    if(cnt==0)
                    {
                        cnt=1;
                        el=nums[i];
                    }
                    else
                    {
                        cnt--;
                    }
                }
        }
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==el) count++;
        }
        if(count>nums.size()/2) return el;
        else return -1;
    }
};