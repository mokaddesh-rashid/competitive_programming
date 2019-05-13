#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    char str[3],st[3];
    int a,b,c,d,x,y,i;

    cin>>str>>st;

    c=str[0]-48;
    d=st[0]-48;
    a=str[1]-96;
    b=st[1]-96;

    if(a==b)
        {
            x=max(c-d,d-c);
            cout<<x<<endl;
            for(i=0;i<x;i++)
            {
                if(c<d)
                    cout<<"R"<<endl;
                else if(c>d)
                    cout<<"L"<<endl;

            }
        }
    else if(c==d)
        {
            x=max(a-b,b-a);
            cout<<x<<endl;
            for(i=0;i<x;i++)
            {
               if(a<b)
                    cout<<"U"<<endl;
                else if(a>b)
                    cout<<"D"<<endl;
            }
        }
    else
    {
        int Z,z=0;
        x=max(a-b,b-a);

        if(x>=max(c-d,d-c))
            {{
                cout<<x<<endl;
                if(a<b)
                {

                    while(c!=d)
                    {
                        if(c<d)
                        {
                            cout<<"RU"<<endl;
                            c++;
                            z++;
                        }
                        else if(c>d)
                        {
                            cout<<"LU"<<endl;
                            c--;
                            z++;
                        }
                    }

                    while(z!=x)
                    {
                        cout<<"U"<<endl;
                        z++;
                    }
                }
               else if(a>b)
                {
                   a=a+(max(c,d)-min(c,d));
                    while(c!=d)
                    {
                        if(c<d)
                        {
                            cout<<"RD"<<endl;
                            c++;
                            z++;
                        }
                        else if(c>d)
                        {
                            cout<<"LD"<<endl;
                            c--;
                            Z++;
                        }
                    }

                     while(z!=x)
                    {
                        cout<<"D"<<endl;
                       z++;
                    }
                }
            }
            }


        else if(x<max(c-d,d-c))
           {


               y=max(c,d);
               z=min(c,d)+x;
               y=y-z;
               x=x+y;

               cout<<x<<endl;




              if(a<b)
            {

               c=c-(b-a);
                 while(a!=b)
                   {
                        cout<<"LU"<<endl;
                                a++;
                   }
                if(c>d)
                while(c!=d)
                   {
                       cout<<"L"<<endl;
                               c--;
                   }
                else if(c<d)
                         while(c!=d)
                     {
                         cout<<"R";
                             c++;
                     }

            }


             if(a>b)
           {

             d=d-(a-b);

              while(a!=b)
            {

            cout<<"RD"<<endl;
            a--;

            }

             if(c>d)
                while(c!=d)
                   {
                       cout<<"L"<<endl;
                               c--;
                   }

            if(c<d)
            while(c!=d)
          {
            cout<<"R"<<endl;
            d--;
          }

         }


        }




    }
}
