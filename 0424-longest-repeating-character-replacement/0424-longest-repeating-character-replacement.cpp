class Solution {
    //TC: O(n)
    //SC: O(26) = O(1)
    //using two pointer approach
    //code from leetcode  discussion
    //watch video tutorial and code in the comment of youtube
public:
    
    int characterReplacement(string s, int k) {
        int n = s.length(),res = 0;
        int start = 0,end = 0,maxFreq = 0;
        map<int,int> mp; //frequency map of A , B
        for(end = 0;end<n;end++){
            mp[s[end]]++;
            maxFreq = max(maxFreq,mp[s[end]]);
            
            //eg: AABABBA
            //less Occuring Frequency value(frequency value of B) till now = sliding window length((end-start)+1)  - maxFreq(frequency of A)
            //this value above > k ... that means we have used all k value
            //now we need to move start pointer and change the window and form a new substring
            
            while(end-start+1 - maxFreq > k){
                mp[s[start]]--;
                start++;
            }
            res = max(res,end-start+1);
        }
        return res;
    }
};