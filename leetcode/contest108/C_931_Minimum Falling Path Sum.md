- Given a square array of integers A, we want the minimum sum of a falling path through A.
- 给出一个矩阵，从上到下，上下两个元素行数偏差不大于1，求从上到下的最小sum

Input: 

[[1,2,3],

[4,5,6],

[7,8,9]]
Output: 12
Explanation: 
The possible falling paths are:

[1,4,7], [1,4,8], [1,5,7], [1,5,8], [1,5,9]

[2,4,7], [2,4,8], [2,5,7], [2,5,8], [2,5,9], [2,6,8], [2,6,9]

[3,5,7], [3,5,8], [3,5,9], [3,6,8], [3,6,9]

The falling path with the smallest sum is [1,4,7], so the answer is 12.

1 <= A.length == A[0].length <= 100
-100 <= A[i][j] <= 100

```c++
class Solution {
public: //思路类似三角形的那种 先从底层预处理在慢慢向上层递进
    int minFallingPathSum(vector<vector<int>>& A) {
        if(A.empty()) return 0;
        int len1 = A.size(), len2 = A[0].size();
        int dp[len1][len2] = {0};
        for(int i = len1-1; i >= 0; i --)
            for(int j = 0; j < len2; j ++)
            {
                if(i == len1-1) 
                    dp[i][j] = A[i][j];
                else 
                    dp[i][j] =A[i][j] + min(dp[i+1][j], min(j > 0 ? dp[i+1][j-1] : INT_MAX, j < len2-1 ? dp[i+1][j+1] : INT_MAX));
            }
        int ans = dp[0][0];
        for(int i = 1; i < len2; i ++) ans = min(ans, dp[0][i]);
        return ans;
    }
};
```
