#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *left;
        Node *right;

        Node(int val)
        {
            data = val;
            left = NULL;
            right = NULL;
        }
};

class Binary_Tree
{
    private:
        Node *root;
        int value;
    public:
        Binary_Tree()
        {
            root = NULL;
        }
        ~Binary_Tree()
        {
            deletetree(root);
            cout<<"Tree deleted successfully"<<endl;
        }
        void deletetree(Node *root)
        {
            if (root == NULL)
            {
                cout<<"Nothing in the tree to delete"<<endl;
            }
            if(root->left != NULL)
            {
                deletetree(root->left);
            }
            if (root->right != NULL)
            {
                deletetree(root->right);
            }
            
            delete root;
            cout<<endl;
        }
        void Insert(int val)
        {
            root = insert(root,val);
        }
        void PrintInOrder()
        {
            InOrder(root);
        }
        void PrintPostOrder()
        {
            PostOrder(root);
        }
        void PrintPreOrder()
        {
            PreOrder(root);
        }
        void Checkempty()
        {
            bool check = CheckBST_empty_or_not(root);
            if (check == true)
            {
                cout<<endl;
                cout<<"Binary Search Tree is Empty"<<endl;
            }
            else
            {
                cout<<"Binary Search Tree is not Empty"<<endl;
            }
        }
        void Search_Node()
        {
            cout<<"Enter value to Search: ";
            cin>>value;
            bool searched_node = search_Node(root,value);

            if (searched_node == true)
            {
                cout<<endl;
                cout<<value<<" has been found in the tree"<<endl;
            }
            else
            {
                cout<<"Value not found"<<endl;
            }
        }
        void Delete_Node()
        {
            cout<<"Enter Value you want to DELETE: ";
            cin>>value;
            Node *node = deletenode(root,value);

            if (node != NULL)
            {
                delete node;
                cout<<"Node "<<value<<" has been deleted successfully"<<endl;
            }
            else 
            {
                cout<<"Node is not found in the tree"<<endl; 
            }
        }
        void Find_Parent(int value)
        {
            Node *parent = findparent(root,value);

            cout<<"Parent of "<<value<<" is "<<parent->data<<endl;
        }
        // void checkforDuplicates()
        // {
        //     Finding_Duplicates(root);
        // }

// ----------------------------------------------------------------------------------------
        Node* findparent(Node *root, int value)
        {
            if (root == NULL)
            {
                return NULL;
            }
            if ((root->left != NULL && root->left->data == value) ||
               (root->right != NULL && root->right->data == value))
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
        bool CheckBST_empty_or_not(Node *root)
        {
            if (root == NULL)
            {
                return true; 
            }
            return false;
        }
        bool search_Node(Node* root,int value)
        {
            if (root == NULL)
            {
                return false;
            }
            if (root->data == value)
            {
                return true;
            }

            if (root->data > value)
            {
                if (root->left != NULL)
                {
                    bool leftNode = search_Node(root->left,value);
                    return leftNode;
                }
            }
            bool rightNode = search_Node(root->right,value);
            return rightNode;
        }
        Node* deletenode(Node* root,int value)
        {
            if (root == NULL)
            {
                return NULL;
            }
            if (root->data == value)
            {
                return root;
            }

            if (value > root->data)
            {
                root->right = deletenode(root->right,value);
            }
            else if (value < root->data)
            {
                root->left = deletenode(root->left,value);
            }
            else
            {
        // Case 1 (parent with no child):

                if(root->right == NULL && root->left == NULL)
                {
                    return root;
                }
        
        // Case 2 (parent having only one child);
        
                else if (root->left != NULL && root->right == NULL)
                {
                    Node *parent_of_delete_node = findparent(root,value);
                    parent_of_delete_node = root->left;
                    return root;
                }
                else if (root->left == NULL && root->right != NULL)
                {
                    Node *parent_of_delete_node = findparent(root,value);
                    parent_of_delete_node = root->right;
                    return root;
                }

        // Case 3 (parent having two children):

                else if (root->left != NULL && root->right != NULL)
                {
                    Node *successor = FindInOrderSuccessor(root->right);
                    // Node *predesuccessor = FindInOrderPreDeSuccessor(root->left);

                    int successor_value = successor->data;
                    root = deletenode(root,successor->data);
                    root->data = successor_value;
                    return successor;
                }
                
            }
            return root;
        }
        Node *FindInOrderSuccessor(Node *root) 
        {
            if (root == nullptr) {
                return nullptr;
            }

            while (root->left != nullptr) 
            {
                root = root->left;
            }

            return root;
        }
        // Node *FindInOrderPreDeSuccessor(Node *root) 
        // {
        //     if (root == nullptr) {
        //         return nullptr;
        //     }

        //     while (root->right != nullptr) 
        //     {
        //         root = root->right;
        //     }

        //     return root;
        // }   
        Node* find_highest_gem(Node *root)
        {
            if (root == NULL)
            {
                return NULL;
            }

            Node* Max_value = root;

            Node *leftParent = find_highest_gem(root->left);
            if (leftParent != NULL && leftParent->data > Max_value->data)
            {
                Max_value = leftParent;
                return Max_value;
            }

            Node* rightParent = find_highest_gem(root->right);
            if (rightParent != NULL && rightParent->data > Max_value->data)
            {
                Max_value = rightParent;
            }
            return Max_value;
        }
        Node* search_by_value(Node* root, int val)
        {
            if (root == NULL)
            {
                return NULL;
            }
            if (root->data == val)
            {
                return root;
            }
            Node* rootleft = search_by_value(root->left,val);
            if (rootleft != NULL)
            {
                return rootleft;
            }
            Node* rootright = search_by_value(root->right,val);
            return rootright;
        }
        Node* insert(Node *root, int val)
        {
            if (root == NULL)
            {
                root = new Node (val);
                root->left = NULL;
                root->right = NULL;
            }
            else if(root != NULL)
            {
                if (val > root->data)
                {
                    root->right = insert(root->right,val);
                }
                else if(val < root->data)
                {
                    root->left = insert(root->left,val);
                }
                else if (val == root->data)
                {
                    cout<<"Duplication not ALLOWED!"<<endl;
                    return NULL;
                }
            }
            return root;
        }

        void InOrder(Node *root)
        {
            if (root != NULL)
            {
                InOrder(root->left);
                cout<<root->data<<" "<<endl;
                InOrder(root->right);
            }
        }
        void PostOrder(Node *root)
        {
            if (root != NULL)
            {
                PostOrder(root->left);
                PostOrder(root->right);
                cout<<root->data<<" "<<endl;
            }
        }
        void PreOrder(Node *root)
        {
            if (root != NULL)
            {
                cout<<root->data<<" ";
                PreOrder(root->left);
                PreOrder(root->right);
            }
        }
};

int main()
{
    Binary_Tree Tree;
    int choose,val,choice;

    Tree.Insert(50);
    Tree.Insert(30);
    Tree.Insert(70);
    Tree.Insert(40);
    Tree.Insert(10);
    Tree.Insert(60);
    Tree.Insert(20);
    Tree.Insert(5);

    while (choose != 8)
    {
        cout<<"Select the Option:"<<endl;
        cout<<"1. Traverse the node."<<endl;
        cout<<"2. Check BST empty or not"<<endl;
        cout<<"3. Search Node from the tree."<<endl;
        cout<<"4. Delete Node from the tree."<<endl;
        cout<<"5. Insert more Node"<<endl;
        cout<<"6. Find Parent of Node"<<endl;
        cout<<"7. Check the Duplicates"<<endl;
        cin>>choose;
        if (choose == 1)
        {
            cout<<"Which format you want to traverse: "<<endl;
            cout<<"1. PreOrder"<<endl;
            cout<<"2. PostOrder"<<endl;
            cout<<"3. InOrder"<<endl;
            cin>>choice;
            if (choice == 1)
            {
                cout<<endl;
                Tree.PrintPreOrder();
                cout<<endl;
            }
            else if (choice == 2)
            {
                cout<<endl;
                Tree.PrintPostOrder();
                cout<<endl;
            }
            else if (choice == 3)
            {
                cout<<endl;
                Tree.PrintInOrder();
                cout<<endl;
            }
            else
            {
                cout<<"Invalid"<<endl;
            }
        }
        else if (choose == 2)
        {
            Tree.Checkempty();   
        }
        else if (choose == 3)
        {
            Tree.Search_Node();
        }
        else if (choose == 4)
        {
            Tree.Delete_Node();
        }
        else if (choose == 5)
        {
            cout<<"Enter the value to insert: ";
            cin>>val;
            Tree.Insert(val);
        }
        else if (choose == 6)
        {
            int value;
            cout<<"Enter the Node value: ";
            cin>>value;

            Tree.Find_Parent(value);
        }
        else if (choose == 7)
        {
            // Tree.checkforDuplicates();
        }
        else
        {
            break;
        }
    }    
}
