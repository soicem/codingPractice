class Solution {
public:
    int traverse(vector<vector<int>>& stones, vector<int>& visited, int iStone){
        if(visited[iStone] == 1) return 0;
        visited[iStone] = 1;
            
        int ret = 1;
        int s = stones[iStone][0];
        int d = stones[iStone][1];
        
        for(int i = 0; i < stones.size(); i++){
            
            int nextS = stones[i][0];
            int nextD = stones[i][1];
            
            if(s == nextS || d == nextD){
                ret += traverse(stones, visited, i);
            }
        }
        return ret;
    }
    
    int removeStones(vector<vector<int>>& stones) {
        vector<int> visited(stones.size() + 1, 0);
        int ans = 0;
        for(int i = 0; i < stones.size(); i++){
            if(visited[i] == 1) continue;
            int ret = traverse(stones, visited, i);
            if(ret > 1){
                ret -= 1;
            } else {
                ret = 0;
            }
            ans += ret;
        }
        return ans;
    }
};
