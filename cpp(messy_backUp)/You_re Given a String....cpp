
#include<iostream>
#include<cstring>


using namespace std;

int main()
{
    char str[111];
    cin>>str;

    int len,a,b,c,x=0,y=0,i,n,m,j;

    len=strlen(str);

    //for(i=0;i<len;i++)
    {
        for(m=0;m<len;m++)
        for(n=m+1;n<len;n++)
        {
            if(str[m]==str[n])
                {
                    i=m;
                    j=n;
                    x=0;
                    while(str[i]==str[j])
                    {
                        i++;
                        j++;
                        x++;
                    }
                    if(x>y)
                        y=x;
                }
        }

        cout<<y;

    }



}
