// question link = https://leetcode.com/problems/toeplitz-matrix


class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        bool flag = true;
        int rows = matrix.size();
        int cols = matrix[0].size();
        if(rows == 1 || cols == 1) return true;
        for(int i=0; i<rows; i++) {
            int x = matrix[i][0];
            int k = 0;
            while(1) {
                
                if(i+k>=rows || k>=cols) {
                    break;
                }
                // cout<<"k = "<<"["<<k<<"]"<<"["<<i+k<<"]"<<endl;
                // cout<<" "<<matrix[i+k][k]<<endl;
                if(x != matrix[i+k][k]) {
                    flag = false;
                    break;
                }
                k++;
                
            }
        }
        
        for(int i=0; i<cols; i++) {
            int x = matrix[0][i];
            // cout<<"----X-----"<<x<<"----X------"<<endl;
            int k = 0;
            while(1) {
                if(i+k>=cols || k>=rows) {
                    break;
                }
                // cout<<"k = "<<"["<<k<<"]"<<"["<<i+k<<"]"<<endl;
                // cout<<" "<<matrix[k][i+k]<<endl;
                if(x != matrix[k][i+k]) {
                    flag = false;
                    break;
                }
                k++;
                
            }
        }
       
        return flag;
    }
};