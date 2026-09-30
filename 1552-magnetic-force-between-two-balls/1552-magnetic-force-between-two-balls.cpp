class Solution {
public:
    bool ispossible(vector<int>& position, int mid, int m) {
        int ball_pos = position[0];
        int count = 1; 
        
        for(int i = 1; i < position.size(); i++) {
            
            if(position[i] - ball_pos >= mid) {
                ball_pos = position[i];
                count++;
                if(count == m) return true; 
            }
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        
    
        int low = 1; 
        
        int high = position[n - 1] - position[0]; 
        int ans = 0;
        
        while(low <= high) {
            
            int mid = low + (high - low) / 2; 
            
            if(ispossible(position, mid, m)) {
                ans = mid;     
                low = mid + 1;  
            } else {
                high = mid - 1; 
            }
        }
        return ans;
    }
};