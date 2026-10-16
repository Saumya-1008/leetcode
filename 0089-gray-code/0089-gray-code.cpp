class Solution {
public:
    vector<int> grayCode(int n) {
        
        int num = 1 << n;
        vector<int> ans;
        for (int i = 0; i <num; ++i)
        {
            ans.push_back(i ^ (i >> 1));
        }

        // Return the generated sequence
        return ans;
    }
};