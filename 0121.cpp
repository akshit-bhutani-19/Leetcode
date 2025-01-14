// 121. Best Time to Buy and Sell Stock
// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

//Time complexity of this solution is O(n^2) which can be inproved.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int highest_initial = 0;
        int n = prices.size();
        for (int i = n-1 ; i >= 0 ; i--){
            if (prices[i]<=highest_initial){
                continue;
            }
            else{
                highest_initial = prices[i];
                for(int j=i-1; j>=0 ; j--){
                    if (prices[i]-prices[j]>max_profit){
                        max_profit = prices[i]-prices[j];
                    }
                }
            }
        }
        return max_profit;
    }
};