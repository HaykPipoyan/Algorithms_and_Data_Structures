class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int index = 0;
        for(int i = 1; i < prices.size(); ++i) {
            if(min > prices[i] && i != prices.size() - 1) {
                min = prices[i];
                index = i;
            }
        }
        int max = prices[index];
        for(int j = index; j < prices.size(); ++j) {
                if(max < prices[j]) {
                    max = prices[j];
                } 
            
        }
        return max - min;
    }
};
