class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(int i = 0;i<s.length();i++){
            char ch = s[i];
            
            
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            else{
                if(!st.empty()){
                    char top = st.top();
                    if(ch == ')' && top == '(' || ch == '}' && top == '{' || ch == ']' && top == '['){
                        st.pop();
                    }
                    else{
                        return false; //the string is not balanced
                    }
                }
                else{
                    return false; //the stack is empty and we don't find a closing bracket 
                }
            }
        }
        
        if(st.empty()) return true;
        else return false;
    }
};