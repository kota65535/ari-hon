#include <iostream>
#include <vector>


const int N = 4;
const int W = 5;

const int INF = 10000000;

struct Item {
    int w;
    int v;
};

Item items[] = {{2,3}, {1,2}, {3,4}, {2, 2}};


int main() {

    int max_v = std::max(items[0], items[N - 1], [](const Item &i1, const Item &i2) {
        return i1.v < i2.v;
    }).v;

    int dp[N+1][max_v*N+1];

    for (int i = 0 ; i <= N ; i++) {
        for (int j = 0 ; j <= max_v * N ; j++) {
            dp[0][j] = INF;
        }
    }

    dp[0][0] = 0;

    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < max_v * N ; j++) {
            dp[i+1][j] = std::min(dp[i][j], dp[i][j - items[i].v] + items[i].w);
            std::cout << i+1 << "," << j << " " << dp[i+1][j] << std::endl;
        }
    }

    int v_max_sum = 0;
    for (int j = 0 ; j < max_v * N ; j++) {
        if (dp[N][j] <= W && v_max_sum < j) {
            v_max_sum = j;
        }
    }

    std::cout << v_max_sum << std::endl;

    return 0;
}
