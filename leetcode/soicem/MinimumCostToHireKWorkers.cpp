class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        double ans = 0x7fffffff;
        int len = quality.size();
        
        vector<vector<double>> workers;
        
        for(int i = 0; i < len; i++){
            workers.push_back({(double)wage[i]/quality[i], (double)quality[i], (double)wage[i]});
        }
        sort(workers.begin(), workers.end());
        
        priority_queue<int> pq;
        int sumQ = 0.0;
        for(auto worker : workers){
            double ratio = worker[0];
            int q = worker[1];
            int w = worker[2];
            
            sumQ += q;
            pq.push(q);
            
            if(pq.size() > K){
                sumQ -= pq.top();
                pq.pop();
            }
            
            if(pq.size() == K){
                ans = min(ans, sumQ * ratio);
            }
        }
        
        return ans;
    }
};
