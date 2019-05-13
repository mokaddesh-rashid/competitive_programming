
#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>

using namespace std;


#define inf         freopen("in.txt", "r", stdin);
#define outf        freopen("out.txt", "w", stdout);
#define pf          prlong long f
#define sf(n)       scanf("%I64d", &n)
#define sff(a,b)    scanf("%I64d %I64d", &a, &b)
#define mn          (long long)-1000000000000000000
#define mx          (long long) 1000000000000000000

//set<long long >::iterator ii;
long long   pfac[20+1], tim[20+1], nf, divi[100000], nd;




int main()
{
    std::ios::sync_with_stdio(false);


    long long n, x, maxx = mn, a, b, m, i , ans, y;

       nf = 4;
       pfac[0] = 2;
       pfac[1] = 3;
       pfac[2] = 7;
       pfac[3] = 5;



        cin >> ans;
        m = ans;
        for( int bt=0; bt < 1<<nf; bt++)
        {
            int nob = 0;
            long long val = 1;
            for(int i=0; i< nf; i++)
            {


                if( bt & (1<<i) )
                {
                    val *=pfac[i];
                    nob++;
                }

            }
            if( nob > 0 )
                 {
                      //cout << val << ' ' << nob << ' ' << m/val << endl;
                     if(nob%2==0)
                        ans += m/val;
                     else
                        ans -= m/val;
                 }

        }
        cout << ans;



}
