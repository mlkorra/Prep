/*
Reverse Linked List
*/

Node* reverse(Node *head)
{
  // Your code here
  Node *prev = NULL;
  Node *link;
  Node *curr = head;
  
  while(curr!=NULL){
      link = curr->next;
      curr->next = prev;
      prev = curr;
      curr = link;
  }
  
  head = prev;
  return head;
}