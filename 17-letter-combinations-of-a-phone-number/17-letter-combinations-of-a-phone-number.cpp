class Solution {
private:
    void solve(string digit, vector<string>& ans, string output, int index, string mapping[]){
        //base case
        if(index >= digit.length()){
            ans.push_back(output);
            return;
        }
        
        int number = digit[index] - '0';
        string value = mapping[number]; //2 = 'ábc'
        
        for(int i = 0;i<value.length();i++){
            output.push_back(value[i]);
            //recursive call
            solve(digit,ans,output,index+1,mapping);
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
        
        string output;
        int index = 0;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,ans,output,index,mapping);
        return ans;
    }
};