class Solution {
public:
      
    int maxProfit(vector<int>& p) {
       int n= p.size(),mini=p[0],maxi=0;
       for(int i=1;i<n;i++){
     int cost=p[i]-mini;
maxi=max(cost,maxi);
mini=min(mini,p[i]);
       }
       return maxi;
    }
};