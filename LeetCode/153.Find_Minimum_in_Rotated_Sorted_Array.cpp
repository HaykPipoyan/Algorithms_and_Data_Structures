class Solution {
public:
    int findMin(vector<int>& nums) {
        int min = INT_MIN;
        int start = 0;
        int end = nums.size() - 1;
        while(start < end){
            int mid = start + (end - start) / 2;
            if(nums[start] <= nums[mid] && nums[mid] > nums[end]){
                start = mid + 1;
            } else {
                end = mid ;
            }           
        }
        min = nums[start];
        return min;

    }
};
