#include <iostream>
using namespace std;

struct Node{
  int data;
  struct Node *next;
};

void push(struct Node**head, int node_data){
  struct Node* newNode=new Node;
  newNode->data=node_data;
  newNode->next=*head;
  *head=newNode;
}

void pop(struct Node*head, int pop_data){
  if(head==NULL){
    cout<<"No element Left to pop."<<endl;
  }
  struct Node*removed =head;
  if(head->data==pop_data){
    *head=*head->next;
    return;
  }
  while((removed->next)->data!=pop_data){
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

  //adding and removing values from the linked list.
  push(&head,5);
  push(&head,4);
  push(&head,6);
  push(&head,2);
  push(&head,3);
  push(&head,1);
  push(&head,8);
  push(&head->next,7);
  push(&head,9);
  push(&head,10);
  pop(head,1);
  pop(head,2);
  pop(head,6);

  cout<<"Linked List as follows: "<<endl;

  displayList(head);
  return 0;
}