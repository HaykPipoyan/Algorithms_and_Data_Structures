class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int corent = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            if(!count) {
                corent = nums[i];
                ++count;
                continue;
            }
            if(nums[i] == corent) {
                ++count;
                continue;
            }
            --count;
        }
        return corent;
    }
};
