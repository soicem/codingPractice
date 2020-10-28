#pragma once

#include <string>
#include <vector>

std::vector<std::vector<char>> phonePad = {
    {},                 {'a','b','c'},  {'d','e','f'},
    {'g','h','i'},      {'j','k','l'},  {'m','n','o'},
    {'p','q','r','s'},  {'t','u','v'},  {'w','x','y','z'}
};

class Solution {
public:
  std::vector<std::string> letterCombinations(std::string digits) {
      std::vector<std::string> answer;
        if (digits.size() > 0) {
            getCombination(digits, 0, "", answer);
        }
        return answer;
    }
    
    void getCombination(std::string& digits, uint32_t index, std::string combination, std::vector<std::string>& answer) {
        
        if (index >= digits.size()) {
            answer.push_back(combination);
            return;
        }
        
        int number = digits[index] - '1';
        
        for (const char& digit : phonePad[number]) {
            combination.push_back(digit);
            getCombination(digits, index + 1, combination, answer);
            combination.pop_back();
        }
    }
};