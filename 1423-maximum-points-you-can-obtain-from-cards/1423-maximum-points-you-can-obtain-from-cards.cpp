class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftSum = 0;
        int rightSum = 0;
        int maxSum = 0;
        
        // Step 1: Calculate the sum of the first k cards from the left
        for (int i = 0; i < k; i++) {
            leftSum += cardPoints[i];
        }
        
        maxSum = leftSum;
        int rightIndex = cardPoints.size() - 1;
        
        // Step 2: Slide the window
        // Remove from the left end and add from the right end
        for (int i = k - 1; i >= 0; i--) {
            leftSum -= cardPoints[i];
            rightSum += cardPoints[rightIndex];
            rightIndex--;
            
            maxSum = max(maxSum, leftSum + rightSum);
        }
        
        return maxSum;
    }
};