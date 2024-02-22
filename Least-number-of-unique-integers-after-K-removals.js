// question link: https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/
// difficulty:    medium



/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number}
 */
var findLeastNumOfUniqueInts = function(arr, k) {
    const frequencyMap = new Map();
    
    arr.forEach(num => {
        frequencyMap.set(num, (frequencyMap.get(num) || 0) + 1);
    });
    
    // Convert map entries to an array of [number, frequency] pairs and sort by frequency
    const sortedFreqArray = Array.from(frequencyMap.entries()).sort((a, b) => a[1] - b[1]);
    
    let uniqueCount = sortedFreqArray.length;
    
    // Iterate through the sorted frequency array
    for (const [num, frequency] of sortedFreqArray) {
        if (k >= frequency) {
            // If k is greater than or equal to the frequency of the current number,
            // decrement k by the frequency and decrement the unique count
            k -= frequency;
            uniqueCount--;
        } else {
            // If k is less than the frequency of the current number, break the loop
            break;
        }
    }
    
    return uniqueCount;
    
    
};