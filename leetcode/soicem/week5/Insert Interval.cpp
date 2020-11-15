class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        int newStart = newInterval[0];
        int newEnd = newInterval[1];
        
        vector<vector<int>> ans;
        
        while(i < intervals.size()){
            int currentStart = intervals[i][0];
            int currentEnd = intervals[i][1];
            
            if(newStart > currentEnd){
                ans.push_back(intervals[i]);
                i++;
            } else {
                break;
            }
        }
        
        while(i < intervals.size()){
            int currentStart = intervals[i][0];
            int currentEnd = intervals[i][1];
            
            if(newEnd < currentStart){
                break;
            } else {
                newStart = min(newStart, currentStart);
                newEnd = max(newEnd, currentEnd);
                i++;
            }
        }
        ans.push_back({newStart, newEnd});
        
        while(i < intervals.size()){
            ans.push_back(intervals[i]);
            i++;
        }
        
        return ans;
    }
};
