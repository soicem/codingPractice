class Solution {
public:
    vector<string> ans;
    int len;
    void traverse(int n, string prepend, string append){
        if(n == 0){
            ans.push_back(prepend + append);
            return;
        }
        
        if(n == 1){
            traverse(n - 1, prepend + "1", append);
            traverse(n - 1, prepend + "8", append);
            traverse(n - 1, prepend + "0", append);
            return;
        }
        
        traverse(n - 2, prepend + "1", "1" + append);
        traverse(n - 2, prepend + "8", "8"+ append);
        traverse(n - 2, prepend + "6", "9" + append);
        traverse(n - 2, prepend + "9", "6" + append);
        if(n != len)
            traverse(n - 2, prepend + "0", "0" + append);
        return;
    }    

    vector<string> findStrobogrammatic(int n) {
        len = n;
        traverse(n, "", "");
        return ans;
    }
};
