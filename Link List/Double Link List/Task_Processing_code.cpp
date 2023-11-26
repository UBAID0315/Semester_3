#include<iostream>
using namespace std;


class Node
{
    public:
        string data;
        Node *prev;
        Node *next;
        bool task;

        Node(string val)
        {
            task = false;
            data = val;
            prev = NULL;
            next = NULL;
        }
};

class Doubly_list
{
    int length;
    Node *head;

    public:
        ~Doubly_list()
        {
            Node *curr = head;
            do
            {
            head = head->next;
            delete curr;
            }
            while(curr != NULL);
            
            head=NULL;
        }
        Doubly_list()
        {
            length = 0;
            head = NULL;
        }
        void Mark_as_Complete(int pos)
        {
            if (pos < 1 || pos > length + 1)
            {
                cout<<"Invalid position"<<endl;
            }
            if (pos > 1 || pos < length)
            {
                Node *curr = head;

                for (int i = 1; i < pos; i++)
                {
                    curr = curr->next;
                }
                curr->task = true;
            }
                        
        }
        void Add_Task(string val,int pos)
        {
            Node *n = new Node(val);

            if (pos < 1 || pos > length + 1)
            {
                cout<<"Invalid position"<<endl;
            }
            else if (pos == 1)
            {
                Node *curr = NULL;
                curr = n;
                if (head != NULL)
                {
                    curr->next = head;
                    head->prev = curr;
                }
                head = n;
            }
            else
            {
                Node *curr = head;

                for (int i = 1; i < (pos-1); i++)
                {
                    curr = curr->next;
                }
                n->next = curr->next;
                if (curr->next != NULL)
                {
                    curr->next->prev = n;
                }
                curr->next = n;
                n->prev = curr;
            }
            length++;
        }
        void Display_Task()
        {
            Node *curr = head;

            for (int i = 1; i <= length; i++)
            {
                cout<<curr->data<<"-"<<curr->task<<endl;
                curr = curr->next;    
            }
        }
        void Remove_Task()
        {
            Node *curr = head;
            if (length == 0)
            {
                cout<<"Nothing to remove from the list"<<endl;
            }
            else if(curr->task == true)
            {
                Node *slow = head;
                for (int i = 1; i <= length; i++)
                {
                    curr->next->prev = slow;
                }
                slow->next = curr->next;
                delete curr;
                cout<<"Task has been successfully removed"<<endl;
            }
            length--;
        }
};

int main()
{
    Doubly_list DL;
    int choose,position;
    string value;

    cout<<"Welcome to your List"<<endl;

    do
    {
        cout<<endl;
        cout<<"Which task you want to perform?"<<endl;
        cout<<"1) Add Task"<<endl;
        cout<<"2) Mark as Completed"<<endl;
        cout<<"3) Remove Task"<<endl;
        cout<<"4) Display Task"<<endl;
        cout<<"5) Exit"<<endl<<endl;

        cout<<"Enter your option: "<<endl;
        cin>>choose;

        if (choose == 1)
        {
            cout<<"Enter the priority level: ";
            cin>>position;
            cout<<"Enter the data you want to put: ";
            cin.ignore();
            getline(cin,value);

            DL.Add_Task(value,position);
        }
        else if (choose == 2)
        {
            cout<<"Enter the task you want to complete: ";
            cin>>position;

            DL.Mark_as_Complete(position);
        }
        else if (choose == 3)
        {
            DL.Remove_Task();
        }
        else if (choose == 4)
        {
            DL.Display_Task();
        }
        else if(choose == 5)
        {}
    } while (choose != 5);
    
}