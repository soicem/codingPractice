class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        
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
                ans.push_back(i);
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
                    ans.push_back(next);
                    numCourses--;
                } else if(indegree[next] < 0){
                    return {};
                }
            }
        }
        
        if(numCourses != 0){
            return {};
        }
        return ans;        
    }
};
