class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int req_time=requests[0];
        for(int i=0;i<requests.size()-1;i++)
        {
            req_time+=(abs(requests[i+1]-requests[i]));
        }
        return req_time;

    }
};