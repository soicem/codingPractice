class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> edges(numCourses);
        
        for(auto prerequisite : prerequisites){
            int pre = prerequisite[1];
            int cur = prerequisite[0];
            indegree[cur]++;
            edges[pre].push_back(cur);
        }
        
        queue<int> que;
        
        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0){
                que.push(i);
                numCourses--;
            }
        }
        
        while(!que.empty()){
            int node = que.front();
            que.pop();
            for(auto next : edges[node]){
                indegree[next]--;
   
                if(indegree[next] == 0){
                    que.push(next);
                    numCourses--;
                } else if(indegree[next] < 0){
                    return false;
                }
            }
        }
        
        if(numCourses != 0){
            return false;
        }
        return true;
    }
};
