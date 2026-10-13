class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        int c;
        int p;
        for(int i=0;i<=n;i++){
            c=0;
            p=i;
            while(p>0){
              p&=(p-1);
              c++;
            }
            ans.push_back(c);
        }
        return ans;
    }
};