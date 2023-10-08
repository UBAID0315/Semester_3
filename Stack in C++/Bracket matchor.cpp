#include<iostream>
using namespace std;

class Node
{
    public:
        Node *next;
        char data;

        Node(char val)
        {
            next = NULL;
            data = val;
        }
};
class Stack
{
    private:
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
            Node *newnode = new Node(val);
            
            if (length == 0)
            {
                top = newnode;
            }
            else
            {
                newnode->next = top;
                top = newnode;
            }
            length++;
        } 
        char pop()
        {
            char value;

            if (length < 0)
            {
                cout<<"Nothing is more to pop"<<endl;
            }
            else if (length > 0)
            {
                Node *curr = top;
                value = curr->data;
                top = top->next;
                delete curr;
            }
            length--;
            return value;
        }
};

bool Bracket_Matcher(string braces)
{
    Stack S1,S2;
    int length = braces.length();

    for (int i = 0; i < length; i++)
    {
        if (i < length / 2)
        {
            S1.push(braces[i]);
        }
        else if(i >= length/2)
        {
            S2.push(braces[i]);

            char curr_S1 = S1.pop();
            char curr_S2 = S2.pop();

            if ((curr_S1 == '{' && curr_S2 != '}')||
                (curr_S1 == '[' && curr_S2 != ']')||
                (curr_S1 == '(' && curr_S2 != ')'))
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    string braces;
    bool Result;

    cout<<"Enter the braces: ";
    cin>>braces;

    Result = Bracket_Matcher(braces);

    if (Result == 1)
    {
        cout<<"Brackets Matched"<<endl;
    }
    else
    {
        cout<<"Something missing in Brackets"<<endl;
    }
    
}
