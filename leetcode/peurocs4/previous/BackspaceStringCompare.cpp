#ifndef BackspaceStringCompare_h__
#define BackspaceStringCompare_h__


#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  bool backspaceCompare(string S, string T) {
    int iS = S.size() - 1;
    int iT = T.size() - 1;

    int skipS = 0;
    int skipT = 0;
    while (true) {
      if (iS >= 0 && S[iS] == '#') {
        ++skipS;
        --iS;
      } 
      else if (skipS > 0) {
        --skipS;
        --iS;
      }
      else if (iT >= 0 &&T[iT] == '#') {
        ++skipT;
        --iT;
      }
      else if (skipT > 0) {
        --skipT;
        --iT;
      }
      else if (iS < 0 && iT < 0) {
        break;
      }
      else if (iS < 0 || iT < 0 || (S[iS] != T[iT])) {
        return false;
      }
      else {
        --iS;
        --iT;
      }
    }

    return true;
  }
};


#endif // BackspaceStringCompare_h__