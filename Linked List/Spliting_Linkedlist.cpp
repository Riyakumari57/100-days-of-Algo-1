/* Program to Split single linked list into two halves in C Programming Language.*/
#include<bits/stdc++.h>
using namespace std;

void append();
void display(struct node *start);
int Split(struct node *start, struct node **start1);

struct node
{
        int data;
        struct node *link;
};

   struct node *root1=NULL,*root2=NULL;

int main()
{
    
      int n;
   cout<<"Enter the no of nodes you want to add"<<endl;
   cin>>n;
   for(int i =0;i<n;i++)
   {
       append();
   }
   
        display(root1);
 
        if(root1!=NULL)
    Split(root1, &root2);
        display(root1);
        display(root2);
 
        return 0;
 
}

int Split(struct node *start, struct node **start1)
{
        struct node *slow, *fast;
        if(start->link==NULL) /*only one element*/
                return 0;
 
        slow=fast=start;
 
        while(fast->link!=NULL && fast->link->link!=NULL)
        {
                slow = slow->link;
                fast = fast->link->link;
        }
        *start1 = slow->link;
        slow->link = NULL;
}

  void append()
  {
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node*));
    printf("enter the data you want to put in node\n");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(root1==NULL) 
      {
        root1=temp;
      }
    else
    {
      struct node *p;
      p=root1;
      while(p->link!=NULL)
      {
        p=p->link;
      }
      p->link=temp;
    }
  }
   
   void display(struct node *start)
{
        struct node *p;
        if(start==NULL)
        {
                printf("\nList is empty\n");
                return;
        }
        p=start;
        printf("\nList is :\n");
        while(p!=NULL)
        {
                printf("%d ",p->data);
                p=p->link;
        }
        printf("\n\n");
}