#define MAX 0x7fffffff

// First solution by myself, but is is too slow
class Solution {
public:
    
    int ans = MAX;
    int traverse(vector<vector<int>> & cache, vector<int>& coins, int amount, int pos){
        if(amount == 0){
            return 0;
        }
        
        if(pos >= coins.size()) return MAX;
        if(amount < 0) return MAX;
        
        int & ret = cache[amount][pos];
        if(ret != -1){
            return ret;
        }
        
        ret = MAX;
        
        int i = 0;
        while(amount - i * coins[pos] >= 0){
            int res = traverse(cache, coins, amount - i * coins[pos], pos + 1);            
            if(res == MAX) {
                i++;
                continue;
            }
            
            ret = min(ret,  res + i);
            i++;
        }
        return ret;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> cache(10001, vector<int>(13, -1));
        sort(coins.begin(), coins.end());
        ans = traverse(cache, coins, amount, 0);
        if(ans == MAX) return -1;
        return ans;
    }
};
