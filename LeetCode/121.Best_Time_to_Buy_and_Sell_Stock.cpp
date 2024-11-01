class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int min = prices[0];
        for(int i = 1; i < prices.size(); ++i){
            int num = prices[i] - min;
            if(min > prices[i]){
                min = prices[i];
            }
            if(num > profit){
                profit = num;
            }
            
        }
        return profit;
    }
};
