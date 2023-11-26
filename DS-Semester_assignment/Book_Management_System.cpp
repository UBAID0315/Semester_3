#include<iostream>
using namespace std;

class Date
{
    private:
        int day;
        int month;
        int year;
    public:
        Date(int d,int m,int y)
        {
            day = d;
            month = m;
            year = y;
        }
        int getday()
        {   
            return day;
        }
        int getmonth()
        {
            return month;
        }
        int getyear()
        {
            return year;
        }
        void setdate(int d,int m,int y)
        {
            day = d;
            month = m;
            year = y;
        }
        void getdate()
        {
            cout<<"Day: "<<getday()<<"Month: "<<getmonth()<<"Year: "<<getyear()<<endl;
        }
};
class Book_node
{
    private:
        int ISBN_number;
        string author;
        string title;
        string genre;
        Date date;
    public:
        Book_node *next;        // next pointer
        Book_node *prev;        // prev pointer

        Book_node(int no,string author_name,string title,string genre,int day,int month,int year):date(day,month,year)
        {
            ISBN_number = no;
            author = author_name;
            this->title = title;
            this->genre = genre;
            next = NULL;
            date.setdate(day,month,year);
        }
        int get_ISBNumber()
        {
            return ISBN_number;
        }
        string get_author()
        {
            return author;
        }
        string get_title()
        {
            return title;
        }
        string get_genre()
        {
            return genre;
        }
        Date getdate()
        {
            return date;
        }
};
class Duble_Linklist
{
    private:
        int length;
        Book_node *head;
    public:
        Duble_Linklist()
        {
            head = nullptr;
            length = 0;
        }
        ~Duble_Linklist()
        {
            Book_node *start = head;

            for (int i = 0; i < length; i++)
            {
                if (head->next != nullptr)
                {
                    head = head->next;
                }
                if (head != nullptr)
                {
                    head->prev = nullptr;
                }
                delete start;
                start = head;
            }
            cout<<"Shelf Deleted Successfully"<<endl;
        }
        void Insert_Book(int b_no, string author_name, string title, string genre, int newday, int newmonth, int newyear) 
        {
            Book_node *temp = head;
            while (temp != nullptr)
            {
                if(temp->get_ISBNumber() == b_no)
                {
                    cout<<"Error! not more than one book have the same id number"<<endl;
                    return;
                }
                temp = temp->next;
            }

            Book_node* newNode = new Book_node(b_no, author_name, title, genre, newday, newmonth, newyear);

            if (head == NULL || newyear < head->getdate().getyear() || 
                (newyear == head->getdate().getyear() && newmonth < head->getdate().getmonth()) ||
                (newyear == head->getdate().getyear() && newmonth == head->getdate().getmonth() && newday <= head->getdate().getday()))
            {   
                newNode->next = head;
                if (head != NULL)
                {
                    head->prev = newNode;
                }
                head = newNode;
            }
            else
            {
                Book_node *temp = head;

                while (temp->next && (newyear > temp->next->getdate().getyear() || 
                    (newyear == temp->next->getdate().getyear() && newmonth > temp->next->getdate().getmonth()) ||
                    (newyear == temp->next->getdate().getyear() && newmonth == temp->next->getdate().getmonth() && newday > temp->next->getdate().getday())))
                {
                    temp = temp->next;
                }
                
                newNode->next = temp->next;
                newNode->prev = temp;
                if (temp->next != nullptr)
                {
                    temp->next->prev = newNode;
                }
                temp->next = newNode;
                
            }
            cout<<"Book Added"<<endl;
            length++;
        }

        void print_List()
        {
            Book_node *temp = head;
            int count=0;

            while (temp != NULL)
            {
                cout<<"(---------Book "<<count+1<<" details---------)"<<endl<<endl;
                cout<<"ISBN: "<<temp->get_ISBNumber()<<endl;
                cout<<"Title: "<<temp->get_title()<<endl;
                cout<<"Author: "<<temp->get_author()<<endl;
                cout<<"Genre: "<<temp->get_genre()<<endl;
                cout<<"Publish Date: "<<temp->getdate().getday()<<" / "<<temp->getdate().getmonth()<<" / "<<temp->getdate().getyear()<<endl<<endl;

                temp = temp->next;
                count++;
            }
        }

        void Filter_Book()
        {
            string author_name;
            Book_node *temp = head;
            int i = 0;

            cout<<"Enter the author's Name: ";
            cin>>author_name;

            while (temp != nullptr)
            {
                if (author_name == temp->get_author())
                {
                    cout<<endl;
                    cout<<"(---------Book "<< i+1 <<" Details---------)"<<endl<<endl;
                    cout<<"ISBN: "<<temp->get_ISBNumber()<<endl;
                    cout<<"Title: "<<temp->get_title()<<endl;
                    cout<<"Author: "<<temp->get_author()<<endl;
                    cout<<"Genre: "<<temp->get_genre()<<endl;
                    cout<<"Publish Date: "<<temp->getdate().getday()<<" / "<<temp->getdate().getmonth()<<" / "<<temp->getdate().getyear()<<endl<<endl;
                }
                temp = temp->next;
                i++;
            }
            temp = NULL;
        }

        void Search(string B_name)
        {
            Book_node *temp = head;

            while (temp != NULL)
            {
                if (temp->get_title() == B_name)
                {
                    cout<<"(---------Book Details---------)"<<endl;
                    cout<<"ISBN: "<<temp->get_ISBNumber()<<endl;
                    cout<<"Title: "<<temp->get_title()<<endl;
                    cout<<"Author: "<<temp->get_author()<<endl;
                    cout<<"Genre: "<<temp->get_genre()<<endl;
                    cout<<"Publish Date: "<<temp->getdate().getday()<<" / "<<temp->getdate().getmonth()<<" / "<<temp->getdate().getyear()<<endl<<endl;
                }
                temp = temp->next;
            }
        }

