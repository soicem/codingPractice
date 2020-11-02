#pragma once

#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> dp;
  std::vector<std::vector<int>> DIRECTIONS{
    {1, 0},
    {0, -1},
    {-1, 0},
    {0, 1}
  };

  int longestIncreasingPath(std::vector<std::vector<int>>& matrix) {
    if (matrix.empty()) { return 0; }
    if (matrix[0].empty()) { return 0; }

    dp.resize(matrix.size(), std::vector<int>(matrix[0].size(), -1));

    auto answer = 0;
    for (auto y = 0; y < matrix.size(); ++y) {
      for (auto x = 0; x < matrix[y].size(); ++x) {
        answer = std::max(answer, dfs(matrix, x, y, INT_MIN));
      }
    }
    return answer;
  }

  int dfs(std::vector<std::vector<int>>& matrix, int x, int y, int previousValue) {
    if (y < 0 || y >= matrix.size()) { return 0; }
    if (x < 0 || x >= matrix[0].size()) { return 0; }

    const auto value = matrix[y][x];
    if (value <= previousValue) { return 0; }

    if (dp[y][x] != -1) { return dp[y][x]; }
    dp[y][x] = 0;

    auto answer = 0;
    for (auto direction : DIRECTIONS) {
      auto nextX = x + direction[0];
      auto nextY = y + direction[1];
      answer = std::max(answer, dfs(matrix, nextX, nextY, value) + 1);
    }
    dp[y][x] = answer;
    return answer;
  }
};
