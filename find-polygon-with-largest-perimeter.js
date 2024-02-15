//  Question  :  https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/description
//  Difficulty:  Medium



/**
 * @param {number[]} nums
 * @return {number}
 */
var largestPerimeter = function(nums) {
    nums.sort((a,b)=>a-b)
    let sum=nums[0]+nums[1],resSum=-1;
    for(let i=2;i<nums.length;i++){
        if(nums[i]<sum){
            resSum=sum+nums[i];
        }
        sum+=nums[i];
    }
    return resSum;
};