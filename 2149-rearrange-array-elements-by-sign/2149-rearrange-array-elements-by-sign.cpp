class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> pa;
         vector<int> na;
         vector<int> r;
        for(int i=0;i<n;i++){
            if(nums[i]>0)
            pa.push_back(nums[i]);
             else if(nums[i]<0)
            na.push_back(nums[i]);
        }
        int j=0,k=0;
        for(int i=0;i<n;i++){
            
            if(i%2 ==0){
            r.push_back(pa[j]);
            j++;
            }
             else {
            r.push_back(na[k]);
            k++;
             }
        }
        nums.assign(r.begin(),r.end());
        return nums;

    }
};