class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         /*
        //Approach 1: Brute force
        //using nested loop
        //TC: 0(n^2)... SC:O(n)
        vector<int> v;
        int n = nums.size();
        for(int i = 0;i<n-1;i++){
            for(int j = i+1;j<n;j++){
              if(nums[i]+nums[j] == target){
                v.push_back(i);
                v.push_back(j);
              } 
           }
        }
        
        return v;
        */
        //-----------------------------------------------------------
        //Approach 2: Using hashing (Most efficient)
        //TC: O(n).....SC:O(n)
        
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i = 0;i<nums.size();i++){
            //if value is found, pointer will never reach end of the map
            if(mp.find(target - nums[i]) != mp.end()){
                //index from hashmap
                ans.push_back(mp[target-nums[i]]); //result 1st index
                ans.push_back(i); //result 2nd index
                return ans;
                
            }
            
            //Hashing : map = {key,value}
            //key = nums[i]... value = index
            mp[nums[i]] = i;
        }
        
        return ans;
    }
    
};