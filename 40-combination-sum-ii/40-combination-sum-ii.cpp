class Solution {
public:
    
    //TC: O(2^n * k)
    //SC: k * x
    
    void solve(int idx, int target, vector<int>& arr, vector<vector<int>> &ans, vector<int> &temp){
        
        //base case
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        
        for(int i = idx; i < arr.size(); i++){
            //idx = index of temp
            //after popping element(backtracking) index size will be zero
            //then next i will be > than idx 
            //so if
            //To avoid duplicate like: [[1,1,2], [1,1,2]]
            if(i > idx && arr[i] == arr[i-1]) continue;
            if(arr[i] > target) break;
            
            temp.push_back(arr[i]);
            //recursive call
            solve(i+1, target-arr[i],arr,ans,temp);
            //backtracking
            temp.pop_back();
        }
        
    }
    
    
    
    
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        
        vector<vector<int>> ans;
        vector<int> temp; 
        
        solve(0,target,arr,ans,temp);
        
        return ans;
    }
};