class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
       long long int l=0,r=0;
        int n=nums.size();
        int o=0;
        int t_c=0;
       long long int c=0;
        while(r<n){
           //check odd
           if(nums[r]%2 ==1){
            o++;
            c=0;
           } 
           //r++;
           while(o==k){
            c++;
            if(nums[l]%2 ==1){
            o--;
           } 
            
            l++;
           }
           t_c+=c;
           r++;
        }
        return t_c;
    }
};