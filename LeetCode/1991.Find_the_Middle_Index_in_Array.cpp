class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int totalSum = 0;
        int leftSum = 0;
        for(int num : nums){
            totalSum += num;
        }
        for(int i = 0; i < nums.size(); ++i){
            int rightSum = totalSum - leftSum - nums[i];
            if(rightSum == leftSum){
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};
