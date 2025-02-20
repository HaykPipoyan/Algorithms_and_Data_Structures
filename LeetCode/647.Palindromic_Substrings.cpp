class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for(int t = 1; t < s.size(); ++t){
            int i = t - 1;
            int j = t;
            while(i >= 0 && j < s.size()){
                if(s[i] == s[j]){
                    ++res;
                } else {
                    break;
                }
                --i;
                ++j;
            }
        }
        for(int t = 0; t < s.size(); ++t){
            int i = t;
            int j = t;
            while(i >= 0 && j < s.size()){
                if(s[i] == s[j]){
                    ++res;
                } else {
                    break;
                }
                --i;
                ++j;
            }
        }
    return res;
    }
};
