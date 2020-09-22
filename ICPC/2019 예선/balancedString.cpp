// https://www.acmicpc.net/problem/17520

#include <iostream>

#define MOD 16769023

using namespace std;

long long traverse(long long zeroCnt, long long oneCnt){
    if(zeroCnt == 0 && oneCnt == 0){
        return 1;
    }

    long long ret = 0;

    if(zeroCnt == oneCnt){
        ret = traverse(zeroCnt - 1, oneCnt) % MOD;
        ret += ret;
    } else if(zeroCnt == oneCnt + 1){
        ret = traverse(zeroCnt - 1, oneCnt);
    } else if(zeroCnt + 1 == oneCnt){
        ret = traverse(zeroCnt, oneCnt - 1);
    }
    return ret % MOD;
}

int main(){
    int n;
    cin >> n;
    int ans = 0;
    if(n % 2 == 1){
        // odd case
        ans = traverse(n / 2, n / 2 + 1);
        ans += ans;
        ans = ans % MOD;
    } else {
        // even case
        ans = traverse(n / 2, n / 2);
    }
    cout << ans << endl;
    return 0;
}

