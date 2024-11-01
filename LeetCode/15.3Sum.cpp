class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> vec;
        std::sort(nums.begin(), nums.end());
        int size = nums.size();
        for(int i = 0; i < size; ++i){
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            int target = -nums[i];
            int left = i + 1;
            int right = size - 1;
            while(left < right){
                int sum = nums[left] + nums[right];
                if(sum == target){
                    vec.push_back({nums[i], nums[left], nums[right]});
                    while(left < right && nums[left] == nums[left + 1]){
                        ++left;
                    }
                    while(left < right && nums[right] == nums[right - 1]){
                        --right;
                    }
                    ++left;
                    --right;
                } else if(sum < target){
                    ++left;
                } else {
                    --right;
                }        
            }    
        }
        return vec;
    }
};
