class Solution {
private:
    void solve(int i, vector<int>& output, vector<vector<int>>& ans, vector<int>& nums){
        //base case
        if(i == nums.size()){
            ans.push_back(output);
            return;
        }
        
        //include
        output.push_back(nums[i]);
        //recursive call
        solve(i+1,output,ans,nums);
        //backtracking
        output.pop_back();
        
        
        //stop same element in ans like: [[1,2,2],[1,2,2]]
        //you will take [1,2,2] only once
        //to avoid duplicate element in ans, while excluding will avoid same digit.
        //
        //test case: 1,2,2 ...here will avoid the 1st 2 which is at i = 1, 
        //there will be no exclude recursion call for i = 2, i will be 3
        //see note khata for better explanation
        while(i<nums.size() - 1 && nums[i] == (nums[i+1]) ){
            i++;
        }
        
        
        //exclude
        solve(i+1,output,ans,nums);
        
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> output;
        
        solve(0,output,ans,nums);
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};