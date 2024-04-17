class Solution {
public:
    
    vector<int> nextsmaller(vector<int>& heights){
        vector<int> ans1;
        stack<int> st;
        st.push(-1);
        for(int i=heights.size()-1;i>=0;i--){
            int curr=heights[i];
            while(st.top()!=-1 && heights[st.top()]>=curr)
                st.pop();
            ans1.push_back(st.top());
            st.push(i);
        }
        return ans1;
    }
     vector<int> prevsmaller(vector<int>& heights){
        vector<int> ans2;
        stack<int> st;
        st.push(-1);
        for(int i=0;i<heights.size();i++){
            int curr=heights[i];
            while(st.top()!=-1 && heights[st.top()]>=curr)
                st.pop();
            ans2.push_back(st.top());
            st.push(i);
        }
        return ans2;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int> next= nextsmaller(heights);
        vector<int> prev = prevsmaller(heights);
        vector<int> area;
         for(int i=0;i<heights.size();i++){
        if(next[i]==-1)
            next[i]=next.size();
            }
        reverse(next.begin(),next.end());
        for(int i=0;i<heights.size();i++){
            int w= next[i]-prev[i]-1;
            int a=w*heights[i];
            area.push_back(a);
            
            }
        int maxi=INT_MIN;
                for(int i=0;i<heights.size();i++){
            if(area[i]>maxi)
                maxi=area[i];
            }
        
        return maxi;
        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> v;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            vector<int>t;
            for(int j=0;j<m;j++){
                t.push_back(matrix[i][j] - '0');
            }
            v.push_back(t);
        }
        vector<int>rows;
        int area=largestRectangleArea(v[0]);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
            if(v[i][j]){
                v[i][j]+=v[i-1][j];
            }
            else{
               v[i][j]=0; 
            }
        }
            area =max(area,largestRectangleArea(v[i]));
        }
    return area;
    }
};