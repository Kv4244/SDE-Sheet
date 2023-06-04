class Solution {
public:
    /*
        Brute force
            Try all possible ways
                1. run a loop for buying stock 
                2. run a loop for selling the bought stock
                3. return max

                int maxProfit(vector<int>& prices) {
                    int maxProfit = 0;
                    for(int i=0;i<prices.size();i++){
                        for(int j=i;j<prices.size();j++){
                            if(prices[j] - prices[i] > maxProfit)
                                maxProfit = prices[j] - prices[i];
                        }
                    }
                    return maxProfit;
                }

            TC : O(N X N) 
            SC : O(1)
    */
    /*
        Pointers 
            1. initialize a pointer as minimumStockBeforeCurr = nums[0];
            2. run a loop for 1 -> n-1
                res = max(res,nums[i]-minimumStockBeforeCurr)
                minimumStockBeforeCurr = min(minimumStockBeforeCurr,nums[i]);
            3. return ans;

            TC : O(N)
            SC : O(1)
    */
    int maxProfit(vector<int>& prices) {
        int max_profit = 0, minimum_stock_before_curr = prices[0];
        for(int i=1;i<prices.size();i++){
            max_profit = max(max_profit,prices[i] - minimum_stock_before_curr);
            minimum_stock_before_curr = min(minimum_stock_before_curr,prices[i]);
        }
        return max_profit;
    }
};