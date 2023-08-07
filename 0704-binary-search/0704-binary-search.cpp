class Solution {
public:
    int search(vector<int>& nums, int target) {
        //implementing binary search
        int start = 0;
        int end = nums.size()-1;
        int mid = (start+end)/2;
        
        while(start<=end){
            if(nums[mid] == target){
                return mid;
            }
            
            if(nums[mid]<target){
                start = mid+1;
            }
            else{ //nums[mid] > target
                end = mid-1;
            }
            
            mid = (start+end)/2;
        }
        return -1;
    }
};