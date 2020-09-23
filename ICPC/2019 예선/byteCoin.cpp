// Byte Coin: https://www.acmicpc.net/problem/17521

#include <cstdio>

using namespace std;

long long coins, cash;

void sell(long long price){
    cash += coins * price;
    coins = 0;
}

void buy(long long price){
    coins += cash / price;
    cash = cash % price;
}

int main(int argc, const char * argv[]) {
    int n;
    long long W;
    scanf("%d %lld", &n, &W);
    
    cash = W;
    coins = 0;
    //printf("cash: %lld\n", cash);
    int arr[n + 1];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    arr[n] = 0;
    
    for(int i = 0; i < n; i++){
        if(arr[i] < arr[i + 1]){
            buy(arr[i]);
        } else if(arr[i] > arr[i + 1]){
            sell(arr[i]);
        }
    }
    printf("%lld\n", cash);
    return 0;
}
