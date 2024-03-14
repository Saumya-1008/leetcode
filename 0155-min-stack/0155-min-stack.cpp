class MinStack {
public:
    vector<pair<int ,int>>st;
    MinStack() {
        
    }
    
    void push(int val) {
        pair<int,int>p;
        if(st.empty()){
            pair<int,int>p;
            p.first=val;
            p.second=val;
            st.push_back(p);
        }
        else{
            pair<int,int>p;
            p.first=val;
            int oldmin=st.back().second;
            p.second=min(oldmin,val);
            st.push_back(p);
        }
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        pair<int,int> rme=st.back();
        return rme.first;
    }
    
    int getMin() {
        pair<int,int> rme=st.back();
        return rme.second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */