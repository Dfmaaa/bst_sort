//BST_sort.c

/*The purpose of this program is to demonstrate a sorting algorithm I wrote. It uses the left-root-right traversal algorithm
The tree we're going to use is a BST, which means there's a condition for insertion. Left child is smaller than parent.
Right child is bigger or equal to parent. That rule is the core of our sorting algorithm, we're actually sorting at insertion,
but we're not doing it in a human-readable format. The traversal algorithm we'll use solves that. We wont save the values in an array
because the sole purpose of this program is to prove that a BST with proper insertion is already sorted. The program has no other features like deletion, finding, etcetera. Only insertion and sorting.*/
#include <stdio.h>
#include <stdlib.h>
struct nd{
    int data;
    struct nd *right;
    struct nd *left;
};

typedef struct nd NODE;
void insert(NODE **, int);
void traverse(NODE *);

void insert(NODE **root,int data){
    if(*root==NULL){
        *root=(NODE*)malloc(sizeof(NODE));
        if(*root==NULL){
            puts("Memory can't be allocated for root node.");
            return;
        }
        (**root).data=data;
        (**root).left=NULL;
        (**root).right=NULL;
        puts("root node allocation was successful.");
        return;
    }
    NODE *current=*root;
    NODE *parent;
    while(1){
        parent=current;
        current=data>=(*current).data?(*current).right:(*current).left;
        if(current==NULL){
            current=(NODE*)malloc(sizeof(NODE));
            if(current==NULL){
                puts("Memory can't be allocated for node.");
                return;
            }
            (*current).data=data;
            (*current).right=NULL;
            (*current).left=NULL;
            int isRight=data>=(*parent).data;
            if(isRight){
                (*parent).right=current;
            }
            else{
                (*parent).left=current;
            }
            puts("\nValue inserted successfully.");
            return;
        }
    }
}
void traverse(NODE *root){    /*This is the krabby patty formula*/
    if(root!=NULL){
    traverse((*root).left);   
    printf("%d\t",(*root).data);
    traverse((*root).right);
    }
}
int main(void){
    NODE *root=NULL;
    int data;
    char ch;
    while(1){
        printf("Insert or sort?(I/S): ");
        scanf(" %c",&ch);
        if(ch=='I'){
            printf("\nEnter data: ");
            scanf("%d",&data);
            insert(&root,data);
        }
        if(ch=='S'){
            traverse(root);
            puts("\n");
        }
    }
}