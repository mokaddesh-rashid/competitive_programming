#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int top, Size;
char *a;
void Resize();
void Push(char value);
void Pop();
char Top();
bool Empty();

void Stack_s()
{
    top = -1;
    Size = 1;
    a = new char [Size];
}

void Resize()
{
    Size *= 2;
    char *b = new char [Size];

    for(int i = 0; i <= top; i++)
        b[i] = a[i];
    delete []a;
    a = b;
}

void Push(char value)
{
    if(top == Size-1)
        Resize();

    top++;
    a[top] = value;
}

void Pop()
{
    if( !Empty() )
        top--;
}

char Top()
{
    if( !Empty() )
        return a[top];

    return NULL;
}

bool Empty()
{
    if(top == -1)
        return true;

    return false;
}
// End of Stack

int priority(char ch)
{
    switch(ch)
    {
        case '+': case '-':
            return 1;
        case '*': case '/':
            return 2;
        case '%':
            return 3;
        case '^':
            return 4;
        default:
            return 0;
    }
}

void makePostfix(string s, string &t)
{
    Stack_s();
    char ch;
    int p;
    string temp;

    for(int i = 0; i < s.size(); i++)
    {
        temp = "";

        while(i < s.size() && s[i] >= '0' && s[i] <= '9')
        {
            temp += s[i];
            i++;
        }

        if( !temp.empty() )
        {
            t += temp;
            t += " ";
        }

        if(i < s.size())
        {
            p = priority(s[i]);

            if(priority(s[i]) >= 1)
            {
                if(t.empty() || priority(s[i-1]) >= 1)
                {
                    cout << "Syntax Error!" << endl;
                    t = "";
                    return ;
                }

                ch =  Top();

                while(priority(ch) >= p)
                {
                    t += ch;
                     Pop();
                    ch =  Top();
                }

                 Push(s[i]);
            }
            else if(s[i] == '[' || s[i] == '{' || s[i] == '(')
            {
                 Push(s[i]);
            }
            else if(s[i] == ']' || s[i] == '}' || s[i] == ')')
            {
                ch =  Top();

                while(ch != NULL && ch != '[' && ch != '{' && ch != '(')
                {
                    t += ch;
                     Pop();
                    ch =  Top();
                }

                if( (s[i] == ']' && ch == '[') || (s[i] == '}' && ch == '{') || (s[i] == ')' && ch == '(') )
                     Pop();
                else
                {
                    cout << "Syntax Error! Expected opening bracket before " << s[i] << endl;
                    t = "";
                    return ;
                }
            }
            else
            {
                cout << "Syntax Error! Invalid Character." << endl;
                t = "";
                return ;
            }
        }
    }

    ch =  Top();

    while(priority(ch) >= 1)
    {
        t += ch;
         Pop();
        ch =  Top();
    }

    if( ! Empty() )
    {
        cout << "Syntax Error!" << endl;
        t = "";
        return ;
    }
}

int toNum(string s)
{
    int i = 0, sum = 0;

    while(i < s.size())
    {
        sum = sum * 10 + (s[i] - '0');
        i++;
    }

    return sum;
}

string toStr(int n)
{
    string temp;
    char ch;

    do
    {
        ch = '0' + (n % 10);
        temp = ch + temp;
        n /= 10;

    } while(n > 0);

    return temp;
}

int calc(int x, int y, char ch)
{
    switch(ch)
    {
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '*':
            return x * y;
        case '/':
            return x / y;
        case '%':
            return x % y;
        case '^':
            return pow(x, y);
    }
}



int main()
{
    Stack_s();
    int len, i, k;
    char ch;
    string s, t;
    bool flag;

    cin >> s;///input should not contains any space

    makePostfix(s, t);

    if( !t.empty() )
    {
        cout << endl << "Postfix : " << t << endl;

    }

    return 0;
}
