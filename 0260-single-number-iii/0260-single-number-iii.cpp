class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long int a=nums[0];
        int x1=0,x2=0;
        for(int i=1;i<nums.size();i++){
           a^=nums[i];
        }
       int r_m= (a&(a-1))^a;
      // cout<<r_m;
        for(int i=0;i<nums.size();i++){
        if((r_m & nums[i])==0)
          x1=x1^nums[i];
        else
          x2=x2^nums[i];

        }
        vector<int>ans ;
        ans.push_back(x1);
      ans.push_back(x2);
    return ans;

    }
};