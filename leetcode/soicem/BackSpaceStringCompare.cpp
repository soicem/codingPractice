class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> stkChar1;
        stack<char> stkChar2;
        
        for(int i = 0; i < S.length(); i++){
            if(S[i] == '#'){
                
                if(!stkChar1.empty())
                    stkChar1.pop();
                continue;
            }
            stkChar1.push(S[i]);
        }
        for(int i = 0; i < T.length(); i++){
            if(T[i] == '#'){
                if(!stkChar2.empty())
                    stkChar2.pop();
                continue;
            }
            stkChar2.push(T[i]);
        }
        
        if(stkChar2.size() != stkChar1.size()) return false;
        
        while(!stkChar2.empty()){
            char c1 = stkChar1.top();
            char c2 = stkChar2.top();
            
            stkChar1.pop();
            stkChar2.pop();
            
            if(c1 != c2) return false;
        }
        return true;
    }
};
