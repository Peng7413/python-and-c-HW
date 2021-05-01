#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node_s{
    int data;
    struct node_s *left;
    struct node_s *right;
}node_t;

void make_new(int data,node_t *root){
    int i=0,j=0;
    node_t *node=NULL;
    node_t *now=NULL;
    now=root;
    node=(node_t*)malloc(sizeof(node_t));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    while(1){
        if(now->data<data){
            if(now->right==NULL){
                now->right=node;
                break;
            }
            else if(now->right!=NULL){
                now=now->right;
            }
        }
        else if(now->data>=data){
            if(now->left==NULL){
                now->left=node;
                break;
            }
            else if(now->left!=NULL){
                now=now->left;
            }
        }
    }
}
void print_data(node_t *root){
    int i=0,j=0;
    node_t *now=NULL,*next=NULL;
    now=root;
    if(now->left!=NULL){
        next=now->left;
        print_data(next);
    }
    printf("%d ",now->data);
    if(now->right!=NULL){
        next=now->right;
        print_data(next);
    }
}
int main(){
    int n=0,i=0,j=0,s1=0;
    char order;
    node_t root;
    while(1){
        scanf("%c",&order);
        if(order=='p'){
            if(s1==0){
                printf("null\n");
            }
            else{
                print_data(&root);
                printf("\n");
            }
        }
        else if(order=='i'){
            scanf("%d",&n);
            if(s1==0){
                root.data=n;
                root.left=NULL;
                root.right=NULL;
                s1=1;
            }
            else
                make_new(n,&root);
        }
        else if(order=='e')
            break;
    }
    return 0;
}
