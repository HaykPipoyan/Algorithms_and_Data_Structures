class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        unordered_map<char, int> map;
        for(auto& i : s){
            map[i]++;
        }
        for(auto& j : t){
            map[j]--;
            if(map[j] == 0){
                map.erase(j);
            }
        }
        if(map.size() != 0){
            return false;
        }
        return true;
        }
};
