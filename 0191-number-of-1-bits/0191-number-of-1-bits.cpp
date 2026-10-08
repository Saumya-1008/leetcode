class Solution {
public:
    int hammingWeight(int n) {
        if(n==1)
        return 1;
      long long int c=0;
        while(n>0){
            n&=n-1;
            n>>1;
            c++;
        }
        return c;
    }
};