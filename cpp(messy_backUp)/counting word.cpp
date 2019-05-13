#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str;
    int i,n,a,b,c,t,x;

    cin>>t;

    for(i=0;i<t;i++)
    {
        cin>>str;
        int num[26]={0};
        for(n=0;n<str.size();n++)
        {

            x=str[n]-97;
            num[x]++;
           // cout<<x<<' ';
        }

        for(n=0;n<26;n++)
        {
            if(num[n]!=0)
            {
                if(n==0)
                    cout<<'a';
                else if(n==1)
                    cout<<'b';
                else if(n==2)
                    cout<<'c';
                else if(n==3)
                    cout<<'d';

                else if(n==4)
                    cout<<'e';

                else if(n==5)
                    cout<<'f';

                else if(n==6)
                    cout<<'g';

                else if(n==7)
                    cout<<'h';

                else if(n==8)
                    cout<<'i';
                else if(n==9)
                    cout<<'j';

                else if(n==10)
                    cout<<'k';

                else if(n==11)
                    cout<<'l';

                else if(n==12)
                    cout<<'m';

                else if(n==13)
                    cout<<'n';

                else if(n==14)
                    cout<<'o';

                else if(n==15)
                    cout<<'p';

                else if(n==16)
                    cout<<'q';
                 else if(n==17)
                    cout<<'r';
                 else if(n==18)
                    cout<<'s';
                 else if(n==19)
                    cout<<'t';
                 else if(n==20)
                    cout<<'u';
                 else if(n==21)
                    cout<<'v';
                 else if(n==22)
                    cout<<'w';
                 else if(n==23)
                    cout<<'x';
                 else if(n==24)
                    cout<<'y';
                 else if(n==25)
                    cout<<'z';
                  cout<<' ';
                  cout<<num[n]<<endl;


            }
        }
    }

}
