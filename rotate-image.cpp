class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size()-1;
        for(int i=0; i<matrix.size(); i++) {
            if (i >= n) {
                break;
            }
            swap(matrix[i], matrix[n]);
            n--;
        }
        
        for(int i=0; i<matrix.size(); i++) {
            for(int j=i+1; j<matrix[0].size(); j++) {
                   if(i !=j ) {
                       int temp;
                       temp = matrix[i][j];
                       matrix[i][j] = matrix[j][i];
                       matrix[j][i] = temp;
                   }
            }
        }
    }
};