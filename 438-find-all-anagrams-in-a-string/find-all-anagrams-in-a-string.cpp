class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int p_num=p.size();
        int s_num=s.size();
        if(p_num>s_num) return {};
        map<char,int> mpp,mpp1;
        vector<int> result;
        for(char c='a';c<='z';c++)
        {
            mpp[c]=0;
            mpp1[c]=0;
        }
        for(int i=0;i<p.size();i++){
            mpp1[p[i]]++;
        }
        for(int i=0;i<p.size();i++){
            mpp[s[i]]++;
        }
        bool ans1=true;
        for(char c='a';c<='z';c++)
        {
            if(mpp[c]!=mpp1[c]) ans1=false; 
        }
        if(ans1) result.push_back(0);
        for(int j=p_num;j<s.size();j++){
            mpp[s[j-p_num]]--;
            mpp[s[j]]++;
            bool ans=true;
            for(char c='a';c<='z';c++){
                if(mpp[c]!=mpp1[c]) {
                    ans=false;
                    break;
                } ;
            }
            if(ans) result.push_back(j-p_num+1);

        }
        return result;
    }
};