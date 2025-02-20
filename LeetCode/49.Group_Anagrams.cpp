class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(auto& x : strs){
            string current = x;
            sort(current.begin(), current.end());
            mp[current].push_back(x);
        }
        vector<vector<string>> vec;
        for(auto& i : mp){
            vec.push_back(i.second);
        }
        return vec;

    }
};
