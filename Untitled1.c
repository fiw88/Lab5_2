#include<stdio.h>
#include<stdlib.h>
#define Size 7

struct  node
{
  int data;
  struct node *next;
};
struct node *hash_table[Size];   //array of pointer

void insertChain(int value)
{
  struct node *new_node;
  new_node= (struct node*) malloc(sizeof(struct node));
  new_node->data= value;
  new_node->next= NULL;
  new_node->next= hash_table[value%Size];
  hash_table[value%Size]= new_node;

}

void printChain()
{
    struct node *ptr;
    for(int i=0; i<Size; i++){
        printf("chain[%d]",i);
            ptr= hash_table[i];
            while(ptr!=NULL){
                printf("-->%d ",ptr->data);
                ptr= ptr->next;

            }
    printf("-->NULL\n");
    }
}

int search_item(int x)
{
    int count=1;
    struct node *ptr;
    ptr = hash_table[x%7];
    while(ptr!=NULL){
        if(ptr->data==x){
            return count;
        }
        count++;
        ptr= ptr->next;
    }
    return -1;
}

int main()
{
   int i;

   for(i=0;i<Size;i++)     //initialize a chained hash table
     hash_table[i]=NULL;

 insertChain(15);// 1
 insertChain(22);// 1
 insertChain(95);// 4
 insertChain(56);// 8
 insertChain(12);// 5
 insertChain(27);// 6
 insertChain(63);// 0
 insertChain(49);
 insertChain(24);
 printChain();
 printf("search 15-%d\n",search_item(15));
 printf("search 50-%d\n",search_item(50));
 printf("search 56-%d\n",search_item(56));

 return 0;
}
