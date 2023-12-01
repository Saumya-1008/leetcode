class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
		// Declare answer variable
        int ans = 0;
		
		// constantly check every interval if it contains queryTime
        for (int i = 0; i < startTime.size(); i++)
            if (startTime[i] <= queryTime && endTime[i] >= queryTime)
                ans++;
        return ans;
    }
};