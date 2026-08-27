class Solution {
private:
    int solve(int i, string& s, vector<int>& memo) {
        if (i == s.length()) return 1;
        if (s[i] == '0') return 0;
        if (memo[i] != -1) return memo[i];
        int ways = solve(i + 1, s, memo);
        if (i + 1 < s.length()) {
            int twoDigitVal = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if (twoDigitVal >= 10 && twoDigitVal <= 26) {
                ways += solve(i + 2, s, memo);
            }
        }
        return memo[i] = ways;
    }

public:
    int numDecodings(string s) {
        int n = s.length();
        if (n == 0) return 0;
        vector<int> memo(n, -1);
        return solve(0, s, memo);
    }
};