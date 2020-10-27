class Solution {
public:
    bool isStrobogrammatic(string num) {
        // 69, 88, 11, 0
        int left = 0;
        int right = num.length() - 1;
        
        while(left <= right){
            if(num[left] == '6' && num[right] == '9'){
                left++;
                right--;
            } else if(num[left] == '9' && num[right] == '6'){
                left++;
                right--;
            } else if(num[left] == '1' && num[right] == '1'){
                left++;
                right--;
            } else if(num[left] == '8' && num[right] == '8'){
                left++;
                right--;
            } else if(num[left] == '0' && num[right] == '0'){
                left++;
                right--;
            } else {
                return false;
            }
        }
        return true;
    }
};
