#include<iostream>
using namespace std;

struct Node 
{
    public:
        int data;
        Node *right;
        Node *left;
        int height;
        Node(int value)
        {
            data = value;
            left = NULL;
            right = NULL;
            height = 1;
        }
};
class AVL_Tree
{
    private:
        Node *root;
        int value,value2;
    public:
        AVL_Tree()
        {
            root = NULL;
        }
        ~AVL_Tree()
        {
            destroytree(root);
        }
        void Delete_Node()
        {
            cout<<"Enter the value: ";
            cin>>value;

            Node *deletedNode = delete_node(root,value);

            if (deletedNode != NULL)
            {
                delete deletedNode;
                cout<<"Node has been deleted successfully"<<endl;
            }
            else
            {
                cout<<"Nothing to delete"<<endl;
            }
        }
        void destroytree(Node *root)
        {
            if (root == NULL)
            {
                cout<<"Nothing Found to delete"<<endl;
            }
                
            destroytree(root->left);
            destroytree(root->right);
            delete root;
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
            Node* node = search_value(root, value);
            if (node == nullptr) 
            {
                return root;
            }

        if (node->left != nullptr && node->right != nullptr) 
        {
            Node* successor = node->right;
            while (successor->left != nullptr) 
            {
                successor = successor->left;
            }

            node->data = successor->data;
            node = successor;
        }

        Node* parent = findparent(root, node->data);
        if (node->left == nullptr) 
        {
            if (parent != nullptr) 
            {
                if (parent->left == node) 
                {
                    parent->left = node->right;
                } 
                else 
                {
                    parent->right = node->right;
                }
            }
        } 
        else 
        {
            if (parent != nullptr) 
            {
                if (parent->left == node) 
                {
                    parent->left = node->left;
                } 
                else 
                {
                    parent->right = node->left;
                }
            }
        }
            return rebalance(root);
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

        void Insert(int val)
        {
            root = insert(root,val);
        }
        void Search()
        {
            cout<<"Enter value you want to search: ";
            cin>>value;
            Node *condition = search_value(root,value);
            if (condition->data == value)
            {
                cout<<value<<" found in tree"<<endl;
            }
            else 
            {
                cout<<value<<" not found"<<endl;
            }
        }
        void Find_Parent(int value)
        {
            Node *parent = findparent(root,value);

            cout<<"Parent of "<<value<<" is "<<parent->data<<endl;
        }
        void PrintTree()
        {
            InOrder(root);
            cout<<endl;
        }
        void Update()
        {
            cout<<"Enter value you want to update: ";
            cin>>value;
            cout<<"Enter updation value: ";
            cin>>value2;
            
            bool updated_value = update_value(root,value,value2);
            if (updated_value)
            {
                cout<<"Value has been updated"<<endl;
            }
            else
            {
                cout<<"Number is not in the tree"<<endl;
            }
        }
        bool update_value(Node *root,int value,int value2)
        {
            if (root == NULL) 
            {
                return false;
            }
            if (root->data == value) 
            {
                root->data = value2;
                return true;
            }
            bool updatedLeft = update_value(root->left,value,value2);
            bool updatedRight = update_value(root->right,value,value2);

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
        Node *search_value(Node* root, int val)
        {
            if (root == NULL)
            {
                return 0;
            }
            if (root->data == val)
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
        Node* insert(Node *root, int val)
        {
            if (root == NULL)
            {
                root = new Node (val);
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

                root->height = 1+max(getHeight(root->left),getHeight(root->right));
                int balance = getBalance(root);

                if (balance > 1 && val < root->left->data)
                {
                    return rightRotate(root);
                }
                if (balance > 1 && val > root->left->data)
                {
                    root->left = leftRotate(root->left);
                    return rightRotate(root);
                }
                if (balance < -1 && val > root->right->data)
                {
                    return leftRotate(root);
                }
                if (balance < -1 && val < root->right->data)
                {
                    root->right = rightRotate(root->right);
                    return leftRotate(root);
                }
                return root;
            }
            return root;
        }
        void InOrder(Node *root)
        {
            if (root != NULL)
            {
                InOrder(root->left);
                cout << root->data << " ";
                InOrder(root->right);
            }
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
    int choose,val;

    while (choose != 7)
    {
        cout<<"Select the Option:"<<endl;
        cout<<"1. Insert"<<endl;
        cout<<"2. Search Node."<<endl;
        cout<<"3. Find Parent of Node"<<endl;
        cout<<"4. Print Tree"<<endl;
        cout<<"5. Update Value"<<endl;
        cout<<"6. Delete Value"<<endl;
        cin>>choose;
        if (choose == 1)
        {
            cout<<"Enter the value: ";
            cin>>val;
            A_Tree.Insert(val);
        }
        else if (choose == 2)
        {
            A_Tree.Search();
        }
        else if (choose == 3)
        {
            int value;
            cout<<"Enter the Node value: ";
            cin>>value;

            A_Tree.Find_Parent(value);
        }
        else if (choose == 4)
        {
            A_Tree.PrintTree();
        }
        else if (choose == 5)
        {
            A_Tree.Update();
        }
        else if (choose == 6)
        {
            A_Tree.Delete_Node();
        }
        
        else
        {
            break;
        }
    }    
    return 0;
}
