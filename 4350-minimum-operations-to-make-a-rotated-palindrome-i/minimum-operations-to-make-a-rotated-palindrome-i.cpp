class Solution {
public:

    string leftrotate(string s, int i)
    {
        int n = s.size();

        return s.substr(i, n-i) + s.substr(0,i);
    }

    int cost_min(string s1)
    {
        int opera = 0;

        int n = s1.size();

        for(int i = 0; i < n/2; i++)
        {
            if(s1[i] != s1[n-i-1])
            {
                int op1, op2;

                if(s1[i] > s1[n-i-1])
                {
                    op1 = s1[i] - s1[n-i-1];
                    op2 = 26 - op1;
                }
                else
                {
                    op1 = s1[n-i-1] - s1[i];
                    op2 = 26 - op1;
                }

                opera += min(op1, op2);
            }
        }

        return opera;
    }

    int minOperations(string s)
    {
        int n = s.size();

        int mincost = INT_MAX;

        for(int i = 0; i < n; i++)
        {
            string s1 = leftrotate(s, i);

            int cost = i + cost_min(s1);

            mincost = min(mincost, cost);
        }

        return mincost;
    }
};