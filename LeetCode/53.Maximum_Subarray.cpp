class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int maxSum = nums[0];
        int sum = nums[0];
        for(int i = 1; i < size; ++i){
            sum = std::max(nums[i], sum + nums[i]);
            maxSum = std::max(sum, maxSum);
        }
        return maxSum;
    }
};
