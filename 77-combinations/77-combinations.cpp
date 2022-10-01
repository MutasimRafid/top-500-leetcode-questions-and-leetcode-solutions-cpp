/* Generating Combinations is exactly similar to generating Subsets.
At every stage we will - a) Pick i-th Element  
                         b) Don't Pick i-th Element
Instead of giving us an array or vector, we are asked to generate all Combinations from 1 to N (both inclsive) and length of each Subset should be exactly K
We use the same Pick & Don't Pick Logic to solve the Question
We should always remember - Relative order matters in Combination just like Subsets
*/
/*
Time Complexity  : O(2^N)
Space Complexity : O(N)
*/

class Solution {
private:
    void solve(int i,int n, int k, vector<int>& output, vector<vector<int>>& ans){
        //base case
        if(k == 0){
            ans.push_back(output);
            return;
        }
        
        if(i>n) return;
        
        // If we don't have enough elements to make our subset, we shouldn't proceed further
        //this base case is for optimization only, not mandatory
        if(k > n-i+1) return; //optimization
        
        
        //include
        output.push_back(i);
        //recursive call
        solve(i+1,n,k-1,output,ans);
        //backtrack
        output.pop_back();
        
        //exclude
        solve(i+1,n,k,output,ans);
        
    }
    
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> output;
        
        ////we are passing 1 to avoid zero, as because in question it is stated that range 1 to n
        solve(1,n,k,output,ans);
        return ans;
    }
};