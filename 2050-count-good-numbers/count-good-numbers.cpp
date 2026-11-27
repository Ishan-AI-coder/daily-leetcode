class Solution {
public:
    long long mod=1000000007;
    long long findpower(long long a,long long b){
        if(b==0) return 1;
        long long half=findpower(a,b/2);
        long long result=(half*half)%mod;
        if(b%2==1){
            result=(result*a)%mod;
        }
        return result%mod;
    }
    int countGoodNumbers(long long n) {
        // Your code goes here
        long long even_pos_num=(n+1)/2;
        long long odd_pos_num=n-even_pos_num;
        long long ans=even_pos_num*5+ odd_pos_num*4;
        return (findpower(5,even_pos_num)*findpower(4,odd_pos_num))%mod;
    }
};
