class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_set<int> set;
        for(int num : nums1) {
            set.insert(num);
        }
        std::vector<int> ans;
        for(auto& it : nums2) {
            if(set.find(it) != set.end()) {
                ans.push_back(it);
                set.erase(it);
            }
        }
        return ans;
    }
};
