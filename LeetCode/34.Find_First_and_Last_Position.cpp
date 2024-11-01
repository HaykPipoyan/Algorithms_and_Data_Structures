class Solution {
public:
    int lowerBound(vector<int>& nums, int target){
        int start = 0;
        int end = nums.size() - 1;
        while(start < end){
            int mid = start + (end - start) / 2;
            if(nums[mid] < target){
                start = mid + 1;                
            } else {
                end = mid;
            }
        }
        if(nums[start] == target){
            return start;
        }
        return -1;
    }

    int upperBound(vector<int>& nums, int target){
        int start = 0;
        int end = nums.size() - 1;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(nums[mid] <= target){
                start = mid + 1;
            } else {
                end = mid -1;
            }
        }
        if(nums[end] == target){
            return end;
        }
        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()){
            return {-1, -1};
        }
        vector<int> res;
        int lower = lowerBound(nums, target); 
        if(lower == -1){
            return {-1, -1};
        }      
        int upper = upperBound(nums, target);
        res.push_back(lower);
        res.push_back(upper);
        return res;
    }
};
