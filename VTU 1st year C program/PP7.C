#include<stdio.h>
#include<conio.h>

struct node
    {
       char name[20];
       char usn[10];
       char branch[4];
       int sem;
       long int phno;
       struct node *link;
    };
typedef struct node *NODE;

NODE temp,first=NULL;
int count=0;

NODE getnode()
   {
    NODE p;
    p=(NODE)malloc(sizeof(struct node));
    p->link=NULL;
    if(p==NULL)
      printf("Unsuccessful memory allocation");
    else
     {
      count++;
     }
      return p;
   }

void read()
   {
     temp=getnode();
     printf("Enter the name of the student:\n");
     scanf("%s",temp->name);
     printf("Enter the usn of the student:\n");
     scanf("%s",temp->usn);
     printf("Enter the branch of the student:\n");
     scanf("%s",temp->branch);
     printf("Enter the sem of the student:\n");
     scanf("%d",&temp->sem);
     printf("Enter the phone number: \n");
     scanf("%ld",&temp->phno);
   }

void create_SLL()
    {
      int i,n;
      printf("Enter the number of students\n");
      scanf("%d",&n);
      for(i=0;i<n;i++)
	{
	  printf("Enter the details of the student\n");
	  insert_front();
	}
    }

void display()
    {
      if(first==NULL)
	{
	  printf("No students are there and count is 0");
	  return;
	}
      temp=first;
      printf("The details of student are :\nNAME\tUSN\t\tBRANCH\tSEM\tPHONE NUMBER\n");
      while(temp->link!=NULL)
	  {
	    printf("%s\t%s\t%s\t%d\t%ld\t\n",temp->name,temp->usn,temp->branch,temp->sem,temp->phno);
	    temp=temp->link;
	  }
	printf("%s\t%s\t%s\t%d\t%ld\t\n",temp->name,temp->usn,temp->branch,temp->sem,temp->phno);
	printf("Total number of students : %d",count);
    }

NODE insert_front()
    {
      printf("Enter the details of the student\n");
      read();
      if(first==NULL)
	{
	  first=temp;
	  return temp;
	}
     temp->link=first;
     return temp;
    }

NODE insert_rear()
    {
      NODE cur;
      printf("Enter the details of the student\n");
      read();
      if(first==NULL)
	{
	  first=temp;
	  return temp;
	}
      cur=first;
      while(cur->link!=NULL)
	  {
	    cur=cur->link;
	  }
      cur->link=temp;
      return first;
    }

void del_front()
    {
     if(first==NULL)
       {
	 printf("The list is empty\n");
       }
      printf("The deleted element is : \t %s\t%s\t%s\t%d\t%ld\t",first->name,first->usn,first->branch,first->sem,first->phno);
      first=first->link;
      free(first);
      count--;
    }

void del_rear()
    {
     NODE prev,cur;
     if(first==NULL)
       {
	 printf("The list is empty\n");
       }
     prev=NULL;
     cur=first;
     while(cur->link!=NULL)
	 {
	   prev=cur;
	   cur=cur->link;
	 }
       printf("%s\t%s\t%s\t%d\t%ld\t",cur->name,cur->usn,cur->branch,cur->sem,cur->phno);
       free(cur);
       count--;
       prev->link=NULL;
    }

void main()
   {
     int ch;
     clrscr();
     while(1)
      {
       printf("\n___Options____\n");
       printf("1.CREATE SLL\n2.DISPLAY\n3.INSERT FRONT\n4.INSERT REAR\n5.DELETE FRONT\n6.DELETE REAR\n7.EXIT\n");
       printf(" ");
       printf("Enter the choice:\t");
       scanf("%d",&ch);
       switch(ch)
	  {
	    case 1: first= create_SLL(); break;
	    case 2: display(); break;
	    case 3: first= insert_front();break;
	    case 4: first= insert_rear(); break;
	    case 5: del_front();break;
	    case 6: del_rear();break;
	    case 7: exit(0); break;
	    default: printf("\nInvalid choice\n");
	  }
      }
   }