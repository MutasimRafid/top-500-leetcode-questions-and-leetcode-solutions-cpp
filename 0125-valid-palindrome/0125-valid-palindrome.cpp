class Solution {
public:
    /*
        Algo:
        1. For palindrome check there is palindrome function.
        2. Palindrome function: string s2 = reverse(s)... loop: if s1 == s2 then yes
        3. now free space + uppercase letter. make all lowercase and omit 
        using ascii value.
        4. then compare using palindrome function
            */
    
    bool isPal(string s){
        string s2 = s;
        reverse(s2.begin(),s2.end());
        if(s2==s){
            return true;
        }
        else{
            return false;
        }
    }
    
    
    bool isPalindrome(string s) {
        
        string s3 = "";
        
        for(auto i: s){
            if(i >= 'a' && i<= 'z') s3+=(char)i;
            else if(i >= 'A' && i<= 'Z') s3+=(char)(i-'A'+'a');
            else if(i >= '0' && i<= '9') s3+=(char)i;
        }
        
        return isPal(s3);
        
        
    }
};