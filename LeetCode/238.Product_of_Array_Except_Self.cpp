class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> res(size, 1);
        int prefixSum = 1;
        for(int i = 1; i < size; ++i){
            prefixSum *= nums[i - 1];
            res[i] = prefixSum;
        }
        prefixSum = 1;
        for(int i = size - 1; i >= 0; --i){
            res[i] *= prefixSum;
            prefixSum *= nums[i];
        }
        return res;
    }
};
