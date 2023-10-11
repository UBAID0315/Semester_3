#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *prev;
        Node *next;

        Node(int val)
        {
            data = val;
            prev = NULL;
            next = NULL;
        }
}; 

class Double_list
{
    int length;
    Node *head;

    public:
        Double_list()
        {
            length = 0;
            head = NULL;
        }
        void insert(int pos, int val)
        {
            if (pos < 1 || pos > length + 1)
            {
                cout<<"Invalid position"<<endl;
            }
            
            Node *n = new Node(val);
            if (pos == 1)
            {
                n->next = head;
                if (head != NULL)
                {
                    head->prev = n;
                }
                head = n;
            }
            if(pos > 1 || pos < length)
            {
                Node *curr = head;

                n->prev = head;
                n->next = curr->next;

                if (curr->next != NULL)
                {
                    curr->next->prev = n;
                }
                curr->next = n;
            }
        length++;
        }
        
        void remove(int pos)
        {
            if (length == 0)
            {
                cout<<"Nothing to remove from the list"<<endl;
            }
            Node *curr = head;
            if (pos == 1)
            {
                head = head->next;
                if (curr->next != NULL)
                {
                    head->prev = NULL;
                }
                delete curr;
            }
            
            if(pos < 1 || pos > length)
            {
                cout<<"Invalid position"<<endl;
            }
            if (pos > 1 || pos < length)
            {
                Node *slow = NULL;
                for (int i = 0; i < pos; i++)
                {
                    slow = curr;
                    curr = curr->next;
                }
                if (curr->next != NULL)
                {
                    curr->next->prev = slow;
                }
                slow->next = curr->next;
                
                delete curr;
            }
            length--;
        }
        void print()
        {
            Node *curr = head;

            for (int i = 1; i <= length; i++)
            {
                cout<<curr->data<<endl;
                curr = curr->next;
            }
        }
        void update(int pos,int val)
        {
            if (length == 0)
            {
                cout<<"Nothing is in the list to update"<<endl;
            }
            if (pos < 1 || pos > length + 1)
            {
                cout<<"Invalid Position"<<endl;
            }
            if (pos >= 1 || pos <= length)
            {
                Node *curr = head;
                for (int i = 1; i < pos; i++)
                {
                    curr = curr->next;
                }
                curr->data = val;
            }
        }
};

int main()
{
    Double_list L;

    L.insert(1,5);
    L.insert(2,3);
    L.insert(3,4);
    L.insert(3,6);
    L.update(3,200);

    L.print();
}
