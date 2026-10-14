class Solution {
public:
   
    vector<int> grayCode(int n) {
        if(n==1)
        return {0,1};
        
        vector<int> t=grayCode(n-1);
        vector<int>ans;
        for(int i=0;i<(t.size());i++){
            ans.push_back(t[i]);
        }
        for(int i=t.size()-1;i>=0;i--){
             ans.push_back((1<<(n-1))+t[i]);
        }
        
        return ans;
        
    }
};