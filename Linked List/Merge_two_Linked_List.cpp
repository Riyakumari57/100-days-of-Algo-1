#include<bits/stdc++.h>
using namespace std;

struct node
{
   int data;
   struct node* link;

};


struct node* append(struct node* root);
void display(struct node* root);
void CombineLL(struct node **root1, struct node **root2);

int main()
{

  struct node  *root1=NULL; 
  struct node  *root2=NULL;


  root1=append(root1);
  cout<<endl;
  cout<<"First Linked List"<<endl;
  display(root1);
  cout<<endl;
  root2=append(root2);
  cout<<endl;
  cout<<"Second  Linked List"<<endl;
  display(root2);
  cout<<endl;

  CombineLL(&root1, &root2);
  cout<<"\nCombined  "<<endl;
        display(root1);

 return 0;
    
}
struct node* append(struct node* root)
{
  int n;
    struct node *temp;
    cout<<"Enter the nodes you want to add in  ll"<<endl;
    cin>>n;
    for(int i=0; i<n;i++)
    {
        
    temp=(struct node*)malloc(sizeof(struct node*));
    cout<<"enter the data you want to put in node\n"<<endl;
    cin>>temp->data;
    temp->link=NULL;
    if(root==NULL) 
      {
        root=temp;
      }
    else
    {
      struct node *p;
      p=root;
      while(p->link!=NULL)
      {
        p=p->link;
      }
      p->link=temp;
    }
     
  }
  return root;
}

  void display(struct node* root)
  {
    struct node *p;
    p=root;
    if(root==NULL)
     {
       printf("\nNo nodes in the list\n");
     }
    else
      {
       while(p!=NULL)
      {
        printf("%d-> ",p->data);
        p=p->link;
     }
    }
  }

 void CombineLL(struct node **root1, struct node **root2)
{
        struct node *p1, *p2, *pnext;
        p1=*root1;
        p2=*root2;
 
        if(p1==NULL) /*If first list is empty*/
        {
                *root1=*root2;
                *root2=NULL;
                return;
        }
        if(p2==NULL) /*If second list is empty*/
                return;
        while(p1->link!=NULL && p2!=NULL)
        {
                pnext = p1->link;
                p1->link = p2;
                p1 = pnext;
                pnext = p2->link;
                p2->link = p1;
                p2=pnext;
        }
        if(p1->link==NULL)
                p1->link = p2;
        *root2=NULL;
}
 

