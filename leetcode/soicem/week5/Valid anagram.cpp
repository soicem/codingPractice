class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        
        unordered_map<char, int> umap;
        for(auto c : s){
            umap[c]++;
        }
        for(auto c : t){
            umap[c]--;
            if(umap[c] < 0) return false;
        }
        return true;
    }
};
