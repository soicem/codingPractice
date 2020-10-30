class Solution {
public:
    vector<string> output;
    map<string, int> m;
    set<string> visited;
    
    vector<vector<int>> directions = {{0,1}, {1,0}, {-1,0}, {0, -1}};
    
    void traverse(vector<vector<char>>& board, int y, int x, string partialAns){
        if(m[partialAns] == -1){
            if(visited.find(partialAns) == visited.end()){
                output.push_back(partialAns);
                visited.insert(partialAns);        
            }
        }
        
        for(int i = 0; i < directions.size(); i++){
            int nextY = y + directions[i][0];
            int nextX = x + directions[i][1];
            
            if(nextY < 0 || nextY >= board.size() || nextX < 0 || nextX >= board[0].size()){
                continue;
            }
            
            if(m[partialAns + board[nextY][nextX]] != 0){
                char c= board[nextY][nextX];
                board[nextY][nextX] -= 30;
                traverse(board, nextY, nextX, partialAns + c);    
                board[nextY][nextX] += 30;
            }
        }
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        for(auto word: words){
            string sub = "";
            for(int i = 0; i < word.size() - 1; i++){
                sub += word[i];
                m[sub] = 1;
            }
            
        }
        for(auto word: words)
            m[word] = -1;
        
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                string s(1, board[i][j]);
                if(m[s] != 0){
                    board[i][j] -= 30;
                    traverse(board, i, j, s);
                    board[i][j] += 30;
                }
                    
            }   
        }
        return output;
    }
};
