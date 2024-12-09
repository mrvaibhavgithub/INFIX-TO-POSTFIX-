#include<iostream>
#include<stack>
using namespace std;

int precedence(char c)
{
    if(c=='+'||c=='-')
    {
        return 1;
        
    }
    if(c=='*'||c=='/')
    {
        return 2;
        
    }
    if(c=='^')
    {
        return 3;
        
    }
    return 0;
}
bool isoperator(char c)
{
    return (c=='+'||c=='-'||c=='*'||c=='/'||c=='^');
}





string topostfix(string infix)
{
    stack<char>s;
    string postfix="";
    for(int i=0;i<=infix.length();i++)
    {
        char c=infix[i];
        
        if(isalnum(c))
        {
            postfix+=c;
        }
        else
        {if(c=='(')
        {
            s.push(c);
            
        }
        else{
        if(c==')')
        {
            while(!s.empty()&&s.top()!='(')
            {
                postfix+=s.top();
                s.pop();
                
            }
            s.pop();
        }
        else{
            if(isoperator(c))
            {
                while(!s.empty() &&precedence(s.top())>=precedence(c))
                {
                    postfix+=s.top();
                    s.pop();
                }
                s.push(c);
                
            }
            else{
                while(!s.empty())
                {
                    postfix+=s.top();
                    s.pop();
                }
            }
        }
        }
        }
    }
    
    return postfix;
}

int main()
{
  string infix;
  string postfix;
  cout<<"enter the infix string:"<<endl;
  cin>>infix;
  postfix=topostfix(infix);
  cout<<"postfix expression:"<<postfix<<endl;
  return 0;
  
}