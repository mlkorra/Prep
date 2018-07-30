
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of linked list is the following
struct node
{
int data;
Node* next;
};*/

#include <bits/stdc++.h>

int detectloop(Node *list)
{
   // your code here
   unordered_set<Node *> s;
   while(list!=NULL)
   {
     if(s.find(list)!=s.end()) return true;
     s.insert(list);
     list = list->next;
   }
   return false;
}