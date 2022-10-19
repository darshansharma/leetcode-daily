// question link - https://leetcode.com/problems/largest-perimeter-triangle

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        while(1){
            if((nums[len-3] + nums[len-2]) > nums[len-1]) {
                return nums[len-3] + nums[len-1] + nums[len-2];
            }
            if((len-3)>0) {
                len = len-1;    
            } else {
                break;
            }
            
        }
        return 0;
    }
};