#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    
    bool canAchieve(const vector<int>& nums, int mid, int maxOperations) {
       long long int operations = 0;
        for (int num : nums) {
            if (num > mid) {
             operations += (num-1)/mid;
            }
        }
       
        return operations <= maxOperations;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;

        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (canAchieve(nums, mid, maxOperations)) {
                ans = mid;       
                high = mid - 1;  
            } else {
                low = mid + 1; 
            }
        }
        
        return ans;
    }
};