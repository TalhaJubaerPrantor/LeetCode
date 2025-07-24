#include<bits/stdc++.h>
using namespace std;

int value(char c)
{
    if(c='^')return 3;
    else if(c=='*' || c=='/') return 2;
    else if(c=='+' || c=='-') return 1;
    else return -1;
}

int main()
{

    string s="(a+b)*c";

    stack<char> stk;
    string result="";

    for(int i=0; i<s.size(); i++)
    {
        if( (s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') )
        {
            result+=s[i];
        }
        else if(s[i]=='(')stk.push('(');
        else if(s[i]==')')
        {
            while(stk.top()!='(')
            {
                result+=stk.top();
                stk.pop();
            }
            stk.pop();
            continue;
        }
        else if(!stk.empty())
        {
            if(value(stk.top())<=value(s[i]))
            {
                stk.push(s[i]);
            }
            else
            {
                result+=stk.top();
                stk.pop();
                stk.push(s[i]);
            }
        }
        else
        {
            stk.push(s[i]);
        }
    }

    while(!stk.empty())
    {
        result+=stk.top();
        stk.pop();
    }

    cout<<result<<endl;


    return 0;
}
