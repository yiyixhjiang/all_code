For some fixed N, an array A is beautiful if it is a permutation of the integers 1, 2, ..., N, such that:

For every i < j, there is no k with i < k < j such that A[k] * 2 = A[i] + A[j].

Given N, return any beautiful array A.  (It is guaranteed that one exists.)

Example 1:

Input: 4
Output: [2,1,4,3]
Example 2:

Input: 5
Output: [3,1,2,5,4]

```c++
class Solution {
public: //不知道怎么搞的 第一名的思路
    vector<int> beautifulArray(int N) {
        if(N == 1) return {1};
        else
        {
            vector<int> v1 = beautifulArray(N/2);
            vector<int> v2 = beautifulArray(N-N/2);
            for(int i = 0; i < v1.size(); i ++)
                v1[i] = v1[i] * 2;
            for(int i = 0; i < v2.size(); i ++)
                v2[i] = v2[i] * 2 - 1;
            v1.insert(v1.end(), v2.begin(), v2.end());
            return v1;
        }
    }
};
```
