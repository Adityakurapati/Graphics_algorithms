#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left, *right;
};

struct stack {
  struct node *T;
  struct stack *next;
};

struct node *root = NULL;

struct queue {
  struct node *data
  ;
  struct queue *next;
};

int emptystack(struct stack *top) { return (top == NULL); }

struct node *createNode(int data) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}

struct node *insert(struct node *root, int data) {
  if (root == NULL) {
    root = createNode(data);
    return root;
  } else if (data > root->data) {
    root->right = insert(root->right, data);
  } else {
    root->left = insert(root->left, data);
  }
  return root;
}

void push(struct node *Temp, struct stack **top) {
  struct stack *s = (struct stack *)malloc(sizeof(struct stack));
  s->next = *top;
  s->T = Temp;
  *top = s;
}

struct node *pop(struct stack **top) {
  if (emptystack(*top)) {
    return NULL;
  }

  struct stack *temp = *top;
  *top = (*top)->next;

  struct node *n = temp->T;
  free(temp);
  return n;
}

void print_tree(struct node *root) {
  if (root != NULL) {
    print_tree(root->left);
    printf("%d ", root->data);
    print_tree(root->right);
  }
}
struct node *mirror(struct node *root){
    struct stack *top =NULL;
    push(root,&top);

    while(!emptystack(top)){
        struct node *temp = pop(&top);

        if(temp!=NULL){
            struct node *tempLeft = temp->left;
            temp->left = temp->right;
            temp->right = tempLeft;

            push(temp->left,&top);
            push(temp->right,&top);
        }

    }
    return root;

}

struct node *findMin(struct node *root) {
  while (root->left != NULL) {
    root = root->left;
  }
  return root;
}

// Deletion
/*
struct node *deleteNode(struct node *root, int key) {
  struct node *temp;
  if (root == NULL) {
    return root;
  } else if (key < root->data) {
    root->left = deleteNode(root->left, key);
  } else if (key > root->data) {
    root->right = deleteNode(root->right, key);
  } else {
    // Node with only one child or no child
    if (root->left == NULL) {
      printf("Deleted Leaf Node or 1 child\n");
      temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      printf("Deleted Leaf Node or 1 child\n");
      temp = root->left;
      free(root);
      return temp;
    }

    // Node with two children
    temp = findMin(root->right);
    root->data = temp->data;
    root->right = deleteNode(root->right, temp->data);
    printf("Deleted Leaf Node or 1 child\n");
  }
  return root;
}
*/
struct node *BSTDelete(struct node *root,int value){
    struct node *temp = NULL;
    if(root == NULL){
        return;
    }else if(value < root->data){
        root->left  = BSTDelete(root->left , value);
    }else if(value > root->data){
        root->right  BSTDelete(root->right, value );
    }else{
        if(root->left == NULL){
            temp = root->right;
            free(root);
            return temp;
        }else if (root->right == NULL){
            temp = root->left;
            free(root);
            return temp;
        }
        else{
                // min of right part will be replaced with root element
            temp = findMin(root->right);
            root->data = temp->data;
            root->right = BSTDelete(root->right, temp->data);
        }
    }
        return root;

};

// Level-wise traversal
void levelOrderTraversal(struct node *root) {
  if (root == NULL)
    return;

  struct queue *front = NULL, *rear = NULL;

  // Enqueue the root
  struct queue *newNode = (struct queue *)malloc(sizeof(struct queue));
  newNode->data = root;
  newNode->next = NULL;
  front = rear = newNode;

  while (front != NULL) {
    struct node *current = front->data;

    // Print the front of the queue
    printf("%d ", current->data);

    // Enqueue left child
    if (current->left != NULL) {
      struct queue *newNode = (struct queue *)malloc(sizeof(struct queue));
      newNode->data = current->left;
      newNode->next = NULL;
      rear->next = newNode;
      rear = newNode;
    }

    // Enqueue right child
    if (current->right != NULL) {
      struct queue *newNode = (struct queue *)malloc(sizeof(struct queue));
      newNode->data = current->right;
      newNode->next = NULL;
      rear->next = newNode;
      rear = newNode;
    }

    // Dequeue the front
    struct queue *temp = front;
    front = front->next;
    free(temp);
  }
}


void levelOrderTraverse(struct node *root){
    Q = createQ();
    if(root != NULL){
        enqueue(root)
    }
    while(!emptyqueue()){
        root = deque(Q);
        printf("%d ",root);
        if(root->left != NULL){
            enqueue(root->left);
        }else{
            enqueue(root->right);
        }
    }
}
// For Calculating Height oF The Tree
int calculateHeight(struct node *root) {
  if (root == NULL) {
    return 0;
  } else {
    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);

    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
  }
}

// Display leaf nodes
void displayLeafNodes(struct node *root, char side) {
  if (root == NULL)
    return;

  if (root->left == NULL && root->right == NULL) {
    printf("Leaf Node on %c side: %d\n", side, root->data);
    return;
  }

  if (root->left != NULL) {
    displayLeafNodes(root->left, 'L');
  }

  if (root->right != NULL) {
    displayLeafNodes(root->right, 'R');
  }
}

int main(void) {
  root = insert(root, 10);
  root = insert(root, 50);
  root = insert(root, 20);
  root = insert(root, 40);
  root = insert(root, 34);

  printf("Displaying the binary search tree:\n");
  print_tree(root);

  printf("\n\nMirror Image : ");
  print_tree(mirror(root));
  printf("\n");

  // Calling Deletion
  root = deleteNode(root, 50); // Update the root after deletion
  printf("\nAfter Deletion:\n");
  print_tree(root);

  // Level-wise traversal
  printf("\n\nLevel-wise Traversal:\n");
  levelOrderTraversal(root);

  // Calculate and display the height
  int height = calculateHeight(root);
  printf("\n\nHeight of the tree: %d\n", height);

  // Display leaf nodes
  printf("\nLeaf Nodes:\n");
  displayLeafNodes(root, ' ');
  return 0;
}
