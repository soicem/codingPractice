class Solution {
public:
    bool isExpressiveWord(string s, string word){        
        int sIdx = 0, wIdx = 0;
        
        while(sIdx < s.length() && wIdx < word.length()){
            int wCnt = 1;
            while(wIdx + 1 < word.length() && word[wIdx] == word[wIdx + 1]) {
                wIdx++;
                wCnt++;
            }
            
            if(s[sIdx] != word[wIdx]) return false;
            
            int sCnt = 1;
            while(sIdx + 1 < s.length() && s[sIdx] == s[sIdx + 1]) {
                sIdx++;
                sCnt++;
            }
            
            if(sCnt < wCnt) return false;
            if(sCnt != wCnt && sCnt < 3) return false;
            
            sIdx++;
            wIdx++;
        }
        
        if(sIdx < s.length() || wIdx < word.length()) return false;
        
        return true;
    }
    
    int expressiveWords(string S, vector<string>& words) {
        int ans = 0;
        for(auto word : words){
            if(isExpressiveWord(S, word)){
                ans++;
            }
        }    
        return ans;
    }
};
