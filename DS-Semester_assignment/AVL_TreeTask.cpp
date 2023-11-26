#include<iostream>
using namespace std;


struct Trunk 
{
    Trunk* prev;
    string str;

    Trunk(Trunk* prev, string str) {
        this->prev = prev;
        this->str = str;
    }
};
class Employee
{
    private:
        int Id;
        string name;
        string designation;
    public: 
        void setvalues(string name,int id,string designation)
        {
            Id = id;
            this->name = name;
            this->designation = designation;
        }
        int get_ID()
        {
            return Id;
        }
        string get_Name()
        {
            return this->name;
        }
        string get_Designation()
        {
            return this->designation;
        }
        void set_ID(int newid)
        {
            Id = newid;
        }
};
struct Node 
{
    public:
        Employee data;
        Node *right;
        Node *left;
        int height;
        Node(string name,int id,string designation)
        {
            data.setvalues(name,id,designation);
            left = NULL;
            right = NULL;
            height = 1;
        }
};
class AVL_Tree
{
    private:
        Node *root;
        string updated_name,updated_designation;
        int id;
    public:
        AVL_Tree()                                              // Constructor
        {
            root = NULL;
        }
        ~AVL_Tree()
        {
            destroytree(root);
        }
        void destroytree(Node *root)                            // Destructor's Function
        {
            if (root != nullptr) 
            {   
                destroytree(root->left);
                destroytree(root->right);
                delete root;
            }
            cout<<"Tree Deleted Successfully"<<endl;     
        }
        void PrintTree()
        {
            printTree(root, 0); 
        }
        void Delete_Node()
        {
            cout<<"Enter the Employee id: ";
            cin>>id;

            Node *deletedNode = delete_node(root,id);
            cout<<"Node has been deleted"<<endl<<endl;
            printTree(deletedNode,0);
        }
        int max(int a, int b)
        {
            if (a > b)
            {
                return a;
            }
            return b;
        }
        Node* delete_node(Node* root, int value) 
        {
            if (root == NULL)
                return root;
        
            if (value < root->data.get_ID())
            {
                root->left = delete_node(root->left, value);
            }
            else if(value > root->data.get_ID())
            {
                root->right = delete_node(root->right, value);
            }
            else
            {
                // node with only one child or no child
                if( (root->left == NULL) ||
                    (root->right == NULL) )
                {
                    Node *temp = root->left ? root->left : root->right;
        
                    if (temp == NULL)                                               // No child case
                    {
                        temp = root;
                        root = NULL;
                    }
                    else                                                           // One child case
                    {
                        *root = *temp;
                    }                                                            
                    delete temp;
                                // the non-empty child
                }
                else
                {
                    Node* temp = findSuccessor(root->right);     // node with two children
 
                    root->data.get_Designation() = temp->data.get_Designation();
                    root->data.get_Name() = temp->data.get_Name();
                    root->right = delete_node(root->right,value);
                    root->data.set_ID(temp->data.get_ID());
                }
            }
        
            // If the tree had only one node
            if (root == NULL)
                return root;
            root->height = 1 + max(height(root->left),height(root->right));
            int balance = getBalance(root);
        
            // Left Left Case
            if (balance > 1 && getBalance(root->left) >= 0)
                return rightRotate(root);
        
            // Left Right Case
            if (balance > 1 && getBalance(root->left) < 0)
            {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
        
            // Right Right Case
            if (balance < -1 && getBalance(root->right) <= 0)
                return leftRotate(root);
        
            // Right Left Case
            if (balance < -1 && getBalance(root->right) > 0)
            {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
        
            return root;
        }
        int height(Node *root)
        {
            if (root == NULL)
                return -1;
            return root->height;
        }
        Node *findSuccessor(Node* root)
        {
            Node *current = root;
        
            /* loop down to find the leftmost leaf */
            while (current->left != NULL)
                current = current->left;
        
            return current;
        }
        int get_balance_factor(Node *node) 
        {
            if (node == nullptr) 
            {
                return 0; 
            }

            int left_height = getHeight(node->left);
            int right_height = getHeight(node->right);

            return left_height - right_height;
        }

        Node* rebalance(Node* root)
        {
            int balance_factor = get_balance_factor(root);

        
            if (balance_factor > 1) 
            {
                if (get_balance_factor(root->left) >= 0) 
                {
                    root = rightRotate(root);
                } 
                else 
                {
                    root->left = leftRotate(root->left);
                    root = rightRotate(root);
                }
            } 
            else if (balance_factor < -1) 
            {
                if (get_balance_factor(root->right) <= 0) {
                root = leftRotate(root);
            } 
            else 
            {
                root->right = rightRotate(root->right);
                root = leftRotate(root);
            }
        }

            update_heights(root);

            return root;
        }
        void update_heights(Node* node) 
        {
            if (node == nullptr) 
            {
                return;
            }

            int left_height = getHeight(node->left);
            int right_height = getHeight(node->right);

            node->height = 1 + max(left_height, right_height);

            update_heights(node->left);
            update_heights(node->right);
        }

        void Insert(string name, int id, string designation)
        {
            root = insert(root,name,id,designation);
        }
        void Search()
        {
            cout<<"Enter employee ID you want to search: ";
            cin>>id;
            Node *condition = search_value(root,id);
            if (condition->data.get_ID() == id)
            {
                cout<<"Employee Name: "<<condition->data.get_Name()<<endl;
                cout<<"Employee Id: "<<condition->data.get_ID()<<endl;
                cout<<"Employee Designation: "<<condition->data.get_Designation()<<endl;
            }
            else 
            {
                cout<<endl<<id<<" not found"<<endl;
            }
        }
        void Find_Parent(int value)
        {
            Node *parent = findparent(root,value);

            cout<<"Parent of "<<value<<" is "<<parent->data.get_ID()<<endl;
        }
        void printTree(Node *root, int level) 
        {
            if (root == NULL) {
                return;
            }

            for (int i = 0; i < level; i++) 
            {
                cout << " ";
            }
            
            cout<<"Employee Id: "<<root->data.get_ID()<<endl;
            cout<<"Employee Name: "<<root->data.get_Name()<<endl;
            cout<<"Employee Designation: "<<root->data.get_Designation()<<endl<<endl;

            if (root->left != NULL) 
            {
                cout << "  ";
                for (int i = 0; i < level; i++) 
                {
                    cout << "-";
                }
                cout << "L: ";
                printTree(root->left, level + 2);
            }

            if (root->right != NULL) 
            {
                cout << "  ";
                for (int i = 0; i < level; i++) 
                {
                    cout << "-";
                }
                cout << "R: ";
                printTree(root->right, level + 2);
            }
        } 
        void Update(string name,string designation)
        {
            cout<<"Enter Updated_Employee Name: ";
            cin>>updated_name;
            cout<<"Enter Updated_Designation: ";
            cin>>updated_designation;
            
            bool updated_value = update_value(root,name,designation,updated_name,updated_designation);
            if (updated_value)
            {
                cout<<"Value has been updated"<<endl;
            }
            else
            {
                cout<<"Number is not in the tree"<<endl;
            }
        }
        bool update_value(Node *root,string name,string designation,string updated_name,string updated_designation)
        {
            if (root == NULL) 
            {
                return false;
            }
            if (root->data.get_Name() == name && root->data.get_Designation() == designation) 
            {
                root->data.setvalues(updated_name,root->data.get_ID(),updated_designation);
                return true;
            }
            bool updatedLeft = update_value(root->left,name,designation,updated_name,updated_designation);
            bool updatedRight = update_value(root->right,name,designation,updated_name,updated_designation);

            return updatedLeft || updatedRight;
        }
        int getHeight(Node* root) 
        {
            if (root == NULL) 
            {
                return 0;
            }
            return root->height;
        }
        int getBalance(Node* root) 
        {
            if (root == NULL) {
                return 0;
            }
            return getHeight(root->left) - getHeight(root->right);
        }
        Node* findparent(Node *root, int value)
        {
            if (root == NULL)
            {
                return NULL;
            }
            if ((root->left != NULL && root->left->data.get_ID() == value) ||
               (root->right != NULL && root->right->data.get_ID() == value))
            {
                return root;
            }

            Node *leftParent = findparent(root->left,value);
            if (leftParent != NULL)
            {
                return leftParent;
            }

            Node* rightparent = findparent(root->right,value);
            return rightparent;
        }
        Node *search_value(Node* root, int val)
        {
            if (root == NULL)
            {
                return 0;
            }
            if (root->data.get_ID() == val)
            {
                return root;
            }
            
            if (root->left != NULL)
            {
                Node* rootleft = search_value(root->left,val);
            }
            
            Node* rootright = search_value(root->right,val);
            return rootright;
        }
        Node* insert(Node *root, string name, int id, string designation)
        {
            if (root == NULL)
            {
                root = new Node(name,id,designation);
            }
            else if(root != NULL)
            {
                if (id > root->data.get_ID())
                {
                    root->right = insert(root->right,name,id,designation);
                }
                else if(id < root->data.get_ID())
                {
                    root->left = insert(root->left,name,id,designation);
                }
                else if (id == root->data.get_ID())
                {
                    cout<<"Duplication not ALLOWED!"<<endl;
                    return NULL;
                }

                root->height = 1+max(getHeight(root->left),getHeight(root->right));
                int balance = getBalance(root);

                if (balance > 1 && id < root->left->data.get_ID())
                {
                    return rightRotate(root);
                }
                if (balance > 1 && id > root->left->data.get_ID())
                {
                    root->left = leftRotate(root->left);
                    return rightRotate(root);
                }
                if (balance < -1 && id > root->right->data.get_ID())
                {
                    return leftRotate(root);
                }
                if (balance < -1 && id < root->right->data.get_ID())
                {
                    root->right = rightRotate(root->right);
                    return leftRotate(root);
                }
                return root;
            }
            return root;
        }
        Node *leftRotate(Node *root)
        {
            Node *child = root->right;
            Node *subchild = child->left;

            child->left = root;
            root->right = subchild;

            root->height = 1 + max(getHeight(root->left),getHeight(root->right));
            child->height = 1 + max(getHeight(child->left),getHeight(child->right));

            return child;
        }
        Node *rightRotate(Node *root)
        {
            Node *child = root->left;
            Node *subchild = child->right;

            child->right = root;
            root->left = subchild;

            root->height = 1 + max(getHeight(root->left),getHeight(root->right));
            child->height = 1 + max(getHeight(child->left),getHeight(child->right));

            return child;
        }
};

int main()
{
    AVL_Tree A_Tree;
    int choose,id;
    string name,designation;

    while (1)
    {
        cout<<"Select the Option:"<<endl;
        cout<<"1. Insert"<<endl;
        cout<<"2. Search For Employee."<<endl;
        cout<<"3. Generate Organizational Chart"<<endl;
        cout<<"4. Modify Employee Information"<<endl;
        cout<<"5. Remove Employee Information"<<endl;
        cout<<"6. Exit Program"<<endl;
        cin>>choose;
        if (choose == 1)
        {
            cout<<"Enter Employee Name: ";
            cin>>name;
            cout<<"Enter Employee Id: ";
            cin>>id;
            cout<<"Enter Employee Designation: ";
            cin>>designation;
            A_Tree.Insert(name,id,designation);
        }
        else if (choose == 2)
        {
            A_Tree.Search();
        }
        else if (choose == 3)
        {
            A_Tree.PrintTree();
        }
        else if (choose == 4)
        {
            A_Tree.Update(name,designation);
        }
        else if (choose == 5)
        {
            A_Tree.Delete_Node();
        }
        else if(choose == 6)
        {
            break;
        }
        else 
        {
            cout<<"Invalid choice"<<endl;
        }
    }    
    return 0;
}