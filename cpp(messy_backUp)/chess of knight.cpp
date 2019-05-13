#include<iostream>
#include<cstdio>


using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    int t;

    scanf("%d",&t);

    int i,n,a,b,x=0,ar;

    for(i=0;i<t;i++)
    {
        cin>>a>>b;


        if(a==1)
        {
            ar=b;

            //cout<<"Case"<<' '<<i+1<<':'<<' '<<ar<<"\n";
            printf("Case %d : %d\n",i+1,ar);
        }
        else if(b==1)
        {
            ar=a;

            //cout<<"Case"<<' '<<i+1<<':'<<' '<<ar<<"\n";
            printf("Case %d : %d\n",i+1,ar);
        }
       else if(a==2)
       {
           ar=max(a,b);
           a=ar;
           ar=ar/4;

           if(a%4==0&&ar!=0)
                x=0;
           else ar++;
           ar=ar*4;
           a--;
           if(a%4==0)
            ar-=2;
         printf("Case %d : %d\n",i+1,ar);

       }
        else if(b%2==0)
        {
            ar=a*(b/2);

           // cout<<"Case"<<' '<<i+1<<':'<<' '<<ar<<"\n";
            printf("Case %d : %d\n",i+1,ar);
        }
        else if(a%2==0&&b%2==1)
        {
            ar=a*(b/2);
            ar=ar+(a/2);
           // cout<<"Case"<<' '<<i+1<<':'<<' '<<ar<<"\n";
           printf("Case %d : %d\n",i+1,ar);
        }
        else if(a%2==1&&b%2==1)
        {
            ar=a*(b/2);
            ar=ar+(a/2)+1;
            //cout<<"Case"<<' '<<i+1<<':'<<' '<<ar<<"\n";
            printf("Case %d : %d\n",i+1,ar);
        }
    }



}
