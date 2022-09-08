class Solution {
private: 
    void solve(vector<int> nums, vector<vector<int>>& ans, int index){
        //base case
        if(index >= nums.size()){
            ans.push_back(nums);
            return;
        }
        
        //solve for 1 case, rest will be taken care of by Recursion
        for(int j = index; j < nums.size(); j++){
            swap(nums[index],nums[j]);
            //recursive call
            solve(nums,ans,index+1);
            //backtracking
            swap(nums[index],nums[j]);
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;
        solve(nums,ans,index);
        return ans;
    }
};