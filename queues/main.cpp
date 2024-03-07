#include <iostream>
using namespace std;

struct Node{
  struct Node *next;
  int data;
};

void push(struct Node** head, int node_data,int q){
  struct Node* last=*head;
  struct Node* nei=*head;
  if(*head==NULL){
  struct Node* newNode= new Node;
  newNode->data=node_data;
  newNode->next=*head;
  *head=newNode;
  }else{
    while(last->next!=NULL){
      q--;
      last=last->next;
    }
      struct Node* newNode=new Node;
      newNode->data=node_data;
      newNode->next=NULL;
      last->next=newNode;
    if(q==1){
      **head=*(nei->next);
    }
  } 
}

void display(struct Node*node){
  while(node->next!=NULL){
    std::cout<<node->data<<"<--";
    node=node->next;
  }
  if(node->next==NULL){
    cout<<node->data;
  }
}

int main(){
  int q=0;
  struct Node*head=NULL;
  push(&head,8,3);
  push(&head,9,3);
  push(&head,1,3);
  push(&head,0,3);
  push(&head,19,3);
  display(head);
}