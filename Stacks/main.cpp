#include <iostream>

//structure of the node for Stacks
struct Node{
  struct Node* next;
  int data;
};

//adding a new data to  the stack
void add(struct Node** head, int new_data){
  struct Node* newNode= new Node;
  newNode->data=new_data;
  newNode->next=*head;
  *head=newNode;
}

void pop(struct Node* head){
  head=head->next;
}

void display(struct Node*node){
  while(node->next!=NULL){
    std::cout<<node->data<<"->";
    node=node->next;
  }
  if(node->next==NULL){
    std::cout<<node->data;
  }
}

int main(){
  struct Node*head=NULL;
  add(&head,10);
  add(&head,5);
  add(&head,4);
  pop(head);
  display(head);
}