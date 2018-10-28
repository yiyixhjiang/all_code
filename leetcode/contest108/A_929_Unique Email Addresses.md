- 邮件分为两部分 @之前和之后 给出一串邮件地址， 其中包含，+等额外的字符，出现在第一个@前的，：忽略，+之后到第一个@之间的忽略。
- 求地址中有多少个不同地址？

Input: ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
Output: 2
Explanation: "testemail@leetcode.com" and "testemail@lee.tcode.com" actually receive mails

```c++  
class Solution {
public: //思路：分两部分，前一部分处理后再拼接，insert到set即可
    string fun(string st1)
    {
        string temp="";
        for(auto x : st1)
        {
            if(x == '+')
                break;
            else if(x == '.')
                ;
            else temp += x;
        }
        return temp;
    }
    int numUniqueEmails(vector<string>& emails) {
        set<string> Set;
        for(auto x : emails)
        {
            string st1, st2;
            int index = 0;
            for(int i = 0; i < x.length(); i ++)
                if(x[i] == '@')
                {
                    st1.assign(x.begin(), x.begin()+i);
                    st2.assign(x.begin()+i+1, x.end());

                    string st = fun(st1) + st2;
                    cout << st << endl;
                    Set.insert(st);
                    break;
                }
        }
        return Set.size();
    }
};
```
