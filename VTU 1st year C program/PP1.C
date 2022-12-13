#include<stdio.h>
#include<conio.h>
int a[20],i,val,pos,n;

void create()
   {
     printf("Enter the number of elements to be inserted in array\n");
     scanf("%d",&n);
     for(i=0;i<n;i++)
     {
       scanf("%d",&a[i]);
     }
   }

void insert()
   {
     printf("Enter the position where the item has to be inserted:\n");
     scanf("%d",&pos);
     printf("Enter the item to be inserted\n");
     scanf("%d",&val);
     for(i=n-1;i>=pos;i--)
	{
	  a[i+1]=a[i];
	}
	a[pos]=val;
     n=n+1;
   }

void delet()
   {
     int i;
     printf("Enter the position of the element to be inserted\n");
     scanf("%d",&pos);
     val=a[pos];
     for(i=pos;i<n-1;i++)
     {
       a[i]=a[i+1];
     }
     n=n-1;
   }


void display()
   {
     int i;
     printf("The elements of array are\n");
     for(i=0;i<n;i++)
       {
	 printf("%d\t",a[i]);
       }
   }

void main()
   {
     int ch;
     clrscr();
     while(1)
	{
	  printf("\n____MENU___\n");
	  printf("1.CREATE\n2.INSERT\n3.DELETE\n4.DISPLAY\n5.EXIT\n");
	  printf(" ");
	  printf("Enter your choice\n");
	  scanf("%d",&ch);
	  switch(ch)
	     {
	       case 1: create(); break;
	       case 2: insert(); break;
	       case 3: delet(); break;
	       case 4: display();break;
	       case 5: exit(0); break;
	     }
	}
	getch();
   }