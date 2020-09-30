#ifndef MinimumCostToHireKWorkers_h__
#define MinimumCostToHireKWorkers_h__


#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

class Solution {
public:
  struct Worker {
    int quality;
    double rate;

    Worker(int quality, double rate) 
      :quality(quality), rate(rate) {}
  };

  struct RateComparator {
    bool operator()(const Worker& worker1, const Worker& worker2) const {
      return worker1.rate < worker2.rate;
    }
  };

  double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
    vector<Worker> workers;
    for (int i = 0; i < quality.size(); ++i) {
      const auto& q = quality[i];
      const auto& w = wage[i];
      const auto r = static_cast<double>(w) / q;
      workers.push_back(*new Worker(q, r));
    }

    sort(workers.begin(), workers.end(), RateComparator());

    double minCost = DBL_MAX;
    priority_queue<int> pq;
    int accumQuality = 0;
    for (const auto& worker : workers) {
      accumQuality += worker.quality;
      pq.push(worker.quality);

      if (pq.size() > K) {
        accumQuality -= pq.top();
        pq.pop();
      }
      if (pq.size() == K) {
        const double cost = accumQuality * worker.rate;
        minCost = min(minCost, cost);
      }
    }
    
    return minCost;
  }
};


#endif // MinimumCostToHireKWorkers_h__