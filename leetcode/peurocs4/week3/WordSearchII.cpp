#ifndef WordSearchII_h__
#define WordSearchII_h__


#include <vector>
#include <unordered_map>

using namespace std;

#define IN_RANGE(x, low, high) (low <= x && x < high)

struct TrieNode {
  char nodeChar;
  unordered_map<char, vector<TrieNode*>> nextChars;

  TrieNode() : TrieNode(' ') {}
  TrieNode(char nodeChar) : nodeChar(nodeChar) {}
};

class Trie {
public:
  TrieNode* root = new TrieNode();

  bool has(string& word) {
    return has(word, 0, root);
  }

  bool has(string& word, int at, TrieNode* node) {
    if (at >= word.size()) { return true; }

    auto& c = word[at];
    if (node->nextChars.count(c) == 0) {
      return false;
    }

    for (auto& nextNode : node->nextChars[c]) {
      if (has(word, at + 1, nextNode)) {
        return true;
      }
    }

    return false;
  }
};

pair<int, int> directions[4] {
  {1, 0},
  {0, 1},
  {-1, 0},
  {0, -1}
};

class Solution {
public:
  Trie trie;

  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    for (int y = 0; y < board.size(); ++y) {
      for (int x = 0; x < board[0].size(); ++x) {
        dfs(board, x, y, trie.root);
      }
    }

    vector<string> answer;
    for (auto& word : words) {
      if (trie.has(word)) {
        answer.push_back(word);
      }
    }
    return answer;
  }

  void dfs(vector<vector<char>>& board, int x, int y, TrieNode* node) {
    if (!IN_RANGE(y, 0, board.size())) { return; }
    if (!IN_RANGE(x, 0, board[0].size())) { return; }
    if (board[y][x] == '-') { return; } // if already used

    char currentChar = board[y][x];
    board[y][x] = '-'; // marked as used

    auto currentNode = new TrieNode(currentChar);
    if (node->nextChars.count(currentChar) == 0) {
      node->nextChars[currentChar] = {};
    }
    node->nextChars[currentChar].push_back(currentNode);

    for (auto& direction : directions) {
      dfs(board, x + direction.first, y + direction.second, currentNode);
    }

    board[y][x] = currentChar;
  }
};


#endif // WordSearchII_h__