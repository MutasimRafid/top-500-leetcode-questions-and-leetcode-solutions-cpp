class Solution {
public:
    void solve(vector<string> &v, int n, int oc, int cc, string s){
        //TC: 2^n
        
        //base case
        if(oc == n && cc == n){
            v.push_back(s);
            return;
        }
        
        if(oc<n){
           solve(v,n,oc+1,cc,s+"("); 
        }
        if(cc<oc){
            solve(v,n,oc,cc+1,s+")");
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        int oc = 0,cc = 0;
        solve(v,n,oc,cc,"");
        return v;
    }
};