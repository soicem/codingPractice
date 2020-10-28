class Solution {
public:
    vector<string> ans;
    int v = -1;
    
    void gp(string s, int depth, int comp){
        if(depth == v){
            if(comp == 0)
                ans.push_back(s);
            return;
        }
        // left branket
        gp(s + "(", depth + 1, comp + 1);
        
        // right branket
        if(comp > 0) 
            gp(s + ")", depth + 1, comp - 1);
    }
    
    vector<string> generateParenthesis(int n) {
        v = n * 2;
        gp("(", 1, 1);
        return ans;
    }
};
