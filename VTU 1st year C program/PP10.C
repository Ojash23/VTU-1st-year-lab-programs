#include<stdio.h>
#include<conio.h>

struct bst
  {
    int info;
    struct bst *llink;
    struct bst *rlink;
  };
typedef struct bst *NODE;

NODE getnode()
   {
     NODE x;
     x=(NODE)malloc(sizeof(struct bst));
     if(x==NULL)
      {
       printf("Unsuccessful\n");
       exit(0);
      }
     return x;
   }

NODE create(int item,NODE root)
    {
      NODE temp,prev,cur;
      temp=getnode();
      temp->info=item;
      temp->rlink=NULL;
      temp->llink=NULL;
      if(root==NULL)
	return temp;
      prev=NULL;
      cur=root;
      while(cur!=NULL)
	 {
	   prev=cur;
	   if(cur->info==item)
	     {
	       printf("Same item can't be allocated\n");
	       free(temp);
	       return root;
	     }
	   else if(cur->info>item)
	      {
		cur=cur->llink;
	      }
	   else
	     cur= cur->rlink;
	 }
	if(prev->info>item)
	  prev->llink=temp;
	else
	  prev->rlink=temp;
	return root;
     }


void search(NODE  root)
   {
     int key;
     NODE cur;
     if(root==NULL)
       {
	 printf("Root is empty \n");
	 return;
       }
     printf("Enter the key to be searched\n");
     scanf("%d",&key);
     cur=root;
     while(cur!=NULL)
	{
	   if(cur->info==key)
	     {
	     printf("Key found in BST\n");
	     return;
	     }
	   else if(cur->info>key)
	     cur=cur->llink;
	   else
	     cur=cur->rlink;
	}
     printf("Key is not found in bst\n");
   }

void preorder(NODE root)
    {
      if(root!=NULL)
       {
	printf("%d\t",root->info);
	 preorder(root->llink);
	 preorder(root->rlink);
       }
    }


void inorder(NODE root)
    {
      if(root!=NULL)
       {
	 inorder(root->llink);
	 printf("%d\t",root->info);
	 inorder(root->rlink);
       }
    }

 void postorder(NODE root)
    {
     if(root!=NULL)
      {
       postorder(root->llink);
       postorder(root->rlink);
	printf("%d\t",root->info);
      }
    }

 void main()
 {
   int i,ch,n;
   NODE root=NULL;
   int item;
   clrscr();
   while(1)
       {
	  printf("\n____OPTIONS__\n");
	  printf("1.CREATE\n2.Traverse in all orders\n3.Search a key\n4.Exit\n");
	  printf(" ");
	  printf("Enter the choice\n");
	  scanf("%d",&ch);
	  switch(ch)
	     {
	       case 1: printf("Enter the number of elements\n");
		       scanf("%d",&n);
		       for(i=1;i<=n;i++)
			  {
			    printf("Enter the element\n");
			    scanf("%d",&item);
			    root = create(item,root);
			  }
		       break;
	       case 2: printf("Traversing Order are as follows:\n");
		       printf("Preorder:\n");
		       preorder(root);
		       printf("\nInorder:\n");
		       inorder(root);
		       printf("\nPostorder\n");
		       postorder(root);
		       break;

	       case 3: search(root);
		       break;
	       case 4: exit(0);
		       break;
	     }
       }
   getch();
 }