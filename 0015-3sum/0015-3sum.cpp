class Solution {
public:
    //Approach 1: using 3 nested loop ..... O(n^3)
    //ApproaCH 2: Using 2 nested loop + use hashmap (Reduces 1 loop)... TC:O(n^2)..OC: O(n)
    //Approach 3: using 2 pointer TC: O(nlogn)..SC: O(n)
    vector<vector<int>> threeSum(vector<int>& nums) {
       int n = nums.size();
       vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        
        for(int i = 0;i<n;i++){
            
            int a = nums[i];
            int t = -a;
            int s = i+1,e = n-1;
            
            while(s<e){
                if(nums[s]+nums[e] == t){
                    ans.push_back({nums[i],nums[s],nums[e]});
                    //stop reapeating
                    while(s<e && nums[s]==nums[s+1]) s++;
                    while(s<e && nums[e]==nums[e-1]) e--;
                    
                    s++;
                    e--;
                }
                else if(nums[s]+nums[e] > t){
                    e--;
                }
                else{
                    s++;
                }
            }
            //stop repeating
            while(i+1<n && nums[i+1] == nums[i]) i++;
        }
        
        return ans;

    }
};