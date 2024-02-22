class Solution {
public:
    bool isAnagram(string s, string t) {
        //Approach1: Brute force solution
        //sorting: TC: O(nlogn)... if manual  quick sort fastest nlogn
        //after sorting if s[i] != t[i] .. not anagram
        
        // Approach 2: use map... TC: O(log n)..
        //
        
        if(s.size() != t.size()){
            return false;
        }
        
        vector<int> v(26);
        
        for(int i = 0;i<s.size();i++){
            v[s[i]-'a']++;
        }
        
        for(int i = 0;i<t.size();i++){
            int x = --v[t[i]-'a'];
            
            if(x<0){
                return false;
            }
        }
        
        return true;
        
        
    }
};