        void RecommendBooks()
        {
            string Book_name;
            Book_node *temp = head;

            cout<<"Enter any book name: ";
            cin>>Book_name;
            
            while (temp != nullptr)
            {
                if (Book_name == temp->get_title())
                {
                    string genre = temp->get_genre();
                    Book_node *temp2 = head;

                    if (genre == temp2->get_genre())
                    {
                        cout<<endl;
                        cout<<"(---------Book Details---------)"<<endl<<endl;
                        cout<<"ISBN: "<<temp->get_ISBNumber()<<endl;
                        cout<<"Title: "<<temp->get_title()<<endl;
                        cout<<"Author: "<<temp->get_author()<<endl;
                        cout<<"Genre: "<<temp->get_genre()<<endl<<endl; 
                    }
                    temp2 = temp2->next;
                }
                temp = temp->next;
            }
        }

        bool DeleteBOOk()
        {
            int number;
            Book_node *temp=head;

            cout<<"Enter ISBN number to (delete): ";
            cin>>number;

            while (temp != nullptr)
            {
                if(temp->get_ISBNumber() == number)
                {
                    // Delete first node
                    if (temp->next != nullptr && temp == head)
                    {
                        head = head->next;
                        if (head != nullptr)
                            head->prev = nullptr;
                        delete temp;
                        temp = NULL;
                    }
                    // Delete last node
                    else if (temp->next == nullptr && temp != head)
                    {
                        temp->prev->next = NULL;
                        delete temp;
                        temp = nullptr;
                    }
                    // Deletion btw two nodes
                    else
                    {
                        temp->prev->next = temp->next;
                        temp->next->prev = temp->prev;
                        delete temp;
                    }
                    length--;
                    return true; 
                }
                temp = temp->next;
            }
            return false;
        }
};
int main()
{  
    Duble_Linklist Shelf;
    int choose,number,day,month,year;
    string author_name,title,genre,Book_name;

    while (choose != 7)
    {
        cout<<endl;
        cout<<"Choose the Option: "<<endl;
        cout<<"1. Add a Book"<<endl;
        cout<<"2. Search the Book"<<endl;
        cout<<"3. Filter Book by Author"<<endl;
        cout<<"4. Recommend Related Books"<<endl;
        cout<<"5. Delete a Book"<<endl;
        cout<<"6. Print the sequence of Books"<<endl;
        cout<<"7. Exit"<<endl;
        cin>>choose;

        if (choose == 1)
        {
            cout<<"Enter the ISBN number: "<<endl;
            cin>>number;
            cout<<"Enter Aurthor: "<<endl;
            cin.ignore();
            getline(cin,author_name);
            cout<<"Enter Book Title: "<<endl;
            getline(cin,title);
            cout<<"Enter Book Genre: "<<endl;
            getline(cin,genre);
            cout<<"Enter Publication Date"<<endl;
            cout<<"\t Enter Day: ";
            cin>>day;
            if (day > 0 && day <= 31)
            {
                cout<<"\t Enter Month: ";
                cin>>month;
                if (month > 0 && month <= 12)
                {
                    cout<<"\t Enter Year: ";
                    cin>>year;
                    if (year >= 1990 && year <= 2023)
                    {
                        Shelf.Insert_Book(number,author_name,title,genre,day,month,year);
                    }
                    else
                    {
                        cout<<"Invalid Year"<<endl;
                    }
                }
                else
                {
                    cout<<"Invalid Month"<<endl;
                }
            }
            else
            {
                cout<<"Invalid Day"<<endl;
            }
        }
        else if (choose == 2)
        {
            cout<<"Enter Book-Title you want to search: ";
            cin>>Book_name;
            Shelf.Search(Book_name);
        }
        else if (choose == 3)
        {
            Shelf.Filter_Book();   
        }
        else if (choose == 4)
        {
            Shelf.RecommendBooks();
        }
        else if(choose == 5)
        {
            bool condition = Shelf.DeleteBOOk();
            if(condition == true)
                cout<<"Book Deleted"<<endl;
            else 
                cout<<"Error while Book Deletion"<<endl;
        }
        else if (choose == 6)
        {
            Shelf.print_List();
        }
        else if (choose == 7)
        {
            break;
        } 
    }
}

// if (!head || year < head->getdate().getyear() ||
//                 (year == head->getdate().getyear() && month < head->getdate().getmonth()) ||
//                 (year == head->getdate().getyear() && month == head->getdate().getmonth() && day <= head->getdate().getday())) {
//                 // Insert at the beginning of the list
//                 newNode->next = head;
//                 if (head) {
//                     head->prev = newNode;
//                 }
//                 head = newNode;
//             } else {
//                 Book_node* temp = head;

//                 while (temp->next && (year > temp->next->getdate().getyear() ||
//                                     (year == temp->next->getdate().getyear() && month > temp->next->getdate().getmonth()) ||
//                                     (year == temp->next->getdate().getyear() && month == temp->next->getdate().getmonth() && day > temp->next->getdate().getday()))) {
//                     temp = temp->next;
//                 }

//                 newNode->next = temp->next;
//                 newNode->prev = temp;
//                 if (temp->next) {
//                     temp->next->prev = newNode;
//                 }
//                 temp->next = newNode;
//             }