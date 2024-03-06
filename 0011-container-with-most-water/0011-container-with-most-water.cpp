class Solution {
public:
    int maxArea(vector<int>& height) {
        //Approach 1: Nested loop. TC: O(n^2).. SC: O(1)
        //Approach 2: Two pointer method.TC: O(n) .. O(1)
        
        int ans = 0;
        int l = 0;
        int r = height.size()-1;
        
        while(l<=r){
            //area = length * width //  here, length = height, width = r-l
            ans = max( min(height[l],height[r]) * (r-l),ans);
            if(height[l]<height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        
        return ans;
    }
};