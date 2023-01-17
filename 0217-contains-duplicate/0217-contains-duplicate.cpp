
class Solution {
public:
    //solution 1: using nested loop ..TC: O(n^2)...SC: O(1)
    //solution 2: using sorting... TC: O(nlogn)..SC: O(1)
    //solution 3: using map/array to count frequency .. TC: O(logn)  SC:O(n)
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> countMap;
        
        for(int i = 0;i<nums.size();i++){
            //if the element appears 2nd time, in map nums[i] is already 1(first time increment when found)
            if(countMap[nums[i]]){
                return true;
            }
            
            //if the element appears first time
            countMap[nums[i]]++;
        }
        return false;
    }
};