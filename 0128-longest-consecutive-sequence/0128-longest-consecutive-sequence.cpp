class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        
        int n=nums.size();
        if(n==0)
        return 0;
        int maxi=1;
       int x,c=0;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        for(auto it:st){
           if(st.find(it-1)==st.end()){
              x=it;
              c=1;
              while(st.find(x+1)!=st.end()){
                x++;
                c++;

              }
            maxi=max(maxi,c);
           }
        }
        return maxi;
    }
};