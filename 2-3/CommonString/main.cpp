#include <iostream>

const int N = 4;
const int M = 4;
const std::string s = "abcd";
const std::string t = "becd";

int dp[N+1][M+1];

int main() {

    dp[0][0] = 0;
    for (int i = 0 ; i <= N ; i++) {
        for (int j = 0 ; j <= M ; j++) {
            if (s[i] == t[j]) {
                dp[i+1][j+1] = dp[i][j] + 1;
            } else {
                dp[i+1][j+1] = std::max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }

    std::cout << dp[N][M] << std::endl;
    return 0;
}