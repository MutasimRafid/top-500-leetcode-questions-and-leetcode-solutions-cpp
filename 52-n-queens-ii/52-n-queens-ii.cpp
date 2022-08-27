class Solution {
public:
    int totalNQueens(int n) {
        vector<bool> col(n,true);
        vector<bool> antiD(2 *n-1, true);
        vector<bool> mainD(2 *n-1, true);
        vector<int> row(n,0);
        int count = 0;
        
        solve(0, row, col, mainD, antiD, count);
        return count;
    }
    
    void solve(int i, vector<int> &row, vector<bool> &col, vector<bool> &mainD, vector<bool> &antiD, int &count){
        
        //Base case
        if(i == row.size()){
            count++;
            return;
        }
        
        
        //1st loop: For each col check if solution possible: check question picture and notebook
        //loop will executed inside each solution
         
        //after 1st loop loop
        //each solution 
        for(int j = 0; j < col.size(); j++){
            if (col[j] && mainD[i+j] && antiD[i+col.size()-1-j]) {
                 
                row[i] = j; 
                 col[j] = mainD[i+j] = antiD[i+col.size()-1-j] = false;
                
                //recursive call: next row
                 solve(i+1, row, col, mainD, antiD, count);
                 
                //backtracking
                 col[j] = mainD[i+j] = antiD[i+col.size()-1-j] = true;
          }
        }
    }
};