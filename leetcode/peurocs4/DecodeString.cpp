#ifndef DecodeString_h__
#define DecodeString_h__


#include <vector>
#include <unordered_map>
#include <cstring>
#include <sstream>

using namespace std;

class Solution {
public:
  unordered_map<int, int> repeatRanges;

  string decodeString(string s) {
    repeatRanges = *new unordered_map<int, int>();
    vector<int> repeats;

    for (int i = 0; i < s.size(); ++i) {
    	const auto& item = s[i];
      if (item == '[') {
        repeats.push_back(i);
      }
      else if (item == ']') {
        int openAt = repeats.back();
        repeatRanges[openAt] = i;
        repeats.pop_back();
      }
    }

    return recurse(s, 0, s.size());
  }

  string recurse(string& str, int left, int right) {
    if (left >= right) { return ""; }

    stringstream ss;
    string numberString;
    for (int i = left; i < right; ++i) {
      const auto& iChar = str[i];
      if (isalpha(iChar)) {
        ss << iChar;
      }
      else if (isdigit(iChar)) {
        numberString += iChar;
      }
      else if (iChar == '[') {
        int repeatAmount = stoi(numberSs);
        for (int j = 0; j < repeatAmount; ++j) {
          ss << recurse(str, i + 1, repeatRanges[i]);
        }
        numberString = "";
        i = repeatRanges[i];
      }
    }
    return ss.str();
  }
};


#endif // DecodeString_h__