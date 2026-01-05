#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data, height;
    struct Node *left, *right;
};
int height(struct Node* node) { 
    return node ? node->height : 0; 
}
int getBalance(struct Node* node) { 
    return node ? height(node->left) - height(node->right) : 0; 
}
struct Node* newnode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value; 
    node->height = 1;
    node->left = node->right = NULL;
    return node;
}
struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left, *T2 = x->right;
    x->right = y; y->left = T2;
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    return x;
}
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right, *T2 = y->left;
    y->left = x; x->right = T2;
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    return y;
}
struct Node* insertNode(struct Node* node, int value) {
    if (!node) return newnode(value);
    if (value < node->data) 
           node->left = insertNode(node->left, value);
    else if (value > node->data) 
          node->right = insertNode(node->right, value);
    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));
    int balance = getBalance(node);
    if (balance > 1 && value < node->left->data) 
             return rightRotate(node);
    if (balance < -1 && value > node->right->data) 
             return leftRotate(node);
    if (balance > 1 && value > node->left->data) { 
        node->left = leftRotate(node->left); 
        return rightRotate(node); 
    }
    if (balance < -1 && value < node->right->data) { 
        node->right = rightRotate(node->right); 
        return leftRotate(node); 
    }
    return node;
}
void preOrder(struct Node* root) {
    if (root) {
            printf("%d ", root->data);
            preOrder(root->left);
            preOrder(root->right);
    }
}
void inOrder(struct Node* root) {
    if (root) { 
        inOrder(root->left); 
        printf("%d ", root->data); 
        inOrder(root->right); 
    }
}
void postOrder(struct Node* root) {
    if (root) { 
        postOrder(root->left); 
        postOrder(root->right); 
        printf("%d ", root->data); 
    }
}
int main() {
    struct Node* root = NULL;
    int n, value;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        root = insertNode(root, value);
    }
    printf("Preorder Traversal: ");
    preOrder(root);
    printf("\n");

    printf("Inorder Traversal: ");
    inOrder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postOrder(root);
    printf("\n");

    return 0;
}
