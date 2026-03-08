class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int max=INT_MIN,sum=0,r;
     //  if(nums)
        for(int i=0;i<nums.size();i++){
            r=sum+nums[i];
             if(r>max)
            max=r;
            if(r>0)
            sum=r;
            else
            sum=0;
          //  if(sum>max)
           // max=sum;
        }
        return max;
    }
};