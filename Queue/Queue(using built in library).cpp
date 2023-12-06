#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<int> queue;
    int value,choose;

    while (choose != 3)
    {
        cout<<" Choose the option below: "<<endl;
        cout<<"01. Push"<<endl;
        cout<<"02. Pop"<<endl;
        cout<<"03. Exit"<<endl;
        cin>>choose;
        
        if (choose == 1)
        {
            queue.push(value);
        }
        else if (choose == 2)
        {
            int front = queue.front();
            queue.pop();
        }
        else{
            break;
        }
    }
}