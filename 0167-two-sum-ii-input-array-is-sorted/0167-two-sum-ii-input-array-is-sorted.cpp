class Solution {
public:
    //solution 1: nested loop. TC: O(n)^2
    //solution 2: As input is sorted. Use binary search. TC: nlogn
    //solution 3: As input is sorted. Use 2 pointer approach. TC: O(n) 
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size()-1;
        
        vector<int> ans;
        
        while(l<r){
            if(numbers[l]+numbers[r] == target){
                ans.push_back(l+1);
                ans.push_back(r+1);
                
                return ans;
                
                //return {l+1,r+1};        
            }
            else if(numbers[l]+numbers[r] > target){
                r--;
            }
            else{
                l++;
            }
        }
        return ans;
    }
};