class Solution {
public:
    bool palindromeCheck(string s){
        string other = s;
        reverse(other.begin(),other.end());
        return (other == s);
        
    }
    
    
    bool isPalindrome(string s) {
        string s2 = "";
        for(auto i: s){
            if(i >= 'a' && i<= 'z') s2 += (char)i;
            else if(i >= 'A' && i<= 'Z') s2 += (char)(i-'A'+'a');
            else if(i >= '0' && i<= '9') s2 += (char)i;
        }
        
        return palindromeCheck(s2);
    }
    
};