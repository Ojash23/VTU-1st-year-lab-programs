#include<stdio.h>
#include<conio.h>

struct node
     {
      char name[20];
      char ssn[10];
      char dept[5];
      int sal;
      long int phno;
      struct node *llink;
      struct node *rlink;
     };
typedef struct node *NODE;

NODE start=NULL;
int count=0;

NODE create()
   {
    NODE p;
    p=(NODE)malloc(sizeof(struct node));
    if(p==NULL)
      {
       printf("Unsuccessful\n");
       exit(0);
      }
    printf("Enter the name:\n");
    scanf("%s",p->name);
      printf("Enter the  SSN \n");
    scanf("%s",p->ssn);
      printf("Enter the following: Dept\n");
    scanf("%s",p->dept);
      printf("Enter the following: salary\n");
    scanf("%d",&p->sal);
      printf("Enter the phone number\n");
    scanf("%ld",&p->phno);
    p->llink=NULL;
    p->rlink=NULL;
    count++;
    return p;
   }

NODE insert_front()
    {
      NODE temp;
      temp=create();
      if(start==NULL)
	return temp;
      temp->rlink=start;
      start->llink=temp;
      return temp;
    }

void del_front()
   {
     NODE temp;
     if(start==NULL)
      {
	printf("The list is empty");
      }
     else
       {
	 temp=start;
	 start = start->rlink;
	 temp->rlink=NULL;
	 start->llink=NULL;
	 printf("The deleted ssn is : %s",temp->ssn);
	 free(temp);
	 count--;
       }
   }

NODE insert_rear()
    {
      NODE temp,cur;
      temp=create();
      if(start==NULL)
	return temp;
      cur=start;
      while(cur->rlink!=NULL)
	  {
	    cur=cur->rlink;
	  }
      cur->rlink=temp;
      temp->llink=cur;
      return start;
    }

void del_rear()
    {
      NODE cur,prev;
      if(start==NULL)
	{
	  printf("The D list is empty\n");
	}
      else if(start->rlink==NULL)
	{
	   printf("The deleted ssn is : %s",start->ssn);
	   free(start);
	   count--;
	}
      else
	{
	  prev=NULL;
	  cur=start;
	  while(cur->rlink!=NULL)
	       {
		 prev=cur;
		 cur=cur->rlink;
	       }
	     printf("The deleted ssn is : %s",cur->ssn);
	     free(cur);
	     count--;
	     prev->rlink=NULL;
	}
    }


void display()
   {
     int num =1;
     NODE cur;
     if(start==NULL)
      {
       printf("NOTHING TO DISPLAY\n");
      }
     else
     {
     cur=start;
     printf("The following details are: \nNo.\tNAME\tSSN\tDEPT\tSalary\tphone number\n");
     while(cur->rlink!=NULL)
	  {
	    printf("%d\t%s\t%s\t%s\t%d\t%ld\n",num,cur->name,cur->ssn,cur->dept,cur->sal,cur->phno);
	    cur= cur->rlink;
	    num++;
	  }
	printf("Total number of employees:\t %d",count);
     }
   }

void insertendfront()
   {
     int ch;
     printf("1.INSERT AT END\n2.DELETE at END\n");
     printf("Enter the choice\n");
     scanf("%d",&ch);
     switch(ch)
	  {
	    case 1: insert_rear();break;
	    case 2: del_rear();break;
	  }
   }

void dequeue()
  {
   int ch;
   while(1)
      {
	printf("\n___OPTIONS___\n");
	printf("1.INSERT FRONT\n2.INSERT REAR\nDELETRE FRONT\nDELETE REAR\n");
	printf("Enter the choice\n");
	scanf("%d",&ch);
	switch(ch)
	    {
	      case 1:start= insert_front(); break;
	      case 2: start= insert_rear(); break;
	      case 3: del_front();break;
	      case 4: del_rear(); break;
	    }
      }
  }

void main()
   {
     int ch;
     clrscr();
     while(1)
       {
	printf("\n___OPTIONS___\n");
	printf("1.CREATE\n2.DISPLAY\n3.Insertion and deletion at end\n4.DEQUEUE\n");
	printf("Enter the choice\n");
	scanf("%d",&ch);
	switch(ch)
	  {
	   case 1:start = create(); break;
	   case 2: display(); break;
	   case 3: insertendfront(); break;
	   case 4: dequeue(); break;
	   case 5: exit(0); break;
	  }
       }
       getch();
   }