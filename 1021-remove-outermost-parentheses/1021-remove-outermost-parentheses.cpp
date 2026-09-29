class Solution {
public:
    string removeOuterParentheses(string S) {
        string ans;
        int opened = 0;

        for(int i = 0; i < S.size(); i++) {

            if(S[i] == '(') {
                // Keep '(' only if it is not the outermost one
                if(opened > 0)
                    ans += S[i];

                opened++;
            }

            if(S[i] == ')') {
                opened--;

                // Keep ')' only if it is not the outermost one
                if(opened > 0)
                    ans += S[i];
            }
        }

        return ans;
    }
};