#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<int> Stack;
    int value,choose;

    while (true)
    {
        cout<<" Choose the option below: "<<endl;
        cout<<"01. Push"<<endl;
        cout<<"02. Pop"<<endl;
        cout<<"03. Top Value"<<endl;
        cout<<"04. Exit"<<endl;
        cin>>choose;
        
        if (choose == 1)
        {
            Stack.push(value);
        }
        else if (choose == 2)
        {
            int front = Stack.top();
            Stack.pop();
        }
        else if (choose == 3)
        {
            cout<<Stack.top()<<endl;
        }       
        else
        {
            break;
        }
    }
}
