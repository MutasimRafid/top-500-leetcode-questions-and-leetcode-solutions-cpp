class Solution {
    private:
    void solve(string digit, string output, int index, vector<string>& ans, string mapping[]){
        //base case
        if(index >= digit.length()){
            ans.push_back(output);
            return;
        }
        
        int num = digit[index] - '0';
        string value = mapping[num]; //2 = 'ábc'
        
        for(int i = 0;i<value.length();i++){
            output.push_back(value[i]);
            
            //recursive call
            solve(digit,output,index+1,ans,mapping);
            //backtracking
            output.pop_back();
        }
    }
    
    
    public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        
        //corner case
        if(digits.length() == 0){
            return ans;
        }
        
        int index = 0;
        string output = "";
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl","mno","pqrs","tuv","wxyz"};
       
        solve(digits,output,index,ans,mapping);
        return ans;
    }
};