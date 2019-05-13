#include<iostream>
using namespace std;

const int MAX = 105;

struct Node
{
    int nodeId;
    Node *next;
    Node() {next = NULL;}
    Node(int v) {nodeId = v; next = NULL;}

}*lis[MAX], *head[MAX], *last[MAX];

void edge(int u,int v)
{
    Node *uNode = new Node(u);
    Node *vNode = new Node(v);

    if(head[u] == NULL) head[u] = vNode;
    else last[u]->next = vNode;
    last[u] = vNode;

    if(head[v] == NULL) head[v] = uNode;
    else last[v] = uNode;
    last[v] = uNode;
}

void show(int p)
{
    Node *s = head[p];
    cout << "edges from " << p << " = ";
    while(s != NULL)
    {
        cout << s->nodeId << ' ';
        s = s->next;
    }
    cout << endl;
}

int main()
{
    int n, t, u, v;
    cout << "Number of node ?\n";
    cin >> n;


    while(true)
    {
        cout<<"1. Enter edges\n";
        cout<<"2. exit\n";
        cin >> t;
        if(t == 1)
        {
            cout<<"enter source node: ";
            cin>>u;
            cout<<"enter destination node: ";
            cin>>v;

            edge(u, v);
        }
        else if(t == 2) break;
        else cout<<"Invalid input. Try again...\n";
        cout << endl;
    }

    cout << endl;
    for(int i = 1; i <= n; i++) show(i);

    return 0;
}
