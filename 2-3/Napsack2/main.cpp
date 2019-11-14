#include <iostream>

const int N = 3;
const int W = 7;

struct Item {
    int w;
    int v;
};

Item items[] = {{3,4}, {4,5}, {2,3}};

int dp[N+1][W+1];

int main() {

    for (int j = 0 ; j <= W ; j++) {
        dp[0][j] = 0;
    }

    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j <= W ; j++) {
            if (items[i].w > j) {
                dp[i+1][j] = dp[i][j];
            } else {
                dp[i+1][j] = std::max(dp[i][j], dp[i+1][j - items[i].w] + items[i].v);
            }
            std::cout << i+1 << "," << j << " " << dp[i+1][j] << std::endl;
        }
    }

    int max = std::max(dp[N][0], dp[N][W]);

    std::cout << max << std::endl;

    return 0;
}