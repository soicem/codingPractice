#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
  std::unordered_map<std::string, int> variableIndex;
  std::vector<std::vector<double>> cacheTable;
  std::unordered_set<int> visited;

  std::vector<double> calcEquation(std::vector<std::vector<std::string>>& equations,
                                   std::vector<double>& values,
                                   std::vector<std::vector<std::string>>& queries) {
    createIndexMap(equations);
    initializeTable(equations, values);

    std::vector<double> answer;
    answer.reserve(queries.size());
    for (auto query : queries) {
      answer.push_back(queryResult(query));
    }
    return answer;
  }

  void createIndexMap(std::vector<std::vector<std::string>>& equations) {
    int i = 0;
    for (const auto& equation : equations) {
      for (const auto& variable : equation) {
        const auto isCreated = variableIndex.emplace(variable, i).second;
        if (isCreated) {
          ++i;
        }
      }
    }
  }

  void initializeTable(std::vector<std::vector<std::string>>& equations,
                       std::vector<double>& values) {
    cacheTable.resize(variableIndex.size(), std::vector<double>(variableIndex.size(), 0.0));

    for (auto i = 0; i < cacheTable.size(); ++i) {
      cacheTable[i][i] = 1.0;
    }

    for (auto i = 0; i < values.size(); ++i) {
      auto variable1 = equations[i][0];
      auto variable2 = equations[i][1];
      const auto variable1Index = variableIndex[variable1];
      const auto variable2Index = variableIndex[variable2];
      cacheTable[variable1Index][variable2Index] = values[i];
      cacheTable[variable2Index][variable1Index] = 1 / values[i];
    }
  }

  double queryResult(std::vector<std::string>& query) {
    const auto nominator = query[0];
    const auto denominator = query[1];

    if (!variableIndex.count(nominator) || !variableIndex.count(denominator)) {
      return -1.0;
    }

    auto result = dfs(variableIndex[nominator], variableIndex[denominator]);
    return result > 0 ? result : -1;
  }

  double dfs(int nominator, int denominator) {
    if (cacheTable[nominator][denominator] > 0.0) {
      return cacheTable[nominator][denominator];
    }

    visited.emplace(nominator);
    auto answer = 0.0;
    for (auto neighbor = 0; neighbor < cacheTable.size(); ++neighbor) {
      if (visited.count(neighbor)) { continue; }
      if (cacheTable[nominator][neighbor] == 0.0) { continue; }

      const auto result = dfs(neighbor, denominator);
      if (result > 0.0) {
        answer = cacheTable[nominator][neighbor] * result;
        cacheTable[nominator][denominator] = answer;
        cacheTable[denominator][nominator] = 1 / answer;
        break;
      }
    }
    visited.erase(nominator);
    return answer;
  }
};
