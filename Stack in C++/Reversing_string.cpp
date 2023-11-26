#include<iostream>
using namespace std;
class Stack
{
    int top;
    int capacity;
    char *arr;
    char *curr;
    public:
    Stack(int size)
    {
        top=-1;
        capacity = size;
        arr = new char[size];
    }
    ~Stack()
    {
        delete[] arr;
    }
    void setarray(string word)
    {
        for (int i = 0; i < word.length(); i++)
        {
            arr[i] = word[i];
            push(arr[i]);
        }
        cout<<"String is pushed"<<endl;
    }
    bool isEmpty()
    {
        if(top == -1)
        {
            cout<<"Stack is empty"<<endl;
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull()
    {
        if(top == capacity-1)
        {
            cout<<"Stack is full"<<endl;
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(char val)
    {
        if(!isFull())
        {
            top++;
            arr[top]=val;
        }
    }
    char pop()
    {
        if(!isEmpty())
        {
            char popped = arr[top];
            top--;
            return popped;
        }
        return ' ';
    }
    void peek()
    {
        if(!isEmpty())
        {
            cout<<"Peeking into the stack (accessing top element)"<<endl;
            cout<<arr[top]<<endl;
        }
    }
    string print_string()
    {   
        string name;
        cout<<endl;
        cout<<"Reverse string from stack: "<<endl;
        for (int i = top; i >= 0; i--)
        {
            name += pop();
        }
        return name;
    }
};

int main()
{
    int size;
    string word;

    cout<<"Enter string: ";
    cin>>word;
    Stack S(word.length());
    S.setarray(word);
    word = S.print_string();

    cout<<word;
}