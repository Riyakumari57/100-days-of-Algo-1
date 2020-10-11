
//Sorting a linked List by using Bubble Sort Algorithm

#include<bits/stdc++.h>
using namespace std;
int length();
void append();
void display();
void bubbleSort(int);

struct node
{
    int data;
    struct node* link;
};

struct node* root;
int main()
{
    int x , len =length();
   cout<<"*****WELCOME TO LINKED LIST*****\n"<<endl;
   while(1)
   {
       cout<<"1 for Append"<<endl;
       cout<<"2 for Display"<<endl;
       cout<<"3 for Sort"<<endl;
       cout<<"4 to quit"<<endl;
       cout<<"Enter your choice :\n"<<endl;
       cin>>x;

       switch(x)
       {
           case 1:append();
                  break;

            case 2:display();
                   break;
            
            case 3:bubbleSort(len);
                   break;

           case 4:cout<<"THANK YOU :)"<<endl;
                  exit(1);
          default:cout<<"WRONG INPUT :("<<endl;
                  break;
       }
   }

   return 0;
}

 void append()
  {
    struct node *temp;
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

   void display()
  {
    struct node *p;
    p=root;
    if(root==NULL)
    {
      cout<<"\nNo nodes in the list\n"<<endl;
    }
    else
    {
     while(p!=NULL)
     {
       cout<<p->data<<endl;
       p=p->link;
     }
    }
  }

  void bubbleSort(int n)
  {
      struct node *temp1,*temp2, *t, *root;
      for(int i=n-2;i>=0;i--)
	{
		temp1=root;
		temp2=temp1->link;
		for(int j=0;j<=i;j++)
		{
			if(temp1->data > temp2->data)
			{
				int k=temp1->data;
				temp1->data=temp2->data;
				temp2->data=k;
			}
			temp1=temp2;
			temp2=temp2->link;
		}
	}
	cout<<"Sorted order is: \n"<<endl;
	t=root;
	while(t!=NULL)
	{
		cout<<t->data<<endl;
		t=t->link;
	}
}
  

   int length()
  {
    int count=0;
    struct node *temp;
    temp=root;
    while(temp!=NULL)
    {
      count++;
      temp=temp->link;
    }
    return count;

