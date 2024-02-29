class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //Approach 1: Nested loop. TC: O(n^2)
        //Approach 2: use 2 array as left[] and right[]  cumulative.. TC: O(n).. SC: O(2n)
        
        // Answers the follow up question
        //Approach 3: Use 1 Array as left[] and use variable product as right[] .. TC: O(n).. SC: O(1)
        
       int n = nums.size();
       vector<int> output;
        //edge case
        if(n<1){
            return output;
        }
        
        int product = 1;
        //left[]
        for(int i = 0;i<n;i++){
            product = product * nums[i];
            output.push_back(product); //left[i]
        }
        
        //traverse from right and output output array
        product = 1;
        for(int i = n-1;i>0;i--){
            output[i] = output[i-1] * product;
            product = product * nums[i];
            
        }
        output[0] = product;
        
        return output;
        
    }
};