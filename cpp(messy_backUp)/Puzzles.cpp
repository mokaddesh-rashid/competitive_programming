        #include<iostream>
        #include<algorithm>

        using namespace std;


        int main()
        {
            int n,m;

            cin>>n>>m;

            int ar[m+1],i,x,a,b,d;

            for(i=0;i<m;i++)
            {
                cin>>ar[i];
            }

            d=m-1;
             for(i=0;i<m;i++,d--)
                 for(x=i;x<d;x++)
             {
                 if(ar[i]>ar[x])
                    swap(ar[i],ar[x]);
                 if(ar[d]<ar[x])
                    swap(ar[d],ar[x]);
             }

             x=0;

              d=0;
              for(i=n-1;i<m;i++)
            {
                a=ar[i]-ar[d];

                x=min(x,a);
            }

            cout<<x;

        }
