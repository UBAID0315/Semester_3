#include<iostream>
using namespace std;

class Node
{
    public:
        Node *next;
        int data;

        Node(int val)
        {
            next = NULL;
            data = val;
        }
};
class List
{
    private:
        int length;
        Node *head;
    public:
        List()
        {
            length = 1;
            head = NULL;
        }
        void josephus( int n, int m )
        {
            int value;
            if (n<=0)
            {
                cout<<"Invalid"<<endl;
                return;
            }
            
            head = new Node(1);
            Node *curr = head;

            for (int i = 2; i <= n; i++)
            {
                curr->next = new Node(i);
                curr = curr->next;
                if (i == n)
                {
                    curr->next = head;
                }
                length++;
            }

            curr = head;
            Node *slow = NULL;
loop:
            for (int i = 1; i <= m; i++)
            {
                slow = curr;
                curr = curr->next;
            }
            while (length != 0)
            {
                if(curr == head)
                {
                    head = head->next;
                    slow->next = head;
                    cout<<curr->data<<" ";
                    delete curr;
                }
                else if(curr->next == head)
                {
                    slow->next = head;
                    cout<<curr->data<<" ";
                    delete curr;
                }
                else if (curr->next != head)
                {
                    slow->next = curr->next;
                    cout<<curr->data<<" ";
                    delete curr;
                }
                if (length != 1)
                {
                    curr = slow->next;
                }
                
                length--;
                if (length != 0)
                {
                    goto loop;
                }
            }
        }
};
int main()
{
    List L;
    int people,step;

    cout<<"Enter the no of peoples: ";
    cin>>people;
    cout<<"Enter the steps: ";
    cin>>step;
    cout<<endl;
    cout<<"Peoples eliminations: [ ";
    L.josephus(people,step);
    cout<<"]";

}
