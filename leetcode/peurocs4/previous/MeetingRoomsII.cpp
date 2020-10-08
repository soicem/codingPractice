#ifndef MeetingRoomsII_h__
#define MeetingRoomsII_h__


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
  struct Comparator {
    bool operator()(const vector<int>& vector1, const vector<int>& vector2) {
      if (vector1[0] == vector2[0]) {
        return vector1[1] < vector2[1];
      }
      return vector1[0] < vector2[0];
    }
  };

  int minMeetingRooms(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), Comparator());
    //print(intervals);

    priority_queue<int, vector<int>, greater<>> pq;

    for (const auto& interval : intervals) {
      const auto& start = interval[0];
      const auto& end = interval[1];

      if (!pq.empty() && pq.top() <= start) {
        pq.pop();
      }
      pq.push(end);
    }

    return pq.size();
  }
};

void print(vector<vector<int>>& intervals) {
  for (const auto& item : intervals) {
    cout << item[0] << ", " << item[1] << endl;
  }
}


#endif // MeetingRoomsII_h__