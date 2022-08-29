// Used the DFS approach to traverse adjancey matrix given in input


class Solution {
public:
    int i=0, j=0;
    int nIslands=0;
    
    void dfs(vector<vector<char>>& grid, int i, int j) {
        // cout<<i<<" : "<<j<<endl;
        if (i <= -1 || j <= -1 ||  i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        dfs(grid, i, j+1);
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j-1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int k=0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    nIslands++;
                    dfs(grid,i,j);
                }
            }
        }
        return nIslands;
    }
};