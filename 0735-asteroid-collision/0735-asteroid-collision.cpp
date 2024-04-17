class Solution {
public:
    void buildans(stack<int>&st,vector<int>&ans){
        if(st.empty())
            return;
        int temp=st.top();
        st.pop();
        buildans(st,ans);
        ans.push_back(temp);
    }
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        
     for(auto ast:asteroids){
         bool destroy =false;
        if(ast>0){
            st.push(ast);
        }
        else{
            if(st.empty()||st.top()<0)
                st.push(ast);
            else{
                while(!st.empty()&& st.top()>0){
               if(abs(ast)==abs(st.top())){
                   destroy =true;
                   st.pop();
               break;}
               else if(abs(ast)>abs(st.top())){
                   
                      st.pop();
                      }
                    else{
                        destroy=true;
                        break;}
           }
               if(!destroy)
                   st.push(ast);
            }
           
            
    }
     }
        vector<int> ans;
        buildans(st,ans);
        return ans;
    }
};