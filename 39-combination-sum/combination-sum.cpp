// even better just two branches not three
class Solution {
public:
    void f(int idx,int sum,vector<int> list,vector<int>& candidates,int target,vector<vector<int>> &ans){
        if(sum>target) return;
        if(sum==target){
            ans.push_back(list);
            return;
        }
        if(idx==candidates.size()) return;
        // Take the element

        // Take the element and stay at the same index
        list.push_back(candidates[idx]);
        f(idx,sum+candidates[idx],list,candidates,target,ans);
        list.pop_back();
        
        // Donot take the element and move to the next index
        f(idx+1,sum,list,candidates,target,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //your code goes here
        vector<vector<int>> ans;
        vector<int> list;
        f(0,0,list,candidates,target,ans);
        return ans;

    }
};