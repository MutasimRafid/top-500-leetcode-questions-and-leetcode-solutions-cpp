class Solution {
public:
    //solution 1: using nested loop: TC:O(n)^2
    //solution 2: using division TC: O(n) .. SC:O(1)
    //solution 3: Using 2 extra array.left product array and right product array... TC:O(n).. SC:O(n)
    
    //Most optimized according to follow up question.
     //solution 4: Use output array as leftProduct array and a variable as right product array.
     // then convert output array as answer array (inplace)
    //TC:O(n)  ..SC: O(1) output array is not considered as extra space according to question
    
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output;
        //edge case
        if(n<1){
            return output;
        }
        
        int product = 1; //here using product as normal variable
        //using output array as left product array
        for(int i = 0;i<n;i++){
            product *= nums[i];
            output.push_back(product);
        }
        
        //traverse from right and update output array
        product = 1; //now using product as right product array
        for(int i = n-1;i>0;i--){
            output[i] = output[i-1] * product;
            product *= nums[i];
        }
        output[0] = product; //default value. 
        
        return output;
        
    }
};