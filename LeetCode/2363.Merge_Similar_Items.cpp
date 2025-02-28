class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        std::map<int, int> sum_weight;
        for(const auto& item : items1){
            sum_weight[item[0]] += item[1];
        }
        for(const auto& item : items2){
            sum_weight[item[0]] += item[1];
        }
        std::vector<std::vector<int>> ret;
        for(const auto& pair : sum_weight){
            ret.push_back({pair.first, pair.second});
        }
        return ret;
    }
};
