#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Recursive function with memoization to find length of LCS ending at i and j
int lcsHelper(const string &s1, const string &s2, int i, int j, int &maxLen,
              int &endIndex, vector<vector<int>> &dp) {
    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i] == s2[j]) {
        dp[i][j] = 1 + lcsHelper(s1, s2, i - 1, j - 1, maxLen, endIndex, dp);
        if (dp[i][j] > maxLen) {
            maxLen = dp[i][j];
            endIndex = i; 
        }
    } 
    else {
        dp[i][j] = 0;
        // Note: Don't explore other branches because LCS must be contiguous
    }

    // Still explore previous indices to continue recursion
    lcsHelper(s1, s2, i - 1, j, maxLen, endIndex, dp);
    lcsHelper(s1, s2, i, j - 1, maxLen, endIndex, dp);

    return dp[i][j];
}

string lcs(string s1, string s2) {
    int m = s1.size(), n = s2.size();
    int maxLen = 0, endIndex = -1;

    vector<vector<int>> dp(m, vector<int>(n, -1));

    lcsHelper(s1, s2, m - 1, n - 1, maxLen, endIndex, dp);

    if (maxLen == 0)
        return "";

    return s1.substr(endIndex - maxLen + 1, maxLen);
}

int main() {
    string s1 = "abcdfgh";
    string s2 = "zbcdfq";

    string lcs = longestCommonSubstring(s1, s2);
    cout << "Longest Common Substring: " << lcs << endl;

    return 0;
}

//TC: O(mn)
