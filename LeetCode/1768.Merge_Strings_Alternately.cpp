class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        std::string result {};
        int size1 = word1.length();
        int size2 = word2.length();
        int i = 0;
        int j = 0;
        while(i < size1 &&  j < size2){
            result += word1[i++];
            result += word2[j++];
        }
        while(i < size1){
            result += word1[i++];
        }
        while(j < size2){
            result += word2[j++];
        }
        return result;
    }
};
