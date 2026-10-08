class Solution {
public:
int countone(int n){
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
    int minBitFlips(int start, int goal) {
        int dummy= start ^ goal;
        cout<<dummy;
       int k= countone(dummy);
       return k;
    }
};