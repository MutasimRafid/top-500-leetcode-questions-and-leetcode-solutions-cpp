class Solution {
public:
    //using map and frequency
    //TC: O(n).. SC: O(n)
    bool isAnagram(string s, string t) {
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