// Question: given two arrays A[n], B[m]
// try to make a new array C, such that C[i] = A[i] or B[i]
// return the maximum length of such C that is non decreasing

int maxNonDecreasingLength(vector<int>& A, vector<int>& B) {
        int ans = 1, dp1 = 1, dp2 = 1, n = A.size();
        int t11, t12, t21, t22;
        for (int i = 1; i < n; i++) {
            t11 = (A[i-1] <= A[i]) ? dp1 + 1 : 1;
            t12 = (A[i-1] <= B[i]) ? dp1 + 1 : 1;
            t21 = (B[i-1] <= A[i]) ? dp2 + 1 : 1;
            t22 = (B[i-1] <= B[i]) ? dp2 + 1 : 1;
            dp1 = max(t11, t21);
            dp2 = max(t12, t22);
            ans = max(ans, max(dp1, dp2));
        }
        return ans;
    }
