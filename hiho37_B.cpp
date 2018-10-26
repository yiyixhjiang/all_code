#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
vector<pair<int, int>> A;
double area(double a)
{
    return 0.25 * a * a;
}
int main()
{
    int n;
    cin >> n;
    while(n --)
    {
        int x,y;
        cin >> x >>y;
        A.push_back(make_pair(x-y,y+x));
    }
    sort(A.begin(), A.end());
    int r = -100000;
    double ans = 0;
    for(int i = 0; i < A.size(); i ++)
    {
        if(A[i].second <= r)
            continue;
         ans += area(A[i].second - A[i].first);
        // cout << ans << endl;
        if(A[i].first < r)
            ans -= area(r - A[i].first);
        r = max(r, A[i].second);
    }
    //cout << ans << endl;
    printf("%.2f\n", ans);
    return 0;
}
