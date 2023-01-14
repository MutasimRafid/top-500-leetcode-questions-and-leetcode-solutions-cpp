class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //approach 1: brute force = nested loop
        //TC: O(n*k) = O(n^2)
        //algo: take 2 loop and store largest element inside vector of each k sized window
        //outside loop from i to n = nums.size
        //inside loop = from j = i to i<i+k-1
        /*
        for(int i = 0;i<nums.size();i++){
          for(int j = i;j<i+k-1;i++){
            maxi = max(nims[i],maxi);
          }
          ans.push_back(maxi);
        }
        */
        
        
        //approach 2: using doubly ended queue
        //TC: O(n).. sc: O(K)
        /*
        //Algo:
        for example k = 3
        1. In queue maintain strictly decreasing order: 9,7,5,-1,-3
        2. store ans from front(largest element): 9,7,5 ..large = 9[also maintainig k sized window]
        3. after window is finished, remove 1 extra element from front
          eg: 9 7 5 -4...remove 9
          
        4. in k sized window, if any bigger element is found,remove all old smaller element
           eg: 7 5 .. element found 10 .. now remove 7 and 5 
           now queue: 10 
        */
        
        deque<int> dq;
        vector<int> ans;
        
        for(int i = 0;i<nums.size();i++){
            //point 3
            if(!dq.empty() && dq.front() == i-k) dq.pop_front();
            
            //point 4
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            
            //point 1
            dq.push_back(i);
            
            //point 2
            if(i>=k-1) ans.push_back(nums[dq.front()]);
            
        }
        return ans;
    }
};