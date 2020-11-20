#pragma once
#include <algorithm>
#include <vector>

class Solution {
public:
  int coinChange(std::vector<int>& coins, int amount) {
    std::vector<int> dp;
    dp.resize(amount + 1, INT_MAX);
    dp[0] = 1;

    for (int ifAmount = 1; ifAmount <= amount; ++ifAmount) {
      for (auto coin : coins) {
        auto amountAfter = ifAmount - coin;
        if (amountAfter > 0 && dp[amountAfter] != INT_MAX) {
          dp[ifAmount] = std::min(dp[ifAmount], dp[amountAfter] + 1);
        }
      }
    }

    return (dp[amount] == INT_MAX) ? (- 1) : (dp[amount]);
  }
};
