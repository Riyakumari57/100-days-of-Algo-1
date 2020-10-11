//  Program to find merge point of two single linked lists 
/*   Merge point is made when the end node of one of the linked list got linked to the second list,
     forming an inverted Y shaped list.

     The first common point from where the sharing of nodes starts is called Merge point .
 
 Time Complexity = O(m+n)
 Space Complexity =O(1)
 */

#include <bits/stdc++.h> 
using namespace std; 

void createMergeNode();
int findMergepoint(struct node* root1, struct node* root2);
int length(struct node* root);
void display(struct node* root);

/* Link list node */

struct node 
{ 
public: 
    int data; 
    node* link; 
};

struct node* root1 =NULL ,*root2=NULL;

int main()
{
   createMergeNode();
   cout<<"First Linked List :"<<endl;
   display(root1);
   cout<<endl;
  cout<<"Second Linked List :"<<endl;
   display(root2);
   cout<<endl;
   cout<<endl<<endl;
   cout << "The Merged Point is at is " <<findMergepoint(root1,root2);
}

void createMergeNode()
{
    struct node *temp, *p, *q;
 //(1st node of first linked list)
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=34;
    root1=temp;
    p=temp;
//(2nd node of first linked list)
     temp=(struct node*)malloc(sizeof(struct node));
     temp->data=45;
     p->link=temp;
     p=p->link;
//(3rd node of first linked list)
    temp=(struct node*)malloc(sizeof(struct node));
     temp->data=67;
     p->link=temp;
     p=p->link;
    

//(1st node of second linked list)
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=44;
    root2=temp;
    q=temp;

//(2nd node of second  linked list)
     temp=(struct node*)malloc(sizeof(struct node));
     temp->data=10;
     q->link=temp;
     q=q->link;

//(3rd node of second linked list)
     temp=(struct node*)malloc(sizeof(struct node));
     temp->data=60;
     q->link=temp;
     q=q->link;

//(4th node of second linked list)
     temp=(struct node*)malloc(sizeof(struct node));
     temp->data=100;
     q->link=temp;
     q=q->link;

//Merged nodes
temp=(struct node*)malloc(sizeof(struct node));
     temp->data=33;
     p->link=q->link=temp;
     p=p->link;

temp=(struct node*)malloc(sizeof(struct node));
     temp->data=77;
     p->link=temp;
     p=p->link;

temp=(struct node*)malloc(sizeof(struct node));
     temp->data=15;
     temp->link=NULL;
     p->link=temp;
     


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
     cout<<"NULL";
    }
  }
int findMergepoint(struct node* root1, struct node* root2)
{
    struct node* p =root1;
    struct node* q= root2;
   int m = length(root1);
   int n = length(root2);
   if(m>n)/*If first list is longer*/
        {
                int d=m-n;
                for(int i=1;i<=d;i++)
                        p=p->link;
        }
        else if(m<n)/*If second list is longer*/
        {
                int d=n-m;
                for(int i=1;i<=d;i++)
                        q=q->link;
        }

         while(p!=NULL && q!=NULL)
        {
                if(p==q)
                        return p->data;       /*Merge point found*/
                p=p->link;
                q=q->link;
        }
        return -1;    /*Lists don't merge*/
}/*End of Find_mergePoint()*/


int length(struct node* root)
{
    int len = 0;
    while(root!=NULL)
    {
        len++;
    root=root->link;
    }
    return len;

}