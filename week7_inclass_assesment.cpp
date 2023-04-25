#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// create a new node
struct node *newNode(int val){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// find minimum in the BST
struct node *findMin(struct node *root) {
    if(root == NULL or root->left == NULL){
        return root;
    }
    return findMin(root->left);
}


// Inorder traversal
void traverseInOrder(struct node *root) {
    if(root == NULL){
        return;
    }
    traverseInOrder(root->left);
    cout << root->key << ' ';
    traverseInOrder(root->right);
}

// Insert a node
struct node *insertNode(struct node *root, int key) {
    struct node *temp = newNode(key);
    
    if(root == NULL){
        root = temp;
    }
    else if( key < root->key){
        root->left = insertNode( root->left, key);
    }
    else{
        root->right = insertNode( root->right, key);
    }
    return root;
}


// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    if(root == NULL){
        return root;
    }
    else if (key < root->key)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = deleteNode(root->right, key);
    }
    else if(root->left == NULL && root->right == NULL){
        delete root;
        root = NULL;
        return root;
    }
    else if(root->right == NULL){
        struct node *temp = root;
        root = temp->left;
        delete temp;
    }
    else if(root->left == NULL){
        struct node *temp = root;
        root = temp->right;
        delete temp;
    }
    else{
        struct node *temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
        delete temp;
    }
    return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}
