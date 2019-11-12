#include <iostream>
#include <algorithm>
#include <numeric>

int N = 3;
int L[] = {8, 5, 8};


int main() {

    int sum = std::accumulate(L, L + N, 0);
    std::sort(L, L + N, std::greater<>());

    int total_cost = 0;
    int cost = sum;
    for (int i = 0 ; i < N - 1 ; i++) {
        total_cost += cost;
        cost = sum - L[i];
    }

    std::cout << total_cost;

    return 0;
}