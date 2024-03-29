static unordered_set<string> operation({"+","-","*","/"});

class Solution {
public:
    //approach: using stack
    // TC: O(n).... SC:O(n)
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for(auto it: tokens){
            if(operation.find(it) == operation.end()){ //it's an integer(not operator as not found in operation)
                st.push(stoi(it));
            }
            else{
                int b = st.top();
                st.pop();
                
                int a = st.top();
                st.pop();
                
                if(it == "+") st.push(a+b);
                else if(it == "-") st.push(a-b);
                else if(it == "*") st.push(a*b);
                else{
                    st.push(a/b);
                }
            }
        }
        return st.top();
    }
};