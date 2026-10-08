class Solution {
public:
   
    bool isPowerOfTwo(int n) {
      //  int x=1;
   long long int c=0;
   int p=n;
   if(n<0)
   return false;
       if(n==0)
       return false;
       if(n==1)
       return true;
      while(p!=1){
         if(p%2 == 1 && p!= 1)
       return false;
             p/=2;
           c++;
      }
    
      return true;
    }
};