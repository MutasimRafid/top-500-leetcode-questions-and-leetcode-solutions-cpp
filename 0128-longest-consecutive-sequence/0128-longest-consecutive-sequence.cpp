class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //1st approach: use sorting 
        //TC: nlogn
        
        //2nd approach: use set
        //TC: O(n)+O(n)+O(n) = 3 O(n) = O(n)
        //sc: O(n)
        
        set<int> s;
        //insert all elements into set
        for(int num:nums){
            s.insert(num);
        }
        
        int longestStreak = 0;
        int currNum = 0;
        int currStreak = 0;
        
        for(int num:nums){
            //if previous element doesn't exist
            if(!s.count(num-1)){
                currNum = num;
                currStreak = 1;
                
                //now i have the minimum number in the streak
                //eg: given data: 73,72,103,102,100,101
                //eg: i have 100. now i will check for 101,102,103....
                while(s.count(currNum+1)){
                    currNum += 1;
                    currStreak += 1;
                }
            }
            longestStreak = max(longestStreak,currStreak);
        }
        
        return longestStreak;
    }
};