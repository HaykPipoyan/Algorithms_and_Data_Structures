class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        std::unordered_set<char> st(jewels.begin(), jewels.end());
        int count = 0;
        for (char stone : stones){
            if (st.count(stone)){
                ++count;
            }
        }
        return count;
    }
};

