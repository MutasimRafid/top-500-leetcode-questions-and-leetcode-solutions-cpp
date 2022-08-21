class Solution {
public:
    bool isPalindrome(string s){
        int l = 0;
        int r = s.size() - 1;
        
        while(l < r){
            if(s[l++] != s[r--]){
                return false;
            }
        }
        return true;
    }
    
    void solve(string s, vector<vector<string>> &ans, vector<string> &temp){
        //base case
        if(s.size() == 0){
            ans.push_back(temp);
        }
        
        
        //help loop for recursive call
        for(int i = 0; i < s.size();i++){
            string leftPar = s.substr(0,i+1);
            if(isPalindrome(leftPar)){
                temp.push_back(leftPar);
                //recursive call
                solve(s.substr(i+1),ans,temp);
                temp.pop_back();
            }
        }
    }
    
    
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        
        solve(s,ans,temp);
        return ans;
    }
};