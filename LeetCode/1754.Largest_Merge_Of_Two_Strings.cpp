class Solution {
public:
    string largestMerge(string word1, string word2) {
        std::string merge {};
        while(!word1.empty() || !word2.empty()){
            if(word1 > word2){
                merge += word1[0];
                word1.erase(word1.begin());
            } else {
                merge += word2[0];
                word2.erase(word2.begin());
            }
        }
        return merge;
    }
};
