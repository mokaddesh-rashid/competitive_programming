#include<iostream>
#include<string>

using namespace std;


int main()
{
    int top=-1,i,a=0;
    char ch;
    string braket,stack0;

    cin>>braket;

    for(i=0;i<braket.size();i++)
    {
        ch=braket[i];

         if(ch=='('||ch=='{'||ch=='[')
        {
            top++;
            stack0[top]=ch;
        }
        else if(ch==')'||ch=='}'||ch==']')
        {
            if(top==-1)
            {
                cout<<"invalid Expression error at "<<i+1<<' '<<endl;
                a=1;
                break;
            }
            else if(ch==')'&&stack0[top]=='(')
                top--;
            else if(ch=='}'&&stack0[top]=='{')
                top--;
            else if(ch==']'&&stack0[top]=='[')
                top--;
            else
            {
                cout<<"invalid Expression error at "<<i+1<<' '<<endl;
                a=1;
                break;
            }
        }


    }

    if(top==-1&&a==0)
        cout<<"valid Expression";
    else if(a==0)
        cout<<"invalid Expression didnot close the bracket";


}
