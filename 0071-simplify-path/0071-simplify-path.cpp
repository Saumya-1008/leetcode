class Solution {
public:
    void solve(stack<string>&st ,string &ans){
        if(st.empty())
            return;
        string adans =st.top();
        st.pop();
        solve(st,ans);
        ans+=adans;
    }
    string simplifyPath(string path) {
        stack<string> st;
        int i=0;
        while(i<path.length()){
            int start =i;
            int end =i+1;
            while(end<path.length() && path[end]!='/')
                end++;
            i=end;
            string minpath =path.substr(start,end -start);
            if(minpath == "/" || minpath =="/.")
                continue;
            if(minpath!="/.."){
                st.push(minpath);
            }
            else if(!st.empty())
                st.pop();
            
        }
    string ans= st.empty()? "/": "";
        solve(st,ans);
        return ans;
    }
    
};