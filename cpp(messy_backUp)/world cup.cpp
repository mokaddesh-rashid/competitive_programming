#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;


class worldcup
{
public:
    int point,goal,x,y;
    char con[111];

    worldcup()
    {
        cin>>con;
        point=0;
        goal=0;
    }


};


int main()
{
    char name[111],nam[111];
    int i,a,b,c,d,n,x,y,z;

    cin>>n;
    z=n;
    worldcup part[n];

     c=(n*(n-2))/2;
    for(i=0;i<c;i++)
    {
       scanf("%s : %s %d : %d", name, nam, &a, &b);


        for(int z=0;z<n;z++)
        {
            if(strcmp(name,part[z].con)==0)
                x=z;
             if(strcmp(nam,part[z].con)==0)
                y=z;
        }

       cout<<x;




    }
}
