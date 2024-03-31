#include<stdio.h>

int maxProfit(int* prices, int pricesize){
    int res = 0;
    int right = prices[pricesize-1];
    for(int i=pricesize-1; i>=0; i--){
        right = right > prices[i] ? right : prices[i];
        res = (right-prices[i]) > res ? (right-prices[i]) : res;
    }
    return res;
}

int main(void){
    
    return 0;
}