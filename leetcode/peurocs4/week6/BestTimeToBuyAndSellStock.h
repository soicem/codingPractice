#pragma once
#include <vector>

class Solution {
public:
  int maxProfit(std::vector<int>& prices) {
    if (prices.empty()) { return 0; }

    int profit = 0;
    int cheapestBuy = prices[0];
    for (int i = 1; i < prices.size(); ++i) {
      cheapestBuy = std::min(cheapestBuy, prices[i]);
      profit = std::max(profit, prices[i] - cheapestBuy);
    }
    return profit;
  }
};
