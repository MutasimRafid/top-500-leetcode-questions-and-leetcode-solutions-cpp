class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //1. use nested loop. tc: o(n^2)
        //2. use sorting. tc: o(nlogn)
        //3. use map. tc: logn
            //use map. and count frequency.
        
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