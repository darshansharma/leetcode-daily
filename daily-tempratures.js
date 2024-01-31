    // Question link - https://leetcode.com/problems/daily-temperatures/description/
    // Difficulty - Easy
    // Date Attempted - 31 Jan 2024

/**
 * @param {number[]} temperatures
 * @return {number[]}
 */
var dailyTemperatures = function(temperatures) {
    const n = temperatures.length;
    const stack = [];
    const result = new Array(n).fill(0);

    for (let i = n - 1; i >= 0; --i) {
        while (stack.length > 0 && temperatures[i] >= temperatures[stack[stack.length - 1]]) {
            
            stack.pop();
        }

        if (stack.length > 0) {
            result[i] = stack[stack.length - 1] - i;
        }
        stack.push(i);
    }
    return result;
};
