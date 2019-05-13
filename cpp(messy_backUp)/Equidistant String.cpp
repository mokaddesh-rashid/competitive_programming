#include<iostream>

using namespace std;

int main()
{
    string line,lin2,lin3;

    int x,a=0,b,c=0,i,n;

    cin>>line>>lin2;

    lin3=line;

    for(i=0;i<line.size();i++)
    {
        if(line[i]==lin2[i])
            lin3[i]=line[i];

        else
        {
            a++;
            if(c%2==0)
                lin3[i]=line[i];
            else if(c%2==1)
                lin3[i]=lin2[i];
            c++;
        }

    }

    if(a%2==1)
        cout<<"impossible";
    else
        cout<<lin3;
}
