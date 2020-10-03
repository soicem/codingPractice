#ifndef LogestIncreasingPathInAMatrix_h__
#define LogestIncreasingPathInAMatrix_h__


#include <vector>
#include <unordered_map>

using namespace std;

#define IN_RANGE(x, from, to) (from <= x && x < to)

struct PairHash {
  template<typename T, typename U>
  size_t operator()(const pair<T, U>& source) {
    size_t hash1 = hash<T>()(source.first);
    size_t hash2 = hash<T>()(source.second);
    return (hash1 * 31) ^ hash2;
  }
};

int directions[4][2] {
  {1, 0},
  {0, 1},
  {-1, 0},
  {0, -1}
};

class Solution {
public:
  unordered_map<pair<int, int>, vector<pair<int, int>>, PairHash> paths;
  unordered_map<pair<int, int>, int, PairHash> dp;

  int longestIncreasingPath(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) { return 0; }

    paths = *new unordered_map<pair<int, int>, vector<pair<int, int>>, PairHash>();
    for (int y = 0; y < matrix.size(); ++y) {
      for (int x = 0; x < matrix[0].size(); ++x) {
        paths[{x, y}] = getAllDestinations(matrix, x, y);
      }
    }

    dp = *new unordered_map<pair<int, int>, int, PairHash>();
    int maxPath = 1;
    for (auto& keyValue : paths) {
      maxPath = max(maxPath, dfs(keyValue.first));
    }
    return maxPath;
  }

  int dfs(pair<int, int>& source) {
    if (dp.count(source) > 0) { return dp[source]; }

    int maxPath = 0;
    for (const auto& neighbor : paths[source]) {
      maxPath = max(maxPath, dfs(neighbor));
    }
    dp[source] = maxPath + 1;
    return maxPath + 1;
  }

  vector<pair<int, int>>& getAllDestinations(vector<vector<int>>& matrix, int x, int y) {
    auto& destinations = *new vector<pair<int, int>>();
    for (auto& direction : directions) {
      int neighborX = x + direction[0];
      int neighborY = y + direction[1];

      if (!IN_RANGE(neighborX, 0, matrix[0].size())) { continue; }
      if (!IN_RANGE(neighborY, 0, matrix.size())) { continue; }
      if (matrix[y][x] <= matrix[neighborY][neighborX]) { continue; }

      destinations.push_back({neighborX, neighborY});
    }
    return destinations;
  }
};


#endif // LogestIncreasingPathInAMatrix_h__