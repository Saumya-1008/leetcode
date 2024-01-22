class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

     int n=nums.size();
     int sum=(n*(n+1))/2,x=0,y=0;
     
// if ther will be any duplicate than it will store in x.
     for(int i=0;i<n;i++)
     {  
         if(nums[abs(nums[i])-1]<0 && x==0)
         {
             x=abs(nums[i]);
         }
        nums[abs(nums[i])-1]=-1*nums[abs(nums[i])-1];
     } 

     for(int i=0;i<n;i++)
     {
         
         sum-=abs(nums[i]);
        
     }
     cout<<sum<<"x"<<x;
     y=sum+x;
     return {x,y};
    }
};