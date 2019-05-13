#include<iostream>
#include<algorithm>


using namespace std;

int main()
{
    long long int n,a,b,x=0,y,z,c,l;

    cin>>n>>a>>b;

    long long int k,bi,ro,qe,gh;

    if(n==1)
        cout<<"King: 0\n";
    else if(a==1&&b==1)
        cout<<"King: 3\n";
    else if(a==1&&b==n)
        cout<<"King: 3\n";
    else if(a==n&&b==1)
        cout<<"King: 3\n";
    else if(a==n&&b==n)
        cout<<"King: 3\n";

    else if(a==1||a==n||b==1||b==n)
        cout<<"King: 5\n";
    else
        cout<<"King: 8\n";

    if(a-1>=1&&b+2<=n)
        x++;

      //cout<<a-1<<' '<<b+2<<' '<<x<<endl;
    if(a+1<=n&&b+2<=n)
        x++;
        //cout<<a+1<<' '<<b+2<<' '<<x<<endl;
    if(a-2>=1&&b+1<=n)
        x++;
        // cout<<a-2<<' '<<b+1<<' '<<x<<endl;
    if(a+2<=n&&b+1<=n)
        x++;
         //cout<<a+2<<' '<<b+1<<' '<<x<<endl;
    if(a-2>=1&&b-1>=1)
        x++;
         //cout<<a-2<<' '<<b-1<<' '<<x<<endl;
    if(a+2<=n&&b-1>=1)
        x++;
        // cout<<a+2<<' '<<b-1<<' '<<x<<endl;
    if(a-1>=1&&b-2>=1)
        x++;
        // cout<<a-1<<' '<<b-2<<' '<<x<<endl;
    if(a+1<=n&&b-2>=1)
        x++;
         //cout<<a+1<<' '<<b-2<<' '<<x<<endl;

    cout<<"Knight: "<<x<<endl;

   x=a-1;
   y=n-a;
   z=b-1;
   l=n-b;

   c=min(x,l)+min(x,z)+min(y,z)+min(y,l);

   cout<<"Bishop: "<<c<<endl;

   cout<<"Rook: "<<(n-1)*2<<endl;
   cout<<"Queen: "<<c+(n-1)*2;



}
