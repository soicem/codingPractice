#ifndef MostStonesRemovedWithSameRowOrColumn_h__
#define MostStonesRemovedWithSameRowOrColumn_h__


#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

#define Stone vector<int>

struct VectorHash {
  template<typename T>
  size_t operator()(const vector<T>& v) const {
    size_t hashValue = 0;
    for (int i = 0; i < v.size(); ++i) {
      auto& item = v[i];
      hashValue += (hash<T>()(item) * (i + 1)) << i;
    }
    return hashValue;
  }
};

class Solution {
public:
  unordered_map<int, vector<Stone>> rowMap;
  unordered_map<int, vector<Stone>> colMap;

  int removeStones(vector<Stone>& stones) {
    for (auto& stone : stones) {
      auto& row = stone[0];
      auto& col = stone[1];

      rowMap[row].push_back(stone);
      colMap[col].push_back(stone);
    }

    int answer = 0;
    int removed = 0;
    unordered_set<Stone, VectorHash> used;

    for (auto& stone : stones) {
      if (used.count(stone) != 0) { continue; }

      removed += dfs(stone, used);
    }

    answer = max(answer, removed);
    return answer;
  }

  int dfs(Stone& stone, unordered_set<Stone, VectorHash>& used) {
    auto& row = stone[0];
    auto& col = stone[1];
    
    used.insert(stone);

    int depth = 0;
    for (auto& next : rowMap[row]) {
      if (used.count(next) != 0) { continue; }

      depth += dfs(next, used) + 1;
    }

    for (auto& next : colMap[col]) {
      if (used.count(next) != 0) { continue; }

      depth += dfs(next, used) + 1;
    }

    return depth;
  }
};


#endif // MostStonesRemovedWithSameRowOrColumn_h__