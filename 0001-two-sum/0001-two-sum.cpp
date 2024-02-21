class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Approach 1: Nested loop. TC: O(n^2)
        //Approach 2: Use sorting and 2 pointer. TC: O(nlogn)
        // Approach 3: Use map/hashmap. TC: O(logn)
        
        vector<int> ans;
        map<int,int> mp;
        
        for(int i = 0;i<nums.size();i++){
            //if element is present in the hashmap
            if(mp.find(target-nums[i]) != mp.end()){
                ans.push_back(mp[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
            mp[nums[i]] = i;
            
        }
        return ans;
    }
};