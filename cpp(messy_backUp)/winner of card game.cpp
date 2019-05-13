#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    int a[11111],d=0,k=0,i,x,n,ar,m;

    cin>>ar;

    char str[ar+1][1111], ch[111], win[111];

    for(i=0;i<ar;i++)
    {
        cin >> ch >> x;
        for(n=0;n<=d;n++)
        {

            if(strcmp(ch,str[n])==0)
            {

                a[n]=a[n]+x;

                break;
            }


            else if(n==d)
            {
                strcpy(str[d],ch);
                a[d]=x;
                d++;

                break;
            }
        }

        if(strcmp(win,str[n])==0&&k>a[n])
        {
        	cout<<"\nfuck "<<win<<"\t"<<k<<endl;
            k=a[0];
            strcpy(win,str[0]);
            for(m=0;m<=d;m++)
            {
               if(k<a[m])
               {
                   k=a[m];
                   strcpy(win,str[m]);
               }
            }

        }

         if(k==a[n])
                 strcpy(win,str[n]);


        else if(a[n]>k)
        {
            strcpy(win,str[n]);
            k=a[n];
            cout<<win<<"\t"<<k<<endl;
        }


    }


    cout<<win;
}
