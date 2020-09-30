class Solution {
public:
    int repl(int index, string S, string src, string dst, string & ans){
        for(int i = 0; i < src.size(); i++){
            if(i == S.length()) {
                ans += S[index];
                return 1;
            }
            
            if(S[index + i] != src[i]){
                ans += S[index];
                return 1;
            }
        }
        ans += dst;
        return src.size();
    }
    
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        string ans = "";
        
        vector<vector<int>> ist;
        for(int i = 0; i < indexes.size(); i++){
            ist.push_back({indexes[i], i});
        }
        sort(ist.begin(), ist.end());
        
        int base = 0;
                          
                          
        for(int i = 0; i < ist.size(); i++){
            int index = ist[i][0];
            int pos = ist[i][1];
            
            while(base < index){
                ans += S[base++];
            }
            
            string source = sources[pos];
            string target = targets[pos];
            
            int len = repl(index, S, source, target, ans);
            base += len;
        }
        
        while(base < S.length()) ans += S[base++];
        
        return ans;
    }
};
