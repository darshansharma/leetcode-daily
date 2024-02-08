// Question link - https://leetcode.com/problems/perfect-squares/description
// Difficulty - Medium
// Date Attempted - 02 Feb 2024

function numSquares(n) {
    const squareNums = Array.from({ length: Math.floor(Math.sqrt(n)) }, (_, i) => Math.pow(i + 1, 2));

    const minNumSquares = (k) => {
      if (squareNums.includes(k)) {
        return 1;
      }
      let minNum = Infinity;

      for (let square of squareNums) {
        if (k < square) {
          break;
        }
        const newNum = minNumSquares(k - square) + 1;
        minNum = Math.min(minNum, newNum);
      }
      return minNum;
    };

    return minNumSquares(n);
  }

 // Notes Section

// Non DP Solution 