#pragma once

#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct TrieNode {
  char value;
  int count;
  std::unordered_map<char, TrieNode*> next;

  TrieNode() : TrieNode('\0') {
  }

  TrieNode(char value) : value(value), count(0) {
  }

  void addNext(char value) {
    if (next.count(value) == 0) {
      next[value] = new TrieNode(value);
    }
    ++next[value]->count;
  }

  void removeNext(char value) {
    if (hasNext(value)) {
      --next[value]->count;
    }
  }

  bool hasNext(char value) {
    return next.count(value) > 0 && next[value]->count > 0;
  }
};

class Trie {
public:
  void addWord(std::string& word) {
    auto* node = head;
    for (auto c : word) {
      node->addNext(c);
      node = node->next[c];
    }
  }

  void removeWord(std::string& word) {
    auto* node = head;
    for (auto c : word) {
      if (!node->hasNext(c)) { break; }
      node->removeNext(c);
      node = node->next[c];
    }
  }

  void print() {
    print(head);
    std::cout << "\n";
  }

  void print(TrieNode* node) {
    if (node == nullptr) { return; }
    std::cout << node->value << "[" << node->count << "]";
    for (auto kValue : node->next) {
      std::cout << " ";
      print(kValue.second);
    }
    std::cout << "|";
  }

  TrieNode* head = new TrieNode();
};


class Solution {
public:
  Trie trie;
  std::vector<std::string> answer;
  std::set<std::pair<int, int>> visited;

  std::vector<std::string> findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words) {
    for (auto& word : words) {
      trie.addWord(word);
    }

    for (int y = 0; y < board.size(); ++y) {
      for (int x = 0; x < board[0].size(); ++x) {
        auto c = board[y][x];
        if (!trie.head->hasNext(c)) { continue; }
        
        std::string candidate(1, c);
        recurse(board, x, y, trie.head->next[c], candidate);
      }
    }
    
    return answer;
  }

  const std::vector<std::vector<int>> DIRECTIONS = {
    {1, 0},
    {0, -1},
    {-1, 0},
    {0, 1}
  };

  void recurse(std::vector<std::vector<char>>& board, int x, int y, TrieNode* node, std::string& candidate) {
    if (node->next.empty()) {
      answer.push_back(candidate);
      trie.removeWord(candidate);
      return;
    }

    visited.insert({x, y});

    int countSum = 0;
    for (auto pair : node->next) {
      countSum += pair.second->count;
    }

    if (countSum < node->count) {
      answer.push_back(candidate);
      trie.removeWord(candidate);
    }

    for (auto dir : DIRECTIONS) {
      auto nextX = x + dir[0];
      auto nextY = y + dir[1];
      if (visited.count({nextX, nextY})) { continue; }
      if (nextX < 0 || nextX >= board[0].size()) { continue; }
      if (nextY < 0 || nextY >= board.size()) { continue; }
      
      auto nextC = board[nextY][nextX];
      if (!node->hasNext(nextC)) { continue; }

      candidate.push_back(nextC);
      recurse(board, nextX, nextY, node->next[nextC], candidate);
      candidate.pop_back();
    }
    
    visited.erase({x, y});
  }
};
