#pragma once

#include <vector>
#include <unordered_map>

using namespace std;

#define IN_RANGE(x, low, high) (low <= x && x < high)

class Solution {
public:
  const vector<pair<int, int>> directions {
    {1, 0},   // 0
    {2, 1},   // 30
    {1, 1},   // 45
    {1, 2},   // 60
    {0, 1},   // 90
    {-1, 2},  // 120
    {-1, 1},  // 135
    {-2, 1},  // 150
    {-1, 0},  // 180
    {-2, -1}, // 210
    {-1, -1}, // 225
    {-1, -2}, // 240
    {0, -1},  // 270
    {1, -2},  // 300
    {1, -1},  // 315
    {2, -1}   // 330
  };

  vector<vector<bool>> used {
    {false, false, false},
    {false, false, false},
    {false, false, false}
  };
  int min;
  int max;
  
  int numberOfPatterns(int m, int n) {
    min = m;
    max = n;

    int answer = 0;
    for (int y = 0; y < used.size(); ++y) {
    	for (int x = 0; x < used[0].size(); ++x) {
        answer += recurse(x, y, 0, 0);
    	}
    }
    return answer;
  }

  int recurse(int x, int y, int usedCount, int directionId) {
    if (usedCount >= max) { return 0; }
    if (!IN_RANGE(x, 0, used[0].size())) { return 0; }
    if (!IN_RANGE(y, 0, used.size())) { return 0; }

    if (used[y][x]) {
      const auto& direction = directions[directionId];
      return recurse(x + direction.first, y + direction.second, usedCount, directionId);
    }

    used[y][x] = true;
    ++usedCount;

    int answer = 0;
    for (int i = 0; i < directions.size() && usedCount < max; ++i) {
      const auto& direction = directions[i];
      answer += recurse(x + direction.first, y + direction.second, usedCount, i);
    }

    used[y][x] = false;
    return (IN_RANGE(usedCount, min, max + 1)) ? (answer + 1) : (answer);
  }
};
