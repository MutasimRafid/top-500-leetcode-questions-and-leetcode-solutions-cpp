class MinStack {
public:
    
    //Approach 1: use pairs inside a stack
    //TC: O(1).. O(2N)
    /*
    void push(int x) {
      int min;
      if (st.empty()) {
        min = x;
      } else {
        min = std::min(st.top().second, x);
      }
      st.push({x,min});
    }

  void pop() {
    st.pop();
  }

  int top() {
    return st.top().first;
  }

  int getMin() {
    return st.top().second;
  }
    */
    //Approach 2: using stack but using modified value
    //TC: O(1)... SC: O(N)
    stack <long long> st;
    long long mini;
    
    MinStack() {
        while(st.empty() == false) st.pop();
        mini = INT_MAX;
    }
    
    void push(int value) {
        long long val = value;
        if(st.empty()){
            mini = val;
            st.push(val);
        }
        else{
            if(val<mini){
                st.push(2*val*1LL-mini); //modified value
                mini = val;
            }
            else{
                st.push(val);
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long elem = st.top();
        st.pop();
        if(elem<mini){
            mini = 2*mini - elem; 
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        long long elem = st.top();
        if(elem<mini){
            return mini;
        }
        return elem;
    }
    
    int getMin() {
        return mini;
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