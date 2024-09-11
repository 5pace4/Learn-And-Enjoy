class Solution {
public:
    long long inf = 100000;
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int dp[amount+1];
        dp[0] = 0;
        for(int i = 1; i < amount+1; i++) dp[i] = inf;
        for(int i = 1; i < amount + 1; i++) {
            for(auto coin:coins) {
                if(coin <= i) dp[i] = min(dp[i], dp[i-coin] + 1);
            }
        }
        if(dp[amount] == inf) return -1;
        else return dp[amount];
    }
};

// Problemt link: https://leetcode.com/problems/coin-change/description/
