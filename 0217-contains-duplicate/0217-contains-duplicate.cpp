class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //using nested loop.. TC: O(n^2)..SC:O(1)
        //using sorting ...TC: O(nlogn)... SC: O(1)
        //using map and count frequency... TC: O(n)..SC:O(n)
        
        map <int,int> countMap;
        
        for(int i = 0;i<nums.size();i++){
            if(countMap[nums[i]]){
                return true;
            }
            
            countMap[nums[i]]++;
            
        }
        
        return false;
    }
};