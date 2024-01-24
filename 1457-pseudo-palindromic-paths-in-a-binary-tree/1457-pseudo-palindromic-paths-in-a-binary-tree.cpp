/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

    class Solution {
public:
    bool checker(vector<int>&freq){
        int cnt = 0 ;

        for(int i = 0 ; i < freq.size() ; i++){
            if (freq[i]%2 != 0)cnt++;

            if (cnt>1)return false;
        }
        return true;
    }   

    void helper(TreeNode* root,vector<int>&freq,int &cnt){
        if (!root)return;

        if(!root->left and !root->right){
            freq[root->val]++;
            if (checker(freq)){
                cnt++;
            }
            freq[root->val]--;
            return;
        }

        freq[root->val]++;
        helper(root->left,freq,cnt);
        helper(root->right,freq,cnt);
        freq[root->val]--;
        return;
    }
        int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> freq(10,0);
        int cnt =0;
        helper(root,freq,cnt);
        return cnt;
    }

        
};
