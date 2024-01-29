    // Question link - https://leetcode.com/problems/implement-queue-using-stacks/description/
    // Difficulty - Easy
    // Date Attempted - 29 Jan 2024

var arr = Array();
var MyQueue = function() {
    arr = [];
};

/** 
 * @param {number} x
 * @return {void}
 */
MyQueue.prototype.push = function(x) {
    arr.push(x);
};

/**
 * @return {number}
 */
MyQueue.prototype.pop = function() {
    let elem = arr.shift();
    return elem;
};

/**
 * @return {number}
 */
MyQueue.prototype.peek = function() {
    return arr[0];
};

/**
 * @return {boolean}
 */
MyQueue.prototype.empty = function() {
    return arr.length === 0 ? true : false;
};

/** 
 * Your MyQueue object will be instantiated and called as such:
 * var obj = new MyQueue()
 * obj.push(x)
 * var param_2 = obj.pop()
 * var param_3 = obj.peek()
 * var param_4 = obj.empty()
 */