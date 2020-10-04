class Solution {
public:
    vector<vector<int>> directions = {{0,1},{1,0},{-1,0},{0,-1}};
    
    int traverse(int y, int x, vector<vector<int>>& matrix, vector<vector<int>>& cache){
        int &ret = cache[y][x];
        
        if(ret != -1) return ret;
        int comp = 1;
        
        for(auto direction : directions){
            int nextY = y + direction[0];
            int nextX = x + direction[1];
            
            if(nextY < 0 || nextY >= matrix.size()) continue;
            if(nextX < 0 || nextX >= matrix[nextY].size()) continue;
            
            if(matrix[y][x] < matrix[nextY][nextX]){
                comp = max(comp, traverse(nextY, nextX, matrix, cache) + 1);
            }
        }
        ret = max(comp, 1);
        return ret;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty()) return 0;
        
        vector<vector<int>> cache(matrix.size(), vector<int>(matrix[0].size(), -1));
        int ans = 0;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(cache[i][j] != -1) continue;
                ans = max(ans, traverse(i, j, matrix, cache));
            }
        }
        return ans;
    }
};
