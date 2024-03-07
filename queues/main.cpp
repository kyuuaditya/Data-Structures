#include <iostream>
using namespace std;

struct Node{
  struct Node *next;
  int data;
};

void push(struct Node** head, int node_data,int q){
  struct Node* last=*head;
  struct Node* nei=*head;
  while(last!=NULL){
    q--;
    last=last->next;
  }
  if(last->next==NULL&&q>0){
    struct Node* newNode=new Node;
    newNode->data=node_data;
    newNode->next=NULL;
    last->next=newNode;
  }
  if(last->next==NULL&&q==0){
    struct Node* newNode=new Node;
    newNode->data=node_data;
    newNode->next=NULL;
    last->next=newNode;
    *head=nei->next;
  }
}

void display(struct Node*node){
  while(node->next!=NULL){
    cout<<node->data<<"-->";
    node=node->next;
  }
  if(node->next==NULL){
    cout<<"node->data";
  }
}

int main(){
  int q=0;
  struct Node*head=NULL;
  push(&head,8,3);
  display(head);
}