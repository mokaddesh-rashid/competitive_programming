#include<iostream>
#include<string>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>



using namespace std;


string str,ss;
int n, m, dp[100][100], t, dl=0 ;


int rec(int x, int y)
{
    int a,b;

    if( x == n )
    return m-y;
    if (y == m)
    return n-x;
    if( dp[x][y] != -1 )
       return dp[x][y];

    if( str[x] == ss[y] )
       {
           dp[x][y] = rec( x+1,y+1);
           return dp[x][y];
       }

    else
    {
        dp[x][y] = rec(x+1,y) + 1;
        dp[x][y]  = min(rec(x,y+1) + 1,dp[x][y]);
        dp[x][y]  = min(dp[x][y],rec(x+1,y+1) + 1);

        return dp[x][y];


    }
}
void prin(int x, int y)
{
    //cout << 'b'<<endl;


    if( x == n )
        {
        for(int i=y; i<m; i++,t++,x++)
            {
               cout <<"I"<<ss[i];
            if( x+1-dl < 10)
                cout << 0;
             cout << x+1-dl;
            } //cout << t << " Insert "<<x+1-dl<<','<<ss[i]<<endl;

          return;
        }
    //return m-y;
    if (y == m)
        {
        for(int i=x; i<n; i++,t++)
             {
                 cout <<"D"<<str[i];
                   if( x+1-dl < 10 )
                cout << 0;

                    cout << x+1-dl ; //<< str[x]<<endl;

                 //cout << t << " Delete "<< x+1-dl << endl;
             }

          return;
        }
    //return n-x;
    if( str[x] == ss[y] )
       {
            prin( x+1,y+1);
       }

    else
    {
        int a;
        a = rec(x+1,y) + 1;
        a  = min(rec(x,y+1) + 1,a);
        a  = min(a,rec(x+1,y+1) + 1);
       // cout << dp[x+1][y] <<' '<< dp[x][y+1] <<' '<< dp[x+1][y+1] <<endl;
        if( rec(x+1,y) + 1 == a )
        {

            cout <<"D"<<str[x];
            if( x+1-dl < 10 )
                cout << 0;
           cout << x+1-dl ; //<< str[x]<<endl;
            dl++;
            prin( x+1,y);
        }
        else if( rec(x,y+1) + 1 == a )
        {
            cout <<"I"<<ss[y];
            if( x+1-dl < 10)
                cout << 0;
             cout << x+1-dl;
            dl--;
            prin( x,y+1);
        }
        else
        {
            cout <<"C"<<ss[y];
            if( x+1-dl < 10)
                cout << 0;
             cout << x+1-dl;
            //cout << t << " Replace "<< x+1-dl << ',' <<ss[y]<<endl;
            t++;
            prin( x+1,y+1);
        }


    }
}





int main()
{

    int x;

    while( true  )
     {
        cin >> str;

        if( str == "#")
            break;
        cin >> ss;
         dl = 0;
         t = 1;
         n = str.size();
         m = ss.size();
     memset( dp,-1,sizeof(dp));
     x = rec(0,0);
     //cout << x <<endl;
     prin(0,0);
     cout << 'E' << endl;


     }
}

