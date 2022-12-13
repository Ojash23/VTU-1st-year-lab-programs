#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 100

int  create(int num)
   {
     int key;
     key = num%MAX;
     return key;
   }


void display(int a[MAX])
  {
    int ch,i;
    printf("1. FULL DISPLAY\n2.FILTERED DISPLAY\n");
    printf("Enter your choice:\n");
    scanf("%d",&ch);
    if(ch==1)
      {
	printf("The contents are:\n");
	for(i=0;i<MAX;i++)
	   {
	      printf("%d\t",a[i]);
	   }
      }
      else
      {
	for(i=0;i<MAX;i++)
	if(a[i]!=-1)
	  {
	    printf("%d\t",a[i]);
	  }
      }
  }

void linear_probe(int a[MAX],int num, int key)
   {
      int count=0,flag=0,i;
	   if(a[key]==-1)
	     {
	       a[key]=num;
	     }
	   else
	    {
	      printf("Collision detected....!!\n");
	      i=0;
	      while(i<MAX)
		  {
		    if(a[i]!=-1)
		      count++;
		    i++;
		  }
	      if(count==MAX)
		{
		  printf("Hash Table is full\n");
		  display(a);
		  exit(0);
		}
	      for(i=key+1;i<MAX;i++)
		 {
		   if(a[i]==-1)
		    {
		      a[i]=num;
		      flag=1;
		      break;
		    }
		 }
	      i=0;
	      while((i<key)&&(flag==0))
		 {
		    if(a[i]==-1)
		      {
			a[i]=num;
			flag=1;
			break;
		      }
		  i++;
		 }
	   }
   }


void main()
{
  int a[MAX],i,num,key;
  int ans=1;
  clrscr();
  for(i=0;i<MAX;i++)
   a[i]=-1;
  do
    {
      printf("Enter the number :\n");
      scanf("%d",&num);
      key= create(num);
      linear_probe(a,num,key);
      printf("\nDo you want to continue? (1/0)");
      scanf("%d",&ans);
     } while(ans);
     display(a);
    getch();
}