class Solution {
private:
    void solve(int i, vector<int>& output, vector<int>& nums, vector<vector<int>>& ans){
        //base case
        if(i == nums.size()){
            ans.push_back(output);
            return;
        }
        
        
        //include
        output.push_back(nums[i]);
        //recursive call]
        solve(i+1,output,nums,ans);
        //backtracking
        output.pop_back();
        
        //stop same element in ans like: [[1,2,2],[1,2,2]]
        //you will take [1,2,2] only once
        while(i<nums.size() - 1 && nums[i] == (nums[i+1]) ){
            i++;
        }
        
        //exclude
        solve(i+1,output,nums,ans);
        
        return;
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> output;
        
        solve(0,output,nums,ans);
        
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};