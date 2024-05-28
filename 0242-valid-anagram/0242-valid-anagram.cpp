class Solution {
public:
    bool isAnagram(string s, string t) {
        //1. using sorting ... TC: O(nlogn).. SC: (1)
        //2. using bucket array/frequency array TC: O(logn).. SC:O(1) as we are using only 21 alphabet space
        
        if(s.size() != t.size()){
            return false;
        }
           
           vector<int> count(26);
           for(int i = 0;i<s.size();i++){
               count[s[i]-'a']++;
           } 
            
            for(int i = 0;i<t.size();i++){
                int x = --count[t[i]-'a'];
                if(x<0){
                    return false;
                }
            }
            
            return true;
           
        }   
           
           
           
           
           
           };
           