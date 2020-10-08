#ifndef RobotRoomCleaner_h__
#define RobotRoomCleaner_h__


#include <unordered_set>
#include <unordered_map>

using namespace std;

// This is the robot's control interface.
// You should not implement it, or speculate about its implementation
class Robot {
  public:
    // Returns true if the cell in front is open and robot moves into the cell.
    // Returns false if the cell in front is blocked and robot stays in the current cell.
    bool move();

    // Robot will stay in the same cell after calling turnLeft/turnRight.
    // Each turn will be 90 degrees.
    void turnLeft();
    void turnRight();

    // Clean the current cell.
    void clean();
};

struct PairHash {
  template<typename T, typename U>
  size_t operator()(const pair<T, U>& source) const {
    return source.first * 31 + source.second;
  }
};

struct PairHash {
  template<typename T, typename U>
  size_t operator()(const pair<T, U>& source) const {
    return source.first * 31 + source.second;
  }
};

class Solution {
public:
  unordered_set<pair<int, int>, PairHash> s;
  int direction = 0; //0:up, 1:left, 2:down, 3:right
  int directionXY[4][2] {
    {0, -1},  //up
    {-1, 0},  //left
    {0, 1},   //down
    {1, 0}    //right
  };

  void cleanRoom(Robot& robot) {
    recurse(robot, 0, 0);
  }

  void recurse(Robot& robot, int x, int y) {
    robot.clean();
    s.insert({x, y});

    cout << direction << ": " << x << ", " << y << endl;

    for (int i = 0; i < 4; ++i) {
      int newX = x + directionXY[direction][0];
      int newY = y + directionXY[direction][1];

      if (s.count(make_pair(newX, newY)) == 0 && robot.move()) {
        recurse(robot, newX, newY);
        robot.turnRight();
        direction = (direction + 3) % 4;
      }
      else {
        robot.turnLeft();
        direction = (direction + 1) % 4;
      }
    }

    robot.turnLeft();
    robot.turnLeft();
    direction = (direction + 2) % 4;
    robot.move();
  }
};


#endif // RobotRoomCleaner_h__