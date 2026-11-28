class Solution {
public:
    void f(int idx,int sum,vector<int> list,vector<int>& candidates,int target,set<vector<int>> &st){
        if(sum>target) return;
        if(sum==target){
            st.insert(list);
            return;
        }
        if(idx==candidates.size()) return;
        // Take the element

        // Take the element and stay at the same index
        list.push_back(candidates[idx]);
        f(idx,sum+candidates[idx],list,candidates,target,st);
        list.pop_back();

        // Take the element and move to the next index
        list.push_back(candidates[idx]);
        f(idx+1,sum+candidates[idx],list,candidates,target,st);
        // Remove the element from the list
        list.pop_back();
        
        // Donot take the element and move to the next index
        f(idx+1,sum,list,candidates,target,st);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //your code goes here
        vector<vector<int>> ans;
        vector<int> list;
        set<vector<int>> st;
        f(0,0,list,candidates,target,st);
        for(auto it : st){
            ans.push_back(it);
        }
        return ans;

    }
};