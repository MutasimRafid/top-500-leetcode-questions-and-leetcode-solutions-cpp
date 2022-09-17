/* This question is exactly similar to  subset 2. 
The only difference is that we have duplicates inside the given vector arr[]
We need to skip the duplicate elements. Else they would generate Duplicate Combinations which we don't want
To skip the Duplicate Elements, we will sort arr[] and use a While Loop to skip all the Duplicate Elements
Also we need to keep track about sum that needs to be equal to target
*/

class Solution {
private:
   void solve(int i, vector<int> &arr, vector<int> &output, vector<vector<int>> &ans, int sum, int n, int target){
        //base case
        // If sum is equal to target, we have reached a Valid Combination
        if(sum == target){
            ans.push_back(output);
            return;
        }
        
           // If at any moment, sum becomes greater than target, we don't need to proceed further
        if(sum > target) return;
        
        // If we reach the end of arr[], we cannot go any further so we return back
        if(i == n) return;
        
        //include
        output.push_back(arr[i]);
        sum += arr[i];
        solve(i+1,arr,output,ans,sum,n,target); //recursive call
        output.pop_back(); //backtracking
        sum -= arr[i];
        
        // Use the While Loop to skip all the duplicate occurrences of i-th Element
        while(i+1 < arr.size() && arr[i] == arr[i+1]) i++;
        
        //exclude
        solve(i+1,arr,output,ans,sum,n,target); //recursive call
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> output;
        vector<vector<int>> ans;
        int sum = 0;
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        
        solve(0,candidates,output,ans,sum,n,target);
        return ans;
    }
};