

// question link - https://leetcode.com/problems/unique-paths/

/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var uniquePaths = function(m, n) {
    var grid = new Array(m);
    var i=0;
    while(i < m) {
        grid[i] = new Array(n).fill(0)
        i++;
    }
    
    // robot coming via last row
    for(let i=0; i<=n-1; i++) {
        grid[m-1][i] = 1;
    }
    
    // robot coming via last column
    for(let i=0; i<=m-1; i++) {
        grid[i][n-1] = 1;
    }
    
    for(let i=m-2; i>=0; i--) {
        for (let j=n-2; j>=0; j--) {
            grid[i][j] = grid[i+1][j] + grid[i][j+1];
        }
    }
    console.log(grid[0][0]);
    return grid[0][0];
    
   
};
