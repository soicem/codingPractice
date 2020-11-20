class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        
        unordered_map<char, int> umap;
        unordered_map<char, int> cmap;
        for(auto c : p){
            umap[c]++;
        }
        cmap = umap;
        
        int len = p.length();
        
        int left = 0, right = 0;
        
        while(right < s.length()){
            if(umap[s[right]] == 0) {
                left = right + 1;
                right = left;
                cmap = umap;
                continue;
            }
            
            if(cmap[s[right]] > 0){
                cmap[s[right]]--;
                right++;
            } else {
                cmap[s[left]]++;
                left++;
            }
            
            if(right - left == len){
                ans.push_back(left);
                cmap[s[left]]++;
                left++;
                continue;
            }
        }
        return ans;
    }
};
