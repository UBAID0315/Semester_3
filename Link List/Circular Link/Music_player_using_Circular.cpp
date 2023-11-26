#include<iostream>
using namespace std;


class Node
{
    public:
        string data;
        Node *prev;
        Node *next;
        
        Node(string val) 
        {
            data = val;
            next = NULL;
            prev = NULL;
        }
};
class Circular_List
{
    int length;
    Node *head;
    Node *tail;
    public:
        Circular_List() 
        {
            length = 0;
            head = NULL;
            tail = NULL;
        }
        ~Circular_List()
        {
            Node *curr = head;
            
            do 
            {
                delete curr;  
                curr = curr->next; 
            } while (curr != head);
            
            head = nullptr;
        }
        int isEmpty()
        {
            if (length == 0)
            {
                return 0;
            }
        }
        void Insert_List(string val,int pos)
        {
            if(pos < 1 || pos > (length+1)) 
            {
                cout<<"Invalid position"<<endl;
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
        void Print_List()
        {
            if (isEmpty()) 
            {
                cout << "List is empty" << endl;
            }
            Node* curr = head;
            do 
            {
                cout << curr->data << " ";
                curr = curr->next;
            } while (curr != head);
            cout << endl;
        }

        void play_song()
        {  
            Node *curr = head;
            int choose;

            cout<<"Now playing..."<<endl;
            cout<<curr->data<<endl;
            curr = curr->next;
                
            while(1)
            {
                cout<<endl;
                cout<<"Which song you want to play"<<endl;
                cout<<"1) Next"<<endl;
                cout<<"2) Previous"<<endl;
                cout<<"3) Exit"<<endl;
                cin>>choose;

                if (choose == 1)
                {
                    next_song();
                }                    
                else if(choose == 2)
                {
                    previous_song();
                }
                else if(choose == 3)
                {
                    cout<<"Exiting the play song list"<<endl;
                }
            }
        }
        void next_song()
        {
            Node *curr = head;
            if(head->next != head)
            {
                head = head->next;
                cout<<"Now Playing"<<endl;
                cout<<head->data<<endl;
            }
        }
        void previous_song()
        {
            Node *curr = head;

            while(curr->next != head)
            {
                curr = curr->next;
            }
            head=curr;
            cout<<"Now Playing"<<endl;
            cout<<head->data<<endl;
        }
        void Update_List(int pos,string song_name)
        {
            Node *curr = head;
            
            for (int i = 1; i < pos ; i++)
            {
                curr = curr->next;
            }
            curr->data = song_name;
        }
        bool checkempty()
        {
            if (head == NULL)
            {
                // cout<<"List is empty"<<endl;
                return true;
            }
            else
            {
                return false;
            }
        }
        void Remove_List(int pos)
        {
            if(checkempty() == true)
            {
                cout<<"List is already empty"<<endl;
            }
            else if(pos < 1 || pos > length + 1)
            {
                cout<<"Invalid position"<<endl;
            }
            else if(checkempty() == false)
            {
                Node *curr = head;
                if(pos == 1)
                {
                    head = head->next;
                    delete curr;
                }
                else if(pos > 1)
                {
                    Node *slow = NULL;
                    for (int i = 1; i < pos; i++)
                    {
                        slow = curr;
                        curr = curr->next;
                    }
                    slow->next = curr->next;
                    delete curr;                   
                }
            }
            length --; 
        }
        void print()
        {
            if (head == NULL)
            {
                cout<<"Nothing is in the list"<<endl;
            }
            else
            {            
                Node *curr = head;
                cout<<endl;
                for (int i = 1; i <= length; i++)
                {
                    cout<<curr->data<<endl;
                    curr = curr->next;
                }
                cout<<endl;
            }
        }
        int search(string name)
        {
            Node *curr = head;
            for (int i = 1; i <= length; i++)
            {
                if (curr->data == name)
                {
                    return i;
                }
                curr = curr->next;
            }
            return 0;
        }
};
int main()
{
    Circular_List list;
    int get_pos,song_pos,choose;
    string song_name;
    
    while (true)
    {
        cout<<endl;
        cout<<"From the below option select any one "<<endl;
        cout<<"1) Add"<<endl;
        cout<<"2) Update"<<endl;
        cout<<"3) Remove"<<endl;
        cout<<"4) Print"<<endl;
        cout<<"5) Search"<<endl;
        cout<<"6) Play song"<<endl;
        cout<<"7) Exit"<<endl;
        cout<<endl;
        cout<<"Enter your option: ";
        cin>>choose;

        if (choose == 1)
        {
            cout<<"Enter the song position: ";
            cin>>song_pos;
            cout<<"Enter the song name: ";
            cin.ignore();
            getline(cin,song_name);
            list.Insert_List(song_name,song_pos);
        }
        else if(choose == 2)
        {
            cout<<"Enter the song position: ";
            cin>>song_pos;
            cout<<"Enter the song name: ";
            cin.ignore();
            getline(cin,song_name);
            list.Update_List(song_pos,song_name);
        }
        else if(choose == 3)
        {
            cout<<"Enter the song position: ";
            cin>>song_pos;
            list.Remove_List(song_pos);
        }
        else if(choose == 4)
        {
            list.print();
        }
        else if(choose == 5)
        {
            cout<<"Enter the song name: ";
            cin.ignore();
            getline(cin,song_name);
            get_pos = list.search(song_name);
            cout<<"Position found: "<<get_pos<<endl;
        }
        else if(choose == 6)
        {
            list.play_song();
        }
        else if(choose == 7)
        {
            cout<<"Play_list exiting"<<endl;
            break;
        }
    }
}