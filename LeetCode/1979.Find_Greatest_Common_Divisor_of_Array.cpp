class Solution {
public:
    int GCD(int a, int b){
        while(b){
            a %= b;
            std::swap(a, b);
        }
        return a;

    }

    int findGCD(vector<int>& nums) {
        int min = 1000;
        int max = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(min > nums[i]){
                min = nums[i];
            }
            if(max < nums[i]){
                max = nums[i];
            }
        }
        return GCD(min, max);
    }
};
