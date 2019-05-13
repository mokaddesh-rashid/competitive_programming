#include<iostream>
#include <math.h>

using namespace std;

int main()
{
    int size_0=pow(10,5);
    long long int i,n,k,a,b,c,population=0,pos[size_0],neg[size_0],top=-1,topn=-1;


    cin>>n>>k;

    for(i=0;i<n;i++)
    {
        cin>>a;

        if(a%2==0)
        {
            top++;
            pos[top]=a;

        }
        else if(a%2==1)
        {
             topn++;
             neg[topn]=a;

        }
        population+=a;
    }

    i=0;
    while(n>k)
    {
        if(i%2==0)
        {

             if(top>-1)
            {
                population-=pos[top];
                top--;

            }

            else
            {
                population-=neg[topn];
                topn--;
            }
        }
        else if(i%2==1)
        {
            if(topn>-1)
            {
                population-=neg[topn];
                topn--;

            }
            else
            {
                 population-=pos[top];
                top--;
            }

        }
        i++;
        n--;
    }

    if(population%2==0)
        cout<< "Daenerys";
    else
        cout<<"Stannis";


}
