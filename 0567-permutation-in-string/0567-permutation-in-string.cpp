class Solution {
public:
    //TC: O(n)
    //SC: O(n)
    //using sliding window
    
    bool checkInclusion(string s1, string s2) {
        vector<int> s1hash(26,0);
        vector<int> s2hash(26,0);
        
        int s1len = s1.size();
        int s2len = s2.size();
        
        if(s1len>s2len) return false;
        
        int left = 0,right = 0;
        //at the beginning of sliding window
        while(right<s1len){
            s1hash[s1[right] - 'a'] += 1;
            s2hash[s2[right] - 'a'] += 1;
            right += 1;
        }
        
        //as in the last loop, in last iteration right became +1 from sliding window size. eg= window size 3. so sliding window size 0-3. right is at 4. after -1. right is at 3.
        //to point right to the end of the window
        right -= 1; 
        
        while(right<s2len){
            if(s1hash == s2hash) return true;
            
            right += 1;
            if(right != s2len)
                s2hash[s2[right] - 'a'] += 1;
            s2hash[s2[left] - 'a'] -= 1;
            left += 1;
        }
        return false;
    }
};