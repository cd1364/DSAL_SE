/*
Name : Daphal Chaitanya Ramdas
Class : SE IT
Div : A
Batch : A
Roll no. : 25015
Assignment No. 5 : Binary Search Tree
*/

#include<iostream>
using namespace std;

struct bstnode
{
   int data;
   struct bstnode *left, *right;
};

struct bstnode *newNode(char v)
{
    bstnode* temp = new bstnode();
    temp->data = v;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct bstnode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

struct bstnode* insert(struct bstnode* node, int key)
{
    if (node == NULL) return newNode(key);
    if (key < node->data)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
   return node;
}

struct bstnode* search(struct bstnode* root, int key)
{
    if (root == NULL || root->data == key)
        return root;

    // Key is greater than root's key
    if (root->data < key)
       return search(root->right, key);
    else
        return search(root->left, key);
}

struct bstnode * minValueNode(struct bstnode* node)
{
    struct bstnode* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct bstnode* deleteNode(struct bstnode* root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
   else
    {

        if (root->left == NULL)
        {
            struct bstnode *temp = root->right;
            free(root);
            return temp;
        }

        else if (root->right == NULL)
        {
            struct bstnode *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            struct bstnode* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
   return root;
}

void mirror(struct bstnode* node)
{
    if (node == NULL)
        return;
    else
    {
        struct bstnode* temp;
        mirror(node->left);
        mirror(node->right);

        temp= node->left;
        node->left = node->right;
        node->right = temp;
    }
}

struct bstnode* copy(struct bstnode *root)
{
    bstnode *root2;
    if(root==NULL)
        return NULL;
    root2=new bstnode;
    root2->left=copy(root->left);
    root2->right=copy(root->right);
    root2->data=root->data;

    return root2;
}
int Maxdepth(struct bstnode *root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        int depth1=Maxdepth(root->left);
        int depth2=Maxdepth(root->right);
        if(depth1>depth2)
            return (depth1+1);
        else
            return (depth2+1);

    }
}

int main()
{
    struct bstnode *root = NULL;
    struct bstnode *root2=NULL;
    struct bstnode *root1=NULL;
    struct bstnode *root3=NULL;
    int ch,n,d,depth;
    while(1)
    {
        cout<<"\n****************MENU*************************";
        cout<<endl<<"1.INSERT";
        cout<<endl<<"2.DELETE";
        cout<<endl<<"3.SEARCH";
        cout<<endl<<"4.TRAVERSAL";
        cout<<endl<<"5.DEPTH OF BST";
        cout<<endl<<"6.COPY OF BST";
        cout<<endl<<"7.MIRROR IMAGE";
        cout<<endl<<"8.EXIT";
        cout<<"\n********************************************";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"\nEnter number of values to insert: ";
                cin>>n;
                cout<<"\nEnter the values to create BST: ";
                for(int i=0; i<n; i++)
                {
                    cin>>d;
                    root = insert(root, d);
                }
                break;
            case 2:
                cout<<"\nEnter the element to delete: ";
                cin>>d;
                root3=deleteNode(root, d);
                break;
            case 3:
                cout<<"\nEnter the element to search: ";
                cin>>d;
                root1=search(root, d);
                if(root1!=NULL)
                    cout<<"\nFound in BST!!";
                else
                    cout<<"\nNot Found in BST!!";
                break;
            case 4:
                cout<<"\nTraversal of BST: ";
                inorder(root);
                break;
            case 5:
                depth=Maxdepth(root);
                cout<<"The depth of BST is: "<<depth;
                break;
            case 6:
                root2=copy(root);
                cout<<"The copy of BST is: ";
                inorder(root2);
                break;
            case 7:
                mirror(root);
                cout <<"\nInorder traversal of the mirror BST is: ";
                inorder(root);
                mirror(root);
                break;
            case 8:
                return 0;
            default:
                cout<<"\nWrong Option";
        }
    }
    return 0;
}

/*

OUTPUT :

****************MENU*************************
1.INSERT
2.DELETE
3.SEARCH
4.TRAVERSAL
5.DEPTH OF BST
6.COPY OF BST
7.MIRROR IMAGE
8.EXIT
********************************************
Enter your choice: 1

Enter number of values to insert: 5

Enter the values to create BST: 98
75
63
48
10

****************MENU*************************
1.INSERT
2.DELETE
3.SEARCH
4.TRAVERSAL
5.DEPTH OF BST
6.COPY OF BST
7.MIRROR IMAGE
8.EXIT
********************************************
Enter your choice: 2

Enter the element to delete: 10

****************MENU*************************
1.INSERT
2.DELETE
3.SEARCH
4.TRAVERSAL
5.DEPTH OF BST
6.COPY OF BST
7.MIRROR IMAGE
8.EXIT
********************************************
Enter your choice: 3

Enter the element to search: 70

Not Found in BST!!
****************MENU*************************
1.INSERT
2.DELETE
3.SEARCH
4.TRAVERSAL
5.DEPTH OF BST
6.COPY OF BST
7.MIRROR IMAGE
8.EXIT
********************************************
Enter your choice: 3

Enter the element to search: 75

Found in BST!!
****************MENU*************************
1.INSERT
2.DELETE
3.SEARCH
4.TRAVERSAL
5.DEPTH OF BST
6.COPY OF BST
7.MIRROR IMAGE
8.EXIT
********************************************
Enter your choice: 4

Traversal of BST: 48 63 75 98
****************MENU*************************
1.INSERT
2.DELETE
3.SEARCH
4.TRAVERSAL
5.DEPTH OF BST
6.COPY OF BST
7.MIRROR IMAGE
8.EXIT
********************************************
Enter your choice: 5
The depth of BST is: 4
****************MENU*************************
1.INSERT
2.DELETE
3.SEARCH
4.TRAVERSAL
5.DEPTH OF BST
6.COPY OF BST
7.MIRROR IMAGE
8.EXIT
********************************************
Enter your choice: 6
The copy of BST is: 48 63 75 98
****************MENU*************************
1.INSERT
2.DELETE
3.SEARCH
4.TRAVERSAL
5.DEPTH OF BST
6.COPY OF BST
7.MIRROR IMAGE
8.EXIT
********************************************
Enter your choice: 7

Inorder traversal of the mirror BST is: 98 75 63 48
****************MENU*************************
1.INSERT
2.DELETE
3.SEARCH
4.TRAVERSAL
5.DEPTH OF BST
6.COPY OF BST
7.MIRROR IMAGE
8.EXIT
********************************************
Enter your choice: 8

*/