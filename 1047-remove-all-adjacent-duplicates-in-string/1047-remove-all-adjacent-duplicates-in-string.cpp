class Solution {
public:
    string removeDuplicates(string s) {
      stack<char>st;
        int l=s.length();
        int i=0;
        
        while(i<l){
            if(!st.empty() && st.top()==s[i]){
                
                                st.pop();
            }
            else 
                st.push(s[i]);

            i++;
        }
        //stack to string 
         string a;
        while(!st.empty()){
           char temp=st.top();
            a+=temp;
            st.pop();
        }
        reverse(a.begin(),a.end());
        return a;
    }
};