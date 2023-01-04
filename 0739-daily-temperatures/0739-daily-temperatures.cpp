class Solution {
public:
    //like next greater element
    //can be done with nested loop O(n)^2
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n); //by default vector is initialized with zero
        stack<int> st;
        
        for(int i = 0;i<n;i++){
            //if current element is not next greater element, then insert into stack
            //if current element is next greater element, 
            //ans[st.top()] = i-st.top()
            //then pop() from stack
            while(st.size() > 0 && temperatures[i] > temperatures[st.top()]){
                ans[st.top()] = i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};