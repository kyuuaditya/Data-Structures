#include <iostream>
using namespace std;

//create a structure called node which contains data and a pointer to the next element.
struct Node{
  int data;
  struct Node *next;
};

//create a push function for the linked list with which you can add values to the start of the list.
void push(struct Node** head,int node_data){
  struct Node* newNode=new Node;
  newNode->data=node_data;
  newNode->next=*head;
  *head=newNode;
}

//create a insert function with which we can add items to a specific position from the start of a linked list.
void insert(struct Node*prev_node,int node_data){
  if(prev_node==NULL){
    cout<<"Previous Node cannot be null";
  }
  struct Node* newNode=new Node;
  newNode->data= node_data;
  newNode->next= prev_node->next;
  prev_node->next= newNode;
}

//create a append function which will add elements to the end of the linked list.
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

//a function to delete any specific value in a linked list. just write it as "del(head,4);".
void del(struct Node*head,int del_data){
  if(head==NULL){
    cout<<"no Linked List Present"<<endl;
  }
  struct Node* removed=head;
  if(head->data==del_data){
    cout<<"text";
      *head=*head->next;
    return;
  }
  while((removed->next)->data!=del_data){
    removed=removed->next;
  }
  removed->next=removed->next->next;
}

//a funtion to display the elements of our linked list.
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

//main function
int main(){
  struct Node*head=NULL;

  //adding and removing values from the linked list.
  append(&head,5);
  push(&head,4);
  append(&head,6);
  push(&head,2);
  insert(head,3);
  push(&head,1);
  append(&head,8);
  insert(head->next->next->next->next,7);
  append(&head,9);
  insert(head->next->next->next,5);
  del(head,1);
  del(head,2);
  del(head,6);

  cout<<"Linked List as follows: "<<endl;

  displayList(head);
  return 0;
}