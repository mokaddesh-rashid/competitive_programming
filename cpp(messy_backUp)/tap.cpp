 #include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double x, y,
    sizee=10;
    char ch=3;
    string message = (" I Love you TAposhi ");
    int print_line = 4;
    if(message.length() % 2 != 0) message += " ";
    for(x=0;x<sizee;x++)
    {
        for(y=0;y<=4*sizee;y++)
        {
            double dist1 = sqrt( pow(x-sizee,2) + pow(y-sizee,2) );
            double dist2 = sqrt( pow(x-sizee,2) + pow(y-3*sizee,2) );
            if (dist1 <sizeee + 0.5 || dist2 <sizeee + 0.5 )
                {
                cout << ch;
                }
            else cout << " ";
        }

            cout<<"n";
    }
    for(x=1;x<2*sizee;x++)
    {

    for(y=0;y<x;y++)
          cout << " ";
    for (y=0;y< ((4*sizee) + 1 – ( 2*x )); y++)
        {
            if (x >= print_line – 1 && x <= print_line + 1) {

                int idx = y – (4*sizee – 2*x – message.length()) / 2;
                if (idx < message.length() && idx >= 0)
                {
                    if (x == print_line)
                          cout<<message[idx];

                      else cout << " ";
                }
                else cout << ch;
            }
            else cout << ch;
        }

            cout<<endl;
    }
    return 0;
}
