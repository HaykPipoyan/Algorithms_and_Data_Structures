class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int maxCount = 0;
        int left = 0;
        for(int right = 0; right < s.length(); ++right){
            char current = s[right];
            if(map.find(current) != map.end() && map[current] >= left){
                left = map[current] + 1;
            } 
            map[current] = right;
            maxCount = max(maxCount, right - left + 1);
        }
        return maxCount;
    }
};
