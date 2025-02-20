class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxSum = nums[0];
        int minSum = nums[0];
        int res = nums[0];

        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] < 0){
                std::swap(minSum, maxSum);
            }
            maxSum = max(nums[i], nums[i] * maxSum);
            minSum = min(nums[i], minSum * nums[i]);
            res = max(maxSum, res);
        }
        return res;
    }
};
