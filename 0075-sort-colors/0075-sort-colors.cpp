class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0,j=0,k=0;
        int n=nums.size();
        vector<int> num;
        while(k<n){
            if(nums[k]== 1){
                    //swap(nums[k],nums[j]);
                    j++; }
                     if(nums[k]== 0){
                        // swap(nums[k],nums[i]);
                   i++;
                   }
                    k++;
        }

        for(int s=0;s<i;s++){
num.push_back(0);
        }
    
      for(int s=i; s<i+j; s++){
num.push_back(1);
        }
        for(int s=i+j;s<n;s++){
num.push_back(2);
        }
       // vector<int> nums = num;
       nums.assign(num.begin(),num.end());
    }
};