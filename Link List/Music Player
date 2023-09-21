#include<iostream>
#include<cstring>
using namespace std;


class Node
{
    public:
        string data;
        Node *next;

        Node(string song)
        {
            data = song;
            next = NULL;
        }
};

class Linked_List
{
    private:
        Node *head;
        int length;
    public:
        Linked_List()
        {
            head = NULL;
            length = 0;
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

        void add(int pos, string song_name)
        {
            if(pos < 1 || pos > length + 1)
            {
                cout<<"Invalid position"<<endl;
            }
            if (checkempty() == true)
            {
                head = new Node(song_name);
                head->next = NULL;
            }
            else if(checkempty() == false)
            {
                Node *curr = new Node(song_name);
                if(pos == 1)
                {
                    curr->next = head;
                    head = curr;
                }
                else
                {
                    Node *curr = head;
                    for (int i = 1; i < (pos - 1); i++)
                    {
                        curr = curr->next;
                    }
                    Node *temp = new Node(song_name);
                    temp->next = curr->next;
                    curr->next = temp;
                }
            }
            length++;
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
        void remove(int pos)
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

        void update(int pos,string song_name)
        {
            Node *curr = head;
            
            for (int i = 1; i < pos ; i++)
            {
                curr = curr->next;
            }
            curr->data = song_name;
        }
        void play_song()
        {  
            string choose = "yes";
            Node *curr = head;
            
            for(int i=1;i <= length;i++)
            {
                if (choose != "no" || "No")
                {
                    cout<<"Now playing..."<<endl;
                    cout<<curr->data<<endl;
                    curr = curr->next;
                    
                    cout<<"Do you want to play the next song"<<endl;
                    cout<<"1) Yes"<<endl;
                    cout<<"2) No"<<endl;
                    cin>>choose;
                }
            }
            cout<<"Your selected playlist has been ended"<<endl;
        }
};

int main()
{
    Linked_List list;
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
            cout<<"Enter the song name: ";
            cin.ignore();
            getline(cin,song_name);
            cout<<"How much this song favourite to you"<<endl<<"1) Top Favorite;"<<endl<<"2) Least Favorite"<<endl<<"3) Some where between, let me specify the number"<<endl;
            cin>>song_pos;
            if (song_pos == 1)
            {
                list.add(song_pos,song_name);

                cout<<endl<<"Song added at your given location successfully"<<endl;
            }
            else if(song_pos == 2)
            {
                list.add(song_pos,song_name);
                cout<<endl<<"Song added at your given location successfully"<<endl;
            }
            else if(song_pos == 3||4||5)
            {
                cout<<"Enter song position: ";
                cin>>song_pos;
                if (song_pos != 1)
                {
                    list.add(song_pos,song_name);
                    cout<<endl<<"Song added at your given location successfully"<<endl;
                }
                else
                {
                    cout<<endl<<"Already booked"<<endl;
                }
            }
        }
        else if(choose == 2)
        {
            cout<<"Enter the song position: ";
            cin>>song_pos;
            cout<<"Enter the song name: ";
            cin.ignore();
            getline(cin,song_name);
            list.update(song_pos,song_name);
        }
        else if(choose == 3)
        {
            cout<<"Enter the song position: ";
            cin>>song_pos;
            list.remove(song_pos);
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
