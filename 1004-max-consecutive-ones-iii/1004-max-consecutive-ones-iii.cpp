class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int zerosCount = 0;
        int maxLength = 0;
        
        while (right < nums.size()) {
            // Expand the window by including nums[right]
            if (nums[right] == 0) {
                zerosCount++;
            }
            
            // If window is invalid, shrink it from the left
            while (zerosCount > k) {
                if (nums[left] == 0) {
                    zerosCount--;
                }
                left++;
            }
            
            // Calculate the valid window size
            maxLength = max(maxLength, right - left + 1);
            
            right++;
        }
        
        return maxLength;
    }
};