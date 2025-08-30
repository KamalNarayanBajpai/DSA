/*
* Problem Link: https://www.codingninjas.com/codestudio/problems/boolean-expression-to-be-true_975474
* Platform: Coding Ninjas
* Difficulty: Hard
* Topic: Dynamic Programming, Recursion with Memoization
*/
/* 
    Time Complexity: O(N^3) 
    Space Complexity: O(N^2) for the dp array + O(N) for the recursion stack
    Where N is the length of the string s.

*/
/* describe problem here
Given a boolean expression in the form of a string consisting of the characters 'T' (true), 'F' (false), '&' (AND), '|' (OR), and '^' (XOR), count the number of ways to parenthesize the expression such that it evaluates to true.
The result should be returned modulo 1003.
*/
class Solution {
public:
    // Recursive helper function with memoization
    int rec(string &s, int i, int j, bool isTrue, vector<vector<vector<int>>>& dp) {
        if (i > j) return 0;  // No expression, no valid evaluation
        if (i == j) {  // Base case: single character (either 'T' or 'F')
            return (isTrue == 1) ? (s[i] == 'T') : (s[i] == 'F');
        }

        // If the result is already calculated, return it
        if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

        int ways = 0;
        // Loop through the expression, considering each operator
        for (int k = i + 1; k < j; k += 2) {
            int leftTrue = rec(s, i, k - 1, 1, dp);  // Left side evaluates to True
            int leftFalse = rec(s, i, k - 1, 0, dp); // Left side evaluates to False
            int rightTrue = rec(s, k + 1, j, 1, dp); // Right side evaluates to True
            int rightFalse = rec(s, k + 1, j, 0, dp); // Right side evaluates to False

            char op = s[k];  // Operator at position k
            if (op == '&') {
                if (isTrue) ways += leftTrue * rightTrue;  // True only when both sides are True
                else ways += leftTrue * rightFalse + leftFalse * rightFalse + leftFalse * rightTrue;
            } else if (op == '|') {
                if (isTrue) ways += leftTrue * rightTrue + leftTrue * rightFalse + leftFalse * rightTrue;
                else ways += leftFalse * rightFalse;  // False only when both sides are False
            } else if (op == '^') {
                if (isTrue) ways += leftTrue * rightFalse + leftFalse * rightTrue;
                else ways += leftTrue * rightTrue + leftFalse * rightFalse;
            }
        }

        // Memoize the result
        dp[i][j][isTrue] = ways;
        return ways;
    }

    int countWays(string &s) {
        int n = s.size();
        // Initialize a 3D dp array where dp[i][j][isTrue] will store the number of ways
        // the substring from i to j can evaluate to True (if isTrue=1) or False (if isTrue=0)
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));

        // We want the entire expression from index 0 to n-1 to evaluate to True
        return rec(s, 0, n - 1, 1, dp);
    }
};
