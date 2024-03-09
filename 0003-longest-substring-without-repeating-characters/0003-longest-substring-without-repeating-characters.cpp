class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //Approach 1: Using Sliding window and hashmap .. TC:O(n).. SC:O(1)
        
        int count[256] = {0};
        int l = 0;//starting index of the window
        int r = 0;//ending index of the window
        int ans = 0; //length of the longest substring without repeating chracters
        
        while(r<s.size()){
            count[s[r]]++; //adding frequency
            
            //if there is a repeating chracter in the window
            while(count[s[r]]>1){
                count[s[l]]--;  //remove frequency from count
                l++; //shorten the window
            }
            
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};