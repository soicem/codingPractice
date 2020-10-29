class Solution {
public:
    string ds;
    map<char, vector<char>> m;
    vector<string> ans;
    void lc(string synDigits, int digitIdx){
        if(ds.size() == digitIdx){
            ans.push_back(synDigits);
            return;
        }
        for(auto v : m[ds[digitIdx]]){
            lc(synDigits + v, digitIdx + 1);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return ans;
        ds = digits;
        m['2'] = {'a', 'b', 'c'};
        m['3'] = {'d', 'e', 'f'};
        m['4'] = {'g', 'h', 'i'};
        m['5'] = {'j', 'k', 'l'};
        m['6'] = {'m', 'n', 'o'};
        m['7'] = {'p', 'q', 'r', 's'};
        m['8'] = {'t', 'u', 'v'};
        m['9'] = {'w', 'x', 'y', 'z'};
        lc("", 0);
        return ans;
    }
};
