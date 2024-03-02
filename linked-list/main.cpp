#include <iostream>
using namespace std;

struct Node{
  int data;
  struct Node *next;
};

void push(struct Node** head,int node_data){
  struct Node* newNode=new Node;
  newNode->data=node_data;
  newNode->next=*head;
  *head=newNode;
}

void insert(struct Node*prev_node,int node_data){
  if(prev_node==NULL){
    cout<<"Previous Node cannot be null";
  }
  struct Node* newNode=new Node;
  newNode->data= node_data;
  newNode->next= prev_node->next;
  prev_node->next= newNode;
}

void append(struct Node**head,int node_data){
  struct Node* newNode= new Node;
  
  struct Node* last=*head;

  newNode->data=node_data;
  newNode->next=NULL;

  if(*head==NULL){
    return;
  }
  while(last->next!=NULL){
    last=last->next;
  }

  last->next=newNode;
  return;
}

void del(struct Node*head,int del_data){
  if(head==NULL){
    cout<<"no Linked List Present"<<endl;
  }
  struct Node* removed=head;
  if(head->data==del_data){
    if(head->next!=NULL){
      head->next=head;
    }
    return;
  }
  while((removed->next)->data!=del_data){
    removed=removed->next;
  }
  removed->next=removed->next->next;
}

void displayList(struct Node*node){
  while(node!=NULL)
  {
    cout<<node->data<<"-->";
    node=node->next;
  }

  if(node==NULL){
    cout<<"null";
  }
}

int main(){
  struct Node*head=NULL;
  append(&head,5);
  push(&head,4);
  append(&head,6);
  push(&head,2);
  insert(head,3);
  push(&head,1);
  append(&head,8);
  cout<<"test";
  insert(head->next->next->next->next,7);
  append(&head,9);
  insert(head->next->next->next,5);
  del(head,1);

  cout<<"Linked List as follows: "<<endl;

  displayList(head);
  return 0;
}