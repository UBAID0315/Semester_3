#include<iostream>
using namespace std;

struct Node
{
    char data;
    Node *next;
    Node(char val)
    {
        data = val;
        next = NULL;
    }
};

class Stack
{
        int length;
        Node *top;
    public:
        Stack()
        {
            length = 0;
            top = NULL;
        }
        void push(char val)
        {
            Node *newNode = new Node(val);
            
            if (length == 0)
            {
                top = newNode;
            }
            else
            {
                newNode->next = top;
                top = newNode;
            }
            length++;
        } 
        char pop()
        {
            char value;
            Node *curr = top;

            top = top->next;
            curr->next = NULL;
            value = curr->data;
            delete curr;
            
            length--;
            return value;
        }
        int getlength()
        {
            return length;
        }
};

int main()
{
    Stack S;
    char location,back_location;
    int choose,length;

    cout<<"Welcome to the cave"<<endl;
    cout<<"Must store your value in the stack so that you can go back whenever you  see the ghost"<<endl;

    while (choose != 3)
    {
        cout<<"Enter the choice: "<<endl;
        cout<<"1. Go Forward"<<endl;
        cout<<"2. Go Back"<<endl;
        cout<<"3. Run from the cave.... I saw the ghost"<<endl;
        cin>>choose;

        if (choose == 1)
        {
            cout<<"Mark your location, so that you can go back"<<endl;
            cout<<"Enter your location: ";
            cin>>location;
            S.push(location);
        }
        else if (choose == 2)
        {
            back_location = S.pop();
            if (S.getlength() != 0)
            {
                cout<<"Your are at location "<<back_location<<endl;
            }
            else
            {
                cout<<"You have'nt any cave to enter"<<endl;
            }
        }
        else if (choose == 3)
        {
            length = S.getlength();
            for (int i = 0; i < length; i++)
            {
                cout<<"You are now at: "<<S.pop()<<endl;
            }
            cout<<"You successfully ran away from the cave"<<endl;
            break;
        }
    }
    
}
