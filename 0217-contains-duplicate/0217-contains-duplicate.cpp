class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //1. using nested loop .. TC: O(n^2).. SC: O(1)
        //2. using sorting .. TC: O(nlogn).. SC: O(1)
        //3. using map and count frequency.. TC: O(n).. SC: O(n)
        
        map<int,int> countMap;
        
        for(int i = 0;i<nums.size();i++){
            if(countMap[nums[i]]){
                return true;
            }
            
            countMap[nums[i]]++;
        }
        
        return false;
    }
};