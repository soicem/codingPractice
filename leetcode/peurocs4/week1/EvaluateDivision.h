#pragma once

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
  unordered_map<string, vector<pair<string, double>>> graph;

  vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    for (int i = 0; i < equations.size(); ++i) {
      auto& equation = equations[i];
      auto& numerator = equation[0];
      auto& denominator = equation[1];
      auto& value = values[i];

      graph[numerator].push_back({denominator, value});
      graph[denominator].push_back({numerator, 1 / value});
    }

    vector<double> answers;
    for (auto& query : queries) {
      double answer = runQuery(query);
      answers.push_back(answer);
    }
    return answers;
  }

  double runQuery(vector<string>& query) {
    auto& numerator = query[0];
    auto& denominator = query[1];

    if (numerator == denominator) {
      return (graph.count(numerator) != 0) ? (1) : (-1);
    }

    unordered_set<string> used {numerator};
    queue<pair<string, double>> q({{numerator, 1}});
    while (!q.empty()) {
      auto& top = q.front();
      auto& variable = top.first;
      auto& value = top.second;

      for (auto& next : graph[variable]) {
        auto& nextVariable = next.first;
        auto& nextValue = next.second;

        if (used.count(nextVariable) > 0) { continue; }
        if (nextVariable == denominator) {
          return value * nextValue;
        }

        used.insert(nextVariable);
        q.push({nextVariable, value * nextValue});
      }

      q.pop();
    }

    return -1;
  }
};
