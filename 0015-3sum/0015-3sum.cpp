class Solution {
public:
    //solution 1: using 3 loops. TC: O(n^3) and to avoid duplicate triplets store data in set
    
    //solution 2: use map to avoid the 3rd loop. TC: O(n)^2
   /* 
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> st;
        for(int i = 0;i<n;i++){
            set<int> hashset;
            for(int j = i+1;j<n;j++){
                int third = -(nums[i]+nums[j]);
                //if third is available in the hashset
                if(hashset.find(third) != hashset.end()){
                    vector<int> temp = {nums[i],nums[j],third};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[j]);
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
    
    */
    
    
    /*
    //solution 3: avoiding extra space
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<n;i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum<0){
                    j++;
                }
                else if(sum>0){
                    k--;
                }
                else{
                    vector<int> temp = {nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
    */
    
    //solution 3 and 2 got TLE
    //solution 4 with no TLE
    //using 2 pointer approach
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target = 0;
        sort(nums.begin(),nums.end());
        set<vector<int>> s;
        vector<vector<int>> output;
        
        for(int i = 0;i<nums.size();i++){
            int j = i+1;
            int k = nums.size()-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == target){
                    s.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if(sum < target){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        
        for(auto it: s){
            output.push_back(it);
        }
        
        return output;
    }
    
};