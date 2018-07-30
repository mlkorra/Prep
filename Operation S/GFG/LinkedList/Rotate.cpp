
int findlen(struct node *head)
{
    int n(0);
    while(!head){
        head = head->next;
        n++;
    }
    return n;
}

void printLL(struct node *head,int n)
{
    while(!head)
    {
        cout << head->data << " ";
    }
    cout << "\n";
}

void rotate(struct node **head_ref, int k)
{ 
  // Complete this method
  int n = findlen(*head_ref);
  int i(0);
  struct node *temp = *head_ref;
  struct node *end;
  struct node *first_head = temp;
  while(!temp){
      end = temp;
      temp = temp->next;
      i++;
      if(i==k) break;
  }
  
  struct node* new_head = temp;
  
  /* Breaking and Fixing */
  struct node* middle = new_head;
  while(!middle){
      middle = middle->next;
  }
  
  end->next = NULL;
  middle->next = *head_ref;
  *head_ref = new_head;

  //printLL(new_head,n);
}