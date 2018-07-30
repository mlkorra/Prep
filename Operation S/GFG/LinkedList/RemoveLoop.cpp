
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of linked list is the following
struct Node
{
int data;
Node* next; 
};*/
/*The function removes the loop from the linked list if present
You are required to complete this method*/
void removeTheLoop(Node *node)
{
     //Your code here
     
     /* Initially detect the Loop */
     unordered_set<Node *> s;
     Node* last;
     while(node!=NULL){
        
        if(s.find(node)==s.end()){
            s.insert(node);
            last = node;
            node = node->next;
        }
        /* Detected */
        else{
            /* Removed */
            last->next=NULL;
            node = node->next;
            break;
        }   
     }
}