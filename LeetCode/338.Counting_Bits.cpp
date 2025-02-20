class Solution {
public:
    vector<int> countBits(int n) {
        std::vector<int> ans(n + 1, 0);
        for(int i = 1; i <= n; ++i){
            ans[i] = ans[i / 2] + (i % 2);
        }
        return ans;
    }
};
