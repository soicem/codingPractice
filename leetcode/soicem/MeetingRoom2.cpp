class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ongoings;
        
        for(auto interval : intervals){
            int cStart = interval[0];
            int cEnd = interval[1];
            
            for(int i = 0; i < ongoings.size(); i++){
                int oStart = ongoings[i][0];
                int oEnd = ongoings[i][1];
                
                if(cStart >= oEnd){
                    ongoings[i][0] = cStart;
                    ongoings[i][1] = cEnd;
                    cStart = cEnd;
                    break;
                }
            }
            
            if(cStart != cEnd){
                ongoings.push_back({cStart, cEnd});
            }
        }
        return ongoings.size();
    }
};
