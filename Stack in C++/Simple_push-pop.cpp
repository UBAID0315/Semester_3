#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};
class Stack
{
    Node *top;
    int capacity;
    int length;
    public:
        Stack(int cap)
        {
            capacity = cap;
            top = NULL;
            length = 0;
        }
        ~Stack() 
        {
            while (!isEmpty()) 
            {
                pop();
            }
        }
        bool isEmpty()
        {
            if(top==NULL)
            {
                return true;
                cout<<"Stack is empty"<<endl;
            }
            else
            {
                return false;
            }
        }
        bool isFull()
        {
            if(length == capacity)
            {
                cout<<"Stack is full"<<endl;
                return true;
            }
            else
            {
                return false;
            }
        }
        void push(int val)
        {
            if (!isFull())
            {
                Node *temp = new Node(val);
                temp->next = top;
                top = temp;
                length++;

                cout<<"Element: "<<val<<" is pushed"<<endl;
            }
            else
            {
                cout<<"Stack Overflow"<<endl;
            }
        }
        int pop()
        {
            if (!isEmpty())
            {
                Node *temp = top;
                int val = top->data;
                top = top->next;
                delete temp;
                temp = NULL;
                length--;
                cout<<"Element: "<<val<<" is popped"<<endl;
                return val;
            }
            else
            {
                cout<<"Stack Underflow"<<endl;
            }
            return 0;
        }
};
int main()
{
    Stack S(2);
    int value_1,value_2,temp;

    cout<<"First value: ";
    cin>>value_1;
    S.push(value_1);
    cout<<"Second value: ";
    cin>>value_2;
    S.push(value_2);

    cout<<endl;
    value_1  = S.pop();
    value_2 = S.pop();

    cout<<value_1<<" "<<value_2<<endl;
}