#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize < 2) {
        return 0;
    }
    int bestForBuy[pricesSize];
    for (int buy = 0; buy < pricesSize; buy++) {
        bestForBuy[buy] = 0;
        for (int sell = buy + 1; sell < pricesSize; sell++) {
            int profit = prices[sell] - prices[buy];
            if (profit > bestForBuy[buy]) {
                bestForBuy[buy] = profit;
            }
        }
    }
    int maxProfitFound = 0;
    for (int i = 0; i < pricesSize; i++) {
        if (bestForBuy[i] > maxProfitFound) {
            maxProfitFound = bestForBuy[i];
        }
    }
    return maxProfitFound;
}

int main(void) {
    int prices1[] = {7, 1, 5, 3, 6, 4};
    int prices2[] = {7, 6, 4, 3, 1};
    int edgeCase[] = {5};
    int newTest[] = {2, 4, 1};

    int n1 = (int)(sizeof(prices1) / sizeof(prices1[0]));
    int n2 = (int)(sizeof(prices2) / sizeof(prices2[0]));
    int n3 = (int)(sizeof(edgeCase) / sizeof(edgeCase[0]));
    int n4 = (int)(sizeof(newTest) / sizeof(newTest[0]));

    printf("Test 1: %d\n", maxProfit(prices1, n1));
    printf("Test 2: %d\n", maxProfit(prices2, n2));
    printf("Test 3: %d\n", maxProfit(edgeCase, n3));
    printf("Test 4: %d\n", maxProfit(newTest, n4));
    return 0;
}
