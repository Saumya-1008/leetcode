class Solution {
public:
    string removeDuplicates(string s) {
        string ans ="";
        int in=0;
        while(in < s.length()){
            if(ans.length()>0 && ans[ans.length()-1]==s[in]){
             ans.pop_back();
            }
            else{
                ans.push_back(s[in]);
            }
            in++;
        }
        return ans;
    }
};