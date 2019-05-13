#include<iostream>
#include<string>

using namespace std;

string str;

int size_s=500, i, value=0;
char stack0[9999];
int top=-1;


void push(char ch)
{
    top++;
    stack0[top]=ch;

}

void pop()
{
    top--;
}

int main()
{
    cin>>str;

    for(i=0;i<str.size();i++)
    {

        if( str[i] == '(' || str[i] == '{' || str[i] == '[' )
            {
               push(str[i]);
            }
        else if( str[i]==')' || str[i]=='}' || str[i]==']' )
            {
               if(top==-1)
               {
                   value=1;
                   break;
               }

               else if(str[i]==')'&&stack0[top]=='(')
                  pop();
               else if(str[i]=='}'&&stack0[top]=='{')
                  pop();
               else if(str[i]==']'&&stack0[top]=='[')
                  pop();

              else
              {
                  value=1;
                  break;
              }
            }
    }

    if(value==0&&top==-1)
        cout<<"valid";
    else
        cout<<"invalid";
}
