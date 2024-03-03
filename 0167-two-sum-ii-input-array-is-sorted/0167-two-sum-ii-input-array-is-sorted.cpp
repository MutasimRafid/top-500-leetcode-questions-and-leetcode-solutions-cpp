class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //Approach 1: using nested loop .. TC: O(n^2)
        //Approach 2: use binary search
        //Approach 3: using two pointer approach TC: O(n).. SC:O(1)
        
        int l = 0;
        int r = numbers.size()-1;
        
        while(l<r){
            if((numbers[l]+numbers[r]) == target){
                return {l+1,r+1};
            } 
            else if(numbers[l]+numbers[r] > target){
                r--;
            }
            else{
                l++;
            }
        }
        
        return {};
    }
};