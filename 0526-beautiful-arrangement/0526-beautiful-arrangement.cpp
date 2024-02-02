class Solution {
public:
    void counth(vector<int>&v,int& n,int& ans,int currnum){
        //base case
        if(currnum>n){
            ans++;
            return;
        }
        for(int i=1;i<=n;i++){
            if(v[i]==0 &&(currnum%i ==0 || i%currnum ==0)){
                v[i]=currnum;
                counth(v,n,ans,currnum+1);
                v[i]=0;
            }
                
        }
            
    }
    int countArrangement(int n) {
        int ans;
        vector<int> v(n+1);
        counth(v,n,ans,1);
        return ans;
    }
};