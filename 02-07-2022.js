

// question link - https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix


/**
 * @param {number[][]} matrix
 * @param {number} k
 * @return {number}
 */
var kthSmallest = function(matrix, k) {
    let i = 0;
    let range = 0;
    let n = matrix.length * matrix.length;

    if (k == 1) return matrix[0][0];
    if (k == 2) return Math.min(matrix[0][1], matrix[1][0])
    while(i < matrix.length) {
        if (k <= (i*matrix.length + i)) {
            break;
        }
        i++;
    }
    console.log("i = ", i);
    let newArr = [];
    let j=0;
    for(let index=0; index<matrix.length; index++) {
        newArr.push(matrix[j][index]);
        if (index == (matrix.length - 1) && j == matrix.length-1 ) {
            break;
        }
        if (index == (matrix.length - 1)) {
            j++;
            index = -1;
        }
    }
    
    newArr.sort((a,b)=>a-b);
    
    return newArr[k-1];
    
    
};
