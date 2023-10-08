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
        void push(int val)
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
        int pop()
        {
            int value;

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

bool isDigit(char c) 
{
    return c >= '0' && c <= '9';
}
int Postfix_Exp(string exp)
{
    Stack S;
    int result,A,B; // A and B are operands

    for (int i = 0; i < exp.length(); i++)
    {
        if (isDigit(exp[i]))
        {
            S.push(exp[i] - 48);
        }
        else if (exp[i] == '*' || exp[i] == '/' || exp[i] == '+' || exp[i] == '-' || exp[i] == '%')
        {
            A = S.pop();
            B = S.pop();
            switch (exp[i])
            {
                case '+':
                    result = B + A;
                    break;
                case '-':
                    result = B - A;
                    break;
                case '*':
                    result = B * A;
                    break;
                case '/':
                    if (B > A)
                    {
                        result = B / A;
                    }
                    else if (A == 0)
                    {
                        cout<<"Runtime_Error: Number divisble by 0"<<endl;
                    }            
                break;
                case '%':
                    result = B % A;
                    break;
                default:
                    break;
            }
            S.push(result);
        }
    }
    return S.pop();
}

int main()
{
    string expression;
    int Stack_value;

    cout<<"Enter the postfix expression: ";
    cin>>expression;
    
    Stack_value = Postfix_Exp(expression);

    cout<<"The last value of Stack is: "<<Stack_value<<endl;
}
