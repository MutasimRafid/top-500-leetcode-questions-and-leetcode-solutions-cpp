class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(int i,vector<int>& arr, vector<int>& temp, int target){
        
        //base case
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        
        if(target < 0){
            return;
        }
        if(i == arr.size()){
            return;
        }
        
        
        //exclude
        solve(i+1,arr,temp,target);
        
        
        //include
        temp.push_back(arr[i]);
        solve(i,arr,temp,target-arr[i]);
        //backtracking
        temp.pop_back();
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
       //ans.clear();
        
        vector<int> temp;
        
        solve(0,arr,temp,target);
        
        return ans;
    }
};