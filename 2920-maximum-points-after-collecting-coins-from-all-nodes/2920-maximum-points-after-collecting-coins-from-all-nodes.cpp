class Solution {
public:
 int vis[100001] = {};
    int dfs(int i, int p, vector<vector<int>> &G, vector<int>& A, int k, int v) {
        if (v > 13) return 0;
        if (vis[i] > v) return 0;
        int op1 = (A[i] >> v) - k, op2 = A[i] >> v + 1;
        vis[i]++;
        for (int j : G[i])
            if (j != p) {
                op1 += dfs(j, i, G, A, k, v);
                op2 += dfs(j, i, G, A, k, v + 1);
            }
        return max(op1, op2);
    }
    int maximumPoints(vector<vector<int>>& edges, vector<int>& A, int k) {
        vector<vector<int>> G(edges.size() + 1);
        for (auto &e : edges) {
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
        }
        return dfs(0, -1, G, A, k, 0);
    }
};