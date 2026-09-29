class Solution {
public:
    int maxDepth(string s) {
        int brac=0;
        int maxi=INT_MIN;
            for (char c : s) {
                if(c=='('){
                 brac++;
                
                 }
                else if(c==')'){
                    brac--;

                }
                 if(brac>maxi)
                 maxi=brac;

            }
return maxi;
    }
};