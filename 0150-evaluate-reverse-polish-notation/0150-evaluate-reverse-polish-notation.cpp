static unordered_set<string> operation({"+", "-", "*", "/"});

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for(auto it: tokens){
            if(operation.find(it) == operation.end()){
                st.push(stoi(it));
            }
            else{
                int b = st.top();
                st.pop();
                
                int a = st.top();
                st.pop();
                
                if(it== "+") st.push(a+b);
                else if(it== "-") st.push(a-b);
                else if(it == "*") st.push(a*b);
                else st.push(a/b);
            }
        }
        return st.top();
    }
};