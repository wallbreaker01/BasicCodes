#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int prec(char c)
{
    if(c=='^') return 3;
    else if(c=='*' || c=='/') return 2;
     else if(c=='+' || c=='-') return 1;
    else return -1;
}

string infixTOpostfix(string s)
{
    reverse(s.begin(),s.end());
    stack<char>st;
    string res="";
    for (ll i = 0 ; i < s.size() ; i++) 
    {
        if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z') res=res+s[i]; //oparend hole result e add hobe
        else if(s[i]==')') st.push(s[i]);
        else if(s[i]=='(')
        {
            while(!st.empty() && st.top()!=')')
            {
                res=res+st.top();
                st.pop();
            }
            if(!st.empty()) st.pop();
        }
        else //operator er jonno
        {
            while(!st.empty() && prec(st.top()) >= prec(s[i])) //top jodi prec theke boro hoy taile age top clear hobe then push hobe
            {
                res=res+st.top();
                st.pop();
            }
            st.push(s[i]); //top boro na hoile direct push
        }
    }
    while(!st.empty())
    {
        res=res+st.top();
        st.pop();
    }
    reverse(res.begin(),res.end());
    return res;
}

//(a-b/c)*(a/k-l) 

int main()
{
    cout<<infixTOpostfix("(a-b/c)*(a/k-l)");
       
}