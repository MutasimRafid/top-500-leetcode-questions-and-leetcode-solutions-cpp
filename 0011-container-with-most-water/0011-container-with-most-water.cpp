class Solution {
public:
    //TC: O(n)
    //SC: O(1)
    int maxArea(vector<int>& height) {
        int ans = 0;
        int left = 0;
        int right = height.size()-1;
        
        while(left < right){
           
            int currArea = min(height[left],height[right]) * (right-left);
            ans=max(currArea,ans);
                
            if(height[left] < height[right] ){
                left++;
            }
            else{
                right--;
            }
        }
        
        return ans;
    }
};