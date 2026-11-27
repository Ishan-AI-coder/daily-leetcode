class Solution {
public:
    void f(vector<int>& nums,int idx,vector<int> &list,vector<vector<int>> &ans){
        if(idx==nums.size()){
            ans.push_back(list);
            return;
        }
        // Don't take the element
        f(nums,idx+1,list,ans);
        // Take the element
        list.push_back(nums[idx]);
        f(nums,idx+1,list,ans);
        list.pop_back();
    }
    vector<vector<int> > subsets(vector<int>& nums) {
        //your code goes here
        vector<vector<int>> ans;
        vector<int> list;
        f(nums,0,list,ans);
        return ans;
    }
};