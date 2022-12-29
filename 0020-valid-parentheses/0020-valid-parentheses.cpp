class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(int i = 0;i<s.length();i++){
            char ch = s[i];
            
            // if opening bracket, stack push
            //if closing bracket, stack top check and pop
            
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            else{
                //for closing bracket
                if(!st.empty()){
                    char top = st.top();
                    //if(matches(top,ch))
                    if((ch == ')' && top == '(') || (ch == '}' && top == '{') ||
                      (ch == ']' && top == '[') ){
                        st.pop();
                    }
                    else{    //the brackets are not balanced
                        return false; 
                    }
                }
                
                else{   //stack is empty and we find a closing bracket in string
                    return false;
                }
            }
        }
        
        if(st.empty()) return true;
        else return false;
    }
};