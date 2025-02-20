class Solution {
public:
    int maximumCount(vector<int>& nums) {
        auto[t1, t2] = std::equal_range(nums.begin(), nums.end(), 0);
        int neg = t1 - nums.begin();
        int pos = nums.end() - t2;
        return std::max(neg, pos);
    }
};
