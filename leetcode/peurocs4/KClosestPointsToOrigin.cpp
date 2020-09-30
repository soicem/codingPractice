#ifndef KClosestPointsToOrigin_h__
#define KClosestPointsToOrigin_h__


#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
  struct Comparator {
    bool operator()(const pair<int, int>& pair1, const pair<int, int>& pair2) const {
      double distance1 = sqrt((pair1.first * pair1.first) + (pair1.second * pair1.second));
      double distance2 = sqrt((pair2.first * pair2.first) + (pair2.second * pair2.second));
      return distance1 < distance2;
    }
  };

  vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    priority_queue<pair<int, int>, vector<pair<int,int>>, Comparator> pq;
    for (const auto& point : points) {
      pq.push(make_pair(point[0], point[1]));

      if (pq.size() > K) {
        pq.pop();
      }
    }

    vector<vector<int>> answer;
    while (!pq.empty()) {
      const auto& top = pq.top();
      const auto& x = top.first;
      const auto& y = top.second;
      answer.push_back({x, y});
      pq.pop();
    }

    return answer;
  }
};


#endif // KClosestPointsToOrigin_h__