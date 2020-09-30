#ifndef NumberOfIslands_h__
#define NumberOfIslands_h__


#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>

using namespace std;

#define IS_IN_RANGE(val, to, from) (to <= val && val < from)

class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    vector<vector<int>> marker;
    for (int y = 0; y < grid.size(); ++y) {
      marker.push_back({});
      for (int x = 0; x < grid[0].size(); ++x) {
        marker.back().push_back(0);
      }
    }

    int landCount = 0;
    for (int y = 0; y < grid.size(); ++y) {
      for (int x = 0; x < grid[0].size(); ++x) {
        if (grid[y][x] == '0' || marker[y][x] != 0) { continue; }

        markAlias(marker, grid, x, y);
        ++landCount;
      }
    }
    return landCount;
  }

  void markAlias(vector<vector<int>>& marker, 
                 const vector<vector<char>>& grid, 
                 const int x, const int y) {

    if (!IS_IN_RANGE(y, 0, marker.size())) { return; }
    if (!IS_IN_RANGE(x, 0, marker[0].size())) { return; }
    if (grid[y][x] == '0' || marker[y][x] != 0) { return; }

    marker[y][x] = 1;
    markAlias(marker, grid, x + 1, y);
    markAlias(marker, grid, x - 1, y);
    markAlias(marker, grid, x, y + 1);
    markAlias(marker, grid, x, y - 1);
  }
};


#endif // NumberOfIslands_h__