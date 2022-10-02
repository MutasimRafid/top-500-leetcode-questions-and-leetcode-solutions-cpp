/* 
Time Complexity:  O(Exponential) 
Space Complexity: O(TargetSum) {Recursive Stack Space}
*/

/* The idea of this question is to return all such combinations whose individual sum is equal to Target
We use the same logic as generating Combinations - only difference is that we calculate the sum of each subset every time.
We can use an element as many times as we want
Our given vector arr[] contains only Unique Subsets that's for sure
*/


class Solution {
public:
    void findCombination(int i, vector<int>& arr, int target, int sumNow, vector<int>& output, vector<vector<int>>& ans){
        //base case
        
        // If our sumTillNow is equal to target, we have reached a Valid Combination
        if(sumNow == target){
            ans.push_back(output);
            return;
        }
        
         // If our sumTillNow exceeds target, there's no point in proceeding further(optimization)
        if(sumNow > target) return;
        
         // If we have reached the end of arr[], we cannot go further as we don't have anymore elements
        if(i >= arr.size()) return;
        
        
        //exclude
         findCombination(i+1,arr,target,sumNow,output,ans);
        
        //include
        sumNow += arr[i];
        output.push_back(arr[i]);
        //won't update i because we can take one element unlimited times
        findCombination(i,arr,target,sumNow,output,ans);
        //backtracking
        sumNow -= arr[i];
        output.pop_back();
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        int sumNow = 0;
        sort(candidates.begin(),candidates.end());
        
        findCombination(0,candidates,target,sumNow,output,ans);
        
        return ans;
    }
};