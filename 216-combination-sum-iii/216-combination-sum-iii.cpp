/* This question is the continuation of Combination Sum 1 & 2
The only difference is that, instead of giving us an array / vector,
We are asked to print all possible combinations using numbers 1 to 9 (both inclusive)
*/
//We need to use exclude recursion part because ans:[1,2,4] comes from exclude part in the recursion tree. (watch khata)

class Solution {
private: 
    void solve(int i,int k, int n, vector<int>& output, vector<vector<int>>& ans, int sumNow){
        //Base case
        //----------------
        // If the Sum-Till-Now becomes greater than n, we don't need to proceed further
        if(sumNow > n) return;
        
        // If k becomes equal to zero(0) , we need to check if the SumNow is equal to n or not
        if(k == 0){
            if(sumNow == n){
                ans.push_back(output);
            }
             // Else we simply return without including the output
            return;
        }
        
        // If i becomes equal to 10, we don't need to proceed any further
        if(i == 10) return;
        
        //---------------------------
        
        //include
        sumNow += i;
        output.push_back(i);
        //recursive call
        solve(i+1,k-1,n,output,ans,sumNow);
        //backtrack
        sumNow -= i;
        output.pop_back();
        
        
        //exclude
        solve(i+1,k,n,output,ans,sumNow);
        
    }
    
public:  
    vector<vector<int>> combinationSum3(int k, int n) {
      vector<int> output;
        vector<vector<int>> ans;
        int sumNow = 0;
        int i = 1;
        
        solve(i,k,n,output,ans,sumNow);
        return ans;
    }
};