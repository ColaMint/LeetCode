#include <cstdio>

class Solution {
   public:
    int getMoneyAmount(int n) {
        int dp[500][500];
        for (int i = 0; i <= n; ++i) {
            dp[i][i] = 0;
        }
        for (int range = 1; range <= n; ++range) {
            for (int i = 0; i < n; ++i) {
                int j = i + range;
                if (j > n) {
                    break;
                }
                int min_cost = -1;
                for (int guess = i; guess <= j; ++guess) {
                    int left_cost = guess > i ? dp[i][guess - 1] : 0;
                    int right_cost = guess < j ? dp[guess + 1][j] : 0;
                    int cost = guess + (left_cost > right_cost ? left_cost
                                                               : right_cost);
                    if (min_cost == -1 || cost < min_cost) {
                        min_cost = cost;
                    }
                }
                dp[i][j] = min_cost;
            }
        }
        return dp[0][n];
    }
};

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", Solution().getMoneyAmount(n));
    return 0;
}
