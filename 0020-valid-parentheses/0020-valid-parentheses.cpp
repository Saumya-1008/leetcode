class Solution {
public:
    bool isValid(string s) {
        int n= s.length();
        stack<char>st;
        //corner case 
        if(n==1 ||n==0){
            return false;
        }
        if(s[0]==')'|| s[0]=='}'|| s[0]==']'){
            return false;
        }
        for(int i=0;i< n;i++){
            if(st.empty())
            {
                if(s[i]==')'|| s[i]=='}'|| s[i]==']')
                    return false;
            }
            if(s[i]=='('|| s[i]=='{'|| s[i]=='['){
                //push
                
                st.push(s[i]);
            }
       else if(s[i]==')' && st.top()=='(')
           st.pop();
            else if(s[i]=='}' && st.top()=='{')
                st.pop();
            else if(s[i]==']' && st.top()=='[')
                st.pop();
            else 
                return false;
        }
        if(st.empty())
            return true;
        else 
            return false;
    }
};