class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp; //key,value
        
        for(auto x: strs){
            string temp = x;
            sort(x.begin(),x.end());
            mp[x].push_back(temp); //key = x, value = temp
        }
        
        for(auto x: mp){
            vector<string> temp = x.second;
            ans.push_back(temp);
        }
        
        return ans;
    }
};