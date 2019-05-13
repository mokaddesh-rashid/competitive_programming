#include<iostream>
#include<string>


using namespace std;


int main()
{
    int n,i,a,b,c,d,x=0;

    string str;

    cin>>n;

    cin>>str;



    n=str.size();


    for(i=0;i<n;i++)
    {
        a=1;
        while(i+a+a+a+a<n)
        {
           if(str[i]=='*'&&str[i+a]=='*'&&str[i+a+a]=='*'&&str[i+a+a+a]=='*'&&str[i+a+a+a+a]=='*')
           {
               x=1;
               break;

           }
           a++;
        }

        if(x==1)
            break;

    }

   if(x==1)
      cout<<"YES";
   else
    cout<<"NO";
}
