class Solution {
//we will use take/not take algo
private:
    void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>>& ans){
        //base case
        if(index >= nums.size()){
            ans.push_back(output);
            return;
        }
        
        //exclude
        solve(nums,output,index+1,ans); //recursive call
        
        
        //include
        int element = nums[index];
        output.push_back(element);
        solve(nums,output,index+1,ans); //recursive call
        //in the parameter of solve function, if we take ...vector<int> output.. the address 
        //then we need to pop back. backtrack. as we are using only 1 vector
        //but here i am not using address. so in each recursive call a new copy of a vector will be created
        //so i don't need to backtrack here
        //output.pop_back(); 
        
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        
        solve(nums,output,index,ans);
        return ans;
    }
};