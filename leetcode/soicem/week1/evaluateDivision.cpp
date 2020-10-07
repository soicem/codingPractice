class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> umap2d;
        int len = equations.size();
        for(int i = 0; i < len; i++){
            string start = equations[i][0];
            string end = equations[i][1];
            double value = values[i];
            
            umap2d[start][end] = value;
            umap2d[end][start] = 1 / value;
        }
        vector<double> ans;
        for(auto query : queries){
            double partialAns = -1.0;
            
            string start = query[0];
            string end = query[1];
            
            if(umap2d.count(start) == 0 || umap2d.count(end) == 0){
                ans.push_back(-1.0);
                continue;
            }
            
            if(start == end) {
                ans.push_back(1.0);
                continue;
            }
            
            string runner = start;
            
            unordered_map<string, int> visited;
            visited[start] = 1;
            
            queue<pair<string, double>> que;
            
            for(auto umap : umap2d[start]){ // starting points
                string next = umap.first;
                double value = umap.second;
                que.push(make_pair(next, value));
            }
            
            while(!que.empty()){ // bfs
                string current = que.front().first;
                double value = que.front().second;
                que.pop();
                
                if(current == end){
                    partialAns = value;
                    break;
                }
                
                visited[current] = 1;
                
                for(auto umap : umap2d[current]){
                    string next = umap.first;
                    double nextValue = umap.second;
                    
                    if(visited[next] == 0){
                        que.push(make_pair(next, value * nextValue));
                    }
                }
            }
            
            ans.push_back(partialAns);
        }
        
        
        return ans;
    }
};
