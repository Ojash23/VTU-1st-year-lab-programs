#include<stdio.h>
#include<conio.h>
#define max 4
int s[max],i,temp;
int top=-1;

void push(int item)
  {
    if(top==max-1)
     {
       printf("Stack Overflow\n");
       return;
     }
     s[++top]=item;
     temp=top;
  }

void pop()
  {
    if(top==-1)
      {
	printf("Stack is empty\n");
	return;
      }
    printf("The deleted element is: %d\n",s[top--]);
  }

void display()
    {
      int i;
      if(top==-1)
	{
	  printf("Stack is empty\n");
	  return;
	}
      for(i=top;i>=0;i--)
	{
	  printf("%d\t",s[i]);
	}
    }

void pallin()
  {
    int i;
    int rev[max];
    if(top==-1)
     {
      printf("Go and insert some element first\n");
      return;
     }
    while(top!=-1)
       {
	 rev[top]=s[top];
	 top--;
       }
       top=temp;
    for(i=0;i<=temp;i++)
       {
	 if(rev[i]==s[top--])
	   {
	     if(i==temp)
	      {
		printf("Pallindrome\n");
		return;
	      }
	   }
       }
       printf("Not a pallindrome\n");
  }

void main()
   {
     int ch,item;
     clrscr();
     while(1)
      {
	printf("\n___MENU___\n");
	printf("1,PUSH\n2.POP\n3.Display\n4.Pallindrome or not\n5.Exit\n");
	printf(" ");
	printf("Enter the choice chutiye!!");
	scanf("%d",&ch);
	switch(ch)
	   {
	      case 1: printf("Enter the item to be inserted :\n");
		      scanf("%d",&item);
		      push(item);
		      break;

	      case 2: pop(); break;

	      case 3: display(); break;

	      case 4: pallin(); break;

	      case 5: exit(0); break;
	   }
      }
      getch();
   }