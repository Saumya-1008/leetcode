bool compare(const vector<int>&v1,const vector<int>&v2)
{
    return v1[0] > v2[0];
}
class Solution {
public:
    void update(int s,int e,const int indx,const int val,int node,vector<int>&segtree)
    {
        if(s == e)
        {
            // there can be multiple values of index indx so we choose with the max value
            segtree[node] = max(segtree[node],val); 
            return;
        }
        int mid = (s+e)/2;
        if(indx <= mid) update(s,mid,indx,val,2*node+1,segtree);
        else update(mid+1,e,indx,val,2*node+2,segtree);
        segtree[node] = max(segtree[2*node+1],segtree[2*node+2]);
    }
    int query(int s,int e,const int l,const int r,int node,const vector<int>&segtree)
    {
        if(l > e or r < s) return -1;
        if(l <= s and e <= r) return segtree[node];
        int mid = (s+e)/2;
        int op1 = query(s,mid,l,r,2*node+1,segtree);
        int op2 = query(mid+1,e,l,r,2*node+2,segtree);
        return max(op1,op2);
    }
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums1.size();
        int m = queries.size();
        vector<pair<int,int>> v(n);
        // sort nums1 and nums2 according to x which is nums1
        for(int i = 0 ; i < n ; ++i)
            v[i] = {nums1[i],nums2[i]}; // (x,y)
        sort(v.begin(),v.end());
        // coordinate compression of y as y is upto 1e9 would make it difficult
        // to create a segment tree without it
        set<int> s;
        for(int &y : nums2)
            s.insert(y);
        for(auto &node : queries)
            s.insert(node[1]);
        map<int,int> cord;
        int tdx = 0;
        for(int x : s)
        {
            cord[x] = tdx;
            ++tdx;
        }
        vector<int> segtree(4*tdx,-1);
        //sorting queries according to decreasing values of x 
        for(int i = 0 ; i < m ; ++i)
            queries[i].push_back(i);
        sort(queries.begin(),queries.end(),compare);
        int indx = n-1;
        vector<int> ans(m,-1);
        for(auto &q : queries)
        {
            int x = q[0];
            int y = q[1];
            int i = q[2];
            while(indx >= 0 and v[indx].first >= x)
            {
                update(0,tdx-1,cord[v[indx].second],v[indx].first+v[indx].second,0,segtree);//(l,r,index,val,node,segtree)
                --indx;
            }
            int ret = query(0,tdx-1,cord[y],tdx-1,0,segtree);//(L,R,l,r)
            ans[i] = ret;
        }
        return ans;
    }
};