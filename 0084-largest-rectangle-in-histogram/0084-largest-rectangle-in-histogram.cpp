class Solution {
public:
    /*
    //approach 1: using loop .. TC: O(n^2).. SC: 
    
    int largestarea(int arr[], int n) {
  int maxArea = 0;
  for (int i = 0; i < n; i++) {
    int minHeight = INT_MAX;
    for (int j = i; j < n; j++) {
      minHeight = min(minHeight, arr[j]);
      maxArea = max(maxArea, minHeight * (j - i + 1));
    }
   }
  return maxArea;
 }
    */
    
    //approach 2: using stack
    //TC: O(n).. //SC: O(N)
    
    vector<int> nextSmallerElement(vector<int> arr,int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        
        
        for(int i = n-1;i>=0;i--){
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr){
                s.pop();
            }
            
            //ans = stack er top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    } 
    
    
    vector<int> prevSmallerElement(vector<int> arr,int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        
        
        for(int i = 0;i<n;i++){
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr){
                s.pop();
            }
            
            //ans = stack er top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        vector<int> next(n);
        next = nextSmallerElement(heights,n);
        
        vector<int> prev(n);
        prev = prevSmallerElement(heights,n);
        
        int area = INT_MIN;
        
        for(int i = 0;i<n;i++){
            int l = heights[i];
            if(next[i] == -1){
                next[i] = n;
            }
            int width = next[i] - prev[i] - 1;
            int newArea = width * l;
            area = max(area,newArea);
        }
        return area;
    }
};