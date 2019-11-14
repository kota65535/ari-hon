#include <iostream>

const int N = 3;
const int a[] = {3, 5, 8};
const int m[] = {3, 2, 2};
const int K = 17;

int dp[N+1][K+1];

int main() {

    for (int i = 0 ; i < N + 1 ; i++) {
        for (int j = 0 ; j < K + 1 ; j++) {
            dp[i][j] = -1;
        }
    }

    for (int i = 0 ; i < N + 1 ; i++) {
        for (int j = 0 ; j < K + 1 ; j++) {
            for (int k = 0; k < m[i]; k++) {
                if (dp[i][j - k * a[i]] >= 0) {
                    dp[i + 1][j] = k;
                    break;
                }
            }
        }
    }

    std::cout << dp[N][K] << std::endl;

    return 0;
}
