class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int>st;
        vector<int> ans;
        int res;
        st.push(-1);
        for(int i=prices.size()-1;i>=0;i--){
            int curr=prices[i];
            while(st.top()>curr){
                st.pop();
                
            }
            if(st.top()==-1){
                ans.push_back(curr);
            }
            else{
                res=curr-st.top();
                ans.push_back(res);
            }
            st.push(curr);
        }
    reverse(ans.begin(),ans.end());
        return ans;
    }
};