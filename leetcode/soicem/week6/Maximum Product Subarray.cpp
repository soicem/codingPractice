class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        
        int result = nums[0];
        
        int mx = nums[0];
        int mn = nums[0];
        for(int i = 1; i < nums.size(); i++){
            int r1 = max(nums[i], max(mx * nums[i], mn * nums[i]));
            int r2 = min(nums[i], min(mx * nums[i], mn * nums[i]));
            mx = r1;
            mn = r2;
            
            result = max(mx, result);
        }
        return result;
    }
};
