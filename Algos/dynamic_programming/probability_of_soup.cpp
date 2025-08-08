#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, unordered_map<int, double>> dp;

    double emptySoup(int a, int b) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1.0;
        if (b <= 0) return 0.0;
        if (dp[a][b]) return dp[a][b];

        double operationA = emptySoup(a - 4, b);
        double operationB = emptySoup(a - 3, b - 1);
        double operationC = emptySoup(a - 2, b - 2);
        double operationD = emptySoup(a - 1, b - 3);

        dp[a][b] = 0.25 * (operationA + operationB + operationC + operationD);
        return dp[a][b];
    }

    double soupServings(int n) {
        if (n >= 4800) return 1.0; // Optimization threshold
        int units = ceil(n / 25.0);
        return emptySoup(units, units);
    }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter amount of soup (ml): ";
    cin >> n;

    double result = sol.soupServings(n);
    cout << fixed << setprecision(6);
    cout << "Probability that soup A becomes empty first: " << result << endl;

    return 0;
}
