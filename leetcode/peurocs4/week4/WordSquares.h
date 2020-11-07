#pragma once
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

struct TrieNode {
  TrieNode* nexts[26];
  std::vector<std::string> words;

  void addNext(char c, std::string& word) {
    if (nexts[c - 'a'] == nullptr) {
      nexts[c - 'a'] = new TrieNode();
    }
    nexts[c - 'a']->words.push_back(word);
  }

  TrieNode* getNext(char c) {
    return nexts[c - 'a'];
  }

  bool hasNext(char c) {
    return nexts[c - 'a'] != nullptr;
  }
};

struct Trie {
  TrieNode* root = new TrieNode();

  void addWord(std::string& word) {
    root->words.push_back(word);

    TrieNode* node = root;
    for (auto c : word) {
      node->addNext(c, word);
      node = node->getNext(c);
    }
  }

  std::vector<std::string> getWordsWithPrefix(std::string& prefix) {
    TrieNode* node = root;
    for (auto c : prefix) {
      if (!node->hasNext(c)) {
        return {};
      }
      node = node->getNext(c);
    }
    return node->words;
  }
};

class Solution {
public:
  Trie trie;
  std::vector<std::string> board;
  std::vector<std::vector<std::string>> answer;

  std::vector<std::vector<std::string>> wordSquares(std::vector<std::string>& words) {
    for (auto& word : words) {
      trie.addWord(word);
    }

    recurse(words[0].size());

    return answer;
  }

  void recurse(int boardSize) {
    if (board.size() >= boardSize) {
      answer.emplace_back(std::vector<std::string>(board));
      return;
    }

    std::stringstream ss;
    for (int i = 0; i < board.size(); ++i) {
      ss << board[i][board.size()];
    }

    auto prefix = ss.str();
    for (auto& word : trie.getWordsWithPrefix(prefix)) {
      board.emplace_back(word);
      recurse(boardSize);
      board.pop_back();
    }
  }
};
