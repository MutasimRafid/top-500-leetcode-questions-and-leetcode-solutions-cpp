class Solution {
    //using sliding window technique, also using hashmap. Here using frequency array as hashmap
    //TC: O(n)
    //SC: O(n)
public:
    int lengthOfLongestSubstring(string s) {
        int count[256] = {0};
        int l = 0;
        int r = 0;
        int ans = 0;
        
        while(r<s.size()){
            count[s[r]]++;
            
            while(count[s[r]] > 1 ){
               count[s[l]]--;
                l++;
            }
            
            
            ans = max(ans,r-l+1); //1 based indexing
            r++;
        }
        return ans;
    }
};