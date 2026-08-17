class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int s=drones.size();
        int mini=INT_MAX,mini_idx=-1;
        for(int i=0;i<s;i++)
        {
            int dist=abs(drones[i][0]-target[0])+abs(drones[i][1]-target[1]);
            if(dist<=drones[i][2]) 
            {
                if(dist<mini)
                {
                    mini=min(mini,dist);
                    mini_idx=i;
                }
            }
        }
        return mini_idx;

    }
};