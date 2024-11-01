class Solution {
public:
    void reverse(vector<int>& nums, int i, int j) {
        while(i < j) {
            std::swap(nums[i], nums[j]);
            ++i;
            --j;
        }

    }
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int i = size - 2;
        while(i >= 0 && nums[i] >= nums[i + 1]) {
            --i;
        }
        if(i == -1) {
            reverse(nums, i+1, size - 1);
            return;
        }
        int j = size - 1;
        while(j >= 0 && nums[j] <= nums[i]) {
            --j;
        }
        std::swap(nums[i], nums[j]);
        reverse(nums, i+1, size - 1);
    }
};
