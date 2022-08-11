// question link - https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix

/**
 * @param {number[][]} matrix
 * @param {number} k
 * @return {number}
 */
var kthSmallest = function (matrix, k) {
    let n = matrix.length;
    if (k == 1) return matrix[0][0];
    if (k == 2) return Math.min(matrix[0][1], matrix[1][0]);
    let i = 0,
        j = 0;
    let newArr = [];
    for (let index = 0; index < matrix.length; index++) {
        newArr.push(matrix[j][index]);
        if (index == n - 1 && j == n - 1) {
            break;
        }
        if (index == matrix.length - 1) {
            j++;
            index = -1;
        }
    }
    newArr.sort((a, b) => a - b);
    return newArr[k - 1];
};
