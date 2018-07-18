Node *BuildTreeHelper(int in[],int pre[],int inStrt,int inEnd,int &j)
{
    if(inStrt > inEnd){
        return NULL;
    }
    
    j++;
    int i;
    for(i=inStrt;i<=inEnd;i++){
        if(in[i]==pre[j]) break;
    }
    Node *head = newNode(pre[j]);
    head->left = BuildTreeHelper(in,pre,inStrt,i-1,j);
    head->right = BuildTreeHelper(in,pre,i+1,inEnd,j);

    return head;
}

Node* buildTree(int in[],int pre[], int inStrt, int inEnd)
{
//add code here.
  int j=-1;
  return BuildTreeHelper(in,pre,inStrt,inEnd,j);
}