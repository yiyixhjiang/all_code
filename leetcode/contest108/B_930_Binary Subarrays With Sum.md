- 题意：In an array A of 0s and 1s, how many non-empty subarrays have sum S?
- 只含有0,1的串，求其中连续子串和为S的个数。

Input: A = [1,0,1,0,1], S = 2
Output: 4
Explanation: 
The 4 subarrays are bolded below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]

A.length <= 30000
0 <= S <= A.length

```c++
class Solution {
public: // 当前的前缀和t减去S后的数 为前缀和出现的次数 + ans, 返回 
    int numSubarraysWithSum(vector<int>& A, int S) {
        unordered_map<int, int> c;
        int ans = 0, t = 0;
        c[0] ++; // 前缀为0有一种 
        for(int x : A)
        {
            t += x;
            ans += c[t - S];
            c[t] ++;
        }
        return ans;
    }
};
```
