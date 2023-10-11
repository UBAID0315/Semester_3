#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;

struct Node
{
    public:
        string data;
        Node *next;
        Node(string val)
        {
            data = val;
            next = NULL;
        }
};

class Circular_List
{
    private:
        Node *head;
        int length;
    public:
        Circular_List()
        {
            head = NULL;
            length = 0;
        }
        void Insert(string val,int pos)
        {
            if(pos < 1 || pos > (length+1)) 
            {
                cout<<"Invalid position"<<endl;
                return;
            }
            
            Node *n = new Node(val);
            if(pos == 1) 
            {
                if(head == NULL)
                {
                    head = n;
                    head->next = head;
                }
                n->next = head;
                Node *curr = head;
                while(curr->next != head) 
                {
                    curr = curr->next;
                }
                curr->next = n;
                head = n;
            } 
            else 
            { 
                Node *curr = head;
                for(int i=1; i<(pos-1); i++) 
                {
                    curr=curr->next;
                }
                Node *temp = new Node(val);
                temp->next = curr->next;
                curr->next = temp;
            }
            length++;
        }
        void show()
        {
            Node *curr = head;
            static int count = 1;

            for (int i = 1; i < count; i++)
            {
                curr = curr->next;
            }
            cout<<curr->data<<endl;
            count++;
        }
        void Start_Game()
        {
            int random;
            string player_name;

                srand(time(NULL));
                random = (rand() % length) + 1;
                cout<<"Random no: "<<random<<endl; 

                Node *curr = head;
                Node *curr_prev = NULL;

                if(random == 1)
                {
                    do
                    {
                        curr_prev = curr;
                        curr = curr->next;
                    } 
                    while (curr_prev->next != head);
                    
                    head = head->next;
                    curr_prev->next = head;
                    curr->next = NULL;
                    player_name = curr->data;
                    delete curr;
                }
                else if(random == length)
                {
                    for (int i = 0; i < random - 1; i++)
                    {
                        curr_prev = curr;
                        curr = curr->next;
                    }
                    
                    curr_prev->next = head;
                    player_name = curr->data;
                    curr->next = NULL;
                    delete curr;
                }
                else
                {
                    for(int i=0 ; i < random - 1; i++)
                    {
                        curr_prev = curr;
                        curr = curr->next;
                    }
                    curr_prev->next = curr->next;
                    player_name = curr->data;
                    delete curr;
                }
            length--;
            print(player_name);
        }
        void print(string player_name)
        {
            cout<<endl;
            cout<<player_name<<" has been removed from the game"<<endl;     

            Node *curr = head;
            if (length != 1)
            {
                cout<<endl;
                cout<<"Current players in the game: "<<endl;
                do
                {
                    cout<<curr->data<<" ";
                    curr = curr->next;
                
                }while(curr != head);
            }
            else if(length == 1)
            {
                cout<<"Winner: "<<curr->data<<endl;
            }
        }
};

int main()
{
    Circular_List C;
    int choose,choice;

    C.Insert("ubaid",1);
    C.Insert("sarmad",2);
    C.Insert("khizar",3);
    C.Insert("Fariba",4);
    C.Insert("Ashar",5);

    while (choose != 3)
    {
        cout<<endl;

        cout<<"1. Traverse players one by one"<<endl;
        cout<<"2. Start Game"<<endl;
        cout<<"3. Exit"<<endl;
        cin>>choose;
        if (choose == 1)
        {
            C.show();
            while (choice != 2)
            {
                cout<<"Show: "<<endl;
                cout<<"1. Next"<<endl;
                cout<<"2. Go to main menu"<<endl;
                cin>>choice;
                if(choice == 1)
                {
                    C.show();
                }
                else if(choice == 2)
                {
                    break;
                }
            }
            cout<<endl;
        }
        else if(choose == 2)
        {
            C.Start_Game();
            cout<<endl;
        }
        else if(choose == 3)
        {
            cout<<"Program exiting..."<<endl;
            break;
        }
    }
}
