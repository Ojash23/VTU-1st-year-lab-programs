#include<stdio.h>
#include<conio.h>
#define compare(x,y) (x==y)?0:(x>y)?1:-1

struct node
{
  int coef;
  int xexp,yexp,zexp;
  struct node *link;
};
typedef struct node *NODE;

NODE getnode()
  {
      NODE x;
      x = (NODE)malloc(sizeof(struct node));
      if(x==NULL)
	printf("unsuccesfull\n");
      return x;
  }

NODE attach(int coef,int xexp,int yexp,int zexp,NODE head)
   {
      NODE temp,cur;
      temp=getnode();
      temp->coef=coef;
      temp->xexp=xexp;
      temp->yexp=yexp;
      temp->zexp=zexp;
      cur=head->link;
      while(cur!=head)
	  {
	    cur=cur->link;
	  }
      cur->link=temp;
      temp->link=head;
      return head;
   }

NODE read_poly(NODE head)
   {
      int i,coef,xexp,yexp,zexp,n;
      printf("Enter the number of elements\n");
      scanf("%d",&n);
      for(i=1;i<=n;i++)
	{
	  printf("Enter the %d item :\n",i);
	  printf("Coef: ");
	  scanf("%d",&coef);
	  printf("Enter the Pow(x),Pow(y) and Pow(z)\n");
	  scanf("%d",&xexp);
	  scanf("%d",&yexp);
	  scanf("%d",&zexp);
	  head=attach(coef,xexp,yexp,zexp,head);
	}
	return head;
   }

void display(NODE head)
    {
      NODE temp;
      if(head->link==head)
	{
	printf("\n Polynomial does not exist\n");
	return;
	}
	temp=head->link;
	while(temp!=head)
	    {
	      printf("%dx^%dy^%dz^%d\n",temp->coef,temp->xexp,temp->yexp,temp->zexp);
	      temp=temp->link;
	      if(temp!=head)
		  printf("+");
	    }
    }

int eval(NODE head)
   {
     NODE poly;
     int x,y,z,sum=0;
     printf("Enter the value of x,y,z");
     scanf("%d%d%d",&x,&y,&z);
     poly= head->link;
     while(poly!=head)
	 {
	   sum += poly->coef*pow(poly->xexp,x)*pow(poly->yexp,y)*pow(poly->zexp,z);
	   poly=poly->link;
	 }
     return sum;
   }

NODE add_poly(NODE head1,NODE head2,NODE head3)
    {
      NODE p1,p2;
      int coef;
      p1=head1->link;
      p2=head2->link;
      while(p1!=head1&&p2!=head2)
	  {
	   while(1)
	     {
		if(p1->xexp==p2->xexp&&p1->yexp==p2->yexp&&p1->zexp==p2->zexp)
		{
		  coef=p1->coef + p2->coef;
		  head3=attach(coef,p1->xexp,p1->yexp,p1->zexp,head3);
		  p1=p1->link;
		  p2=p2->link;
		  break;
		}
	       if(p1->xexp!=0||p2->xexp!=0)
		{
		  switch(compare(p1->xexp,p2->xexp))
		  {
		    case -1: head3=attach(p2->coef,p2->xexp,p2->yexp,p2->zexp,head3);
			     p2=p2->link;
			     break;

		    case 0: if(p1->yexp > p2->yexp)
			     {
				head3=attach(p1->coef,p1->xexp,p1->yexp,p1->zexp,head3);
				p1=p1->link;
				break;
			     }
			      if(p1->yexp< p2->yexp)
			     {
				head3=attach(p2->coef,p2->xexp,p2->yexp,p2->zexp,head3);
				p2=p2->link;
				break;
			     }
			      if(p1->zexp > p2->zexp)
			     {
				head3=attach(p1->coef,p1->xexp,p1->yexp,p1->zexp,head3);
				p1=p1->link;
				break;
			     }
			      if(p1->zexp< p2->zexp)
			     {
				head3=attach(p2->coef,p2->xexp,p2->yexp,p2->zexp,head3);
				p2=p2->link;
				break;
			     }
			     break;
		    case 1: head3=attach(p1->coef,p1->xexp,p1->yexp,p1->zexp,head3);
			     p1=p1->link;
			     break;
			}
		break;
		}
		 if(p1->yexp!=0||p2->yexp!=0)
		{
		  switch(compare(p1->yexp,p2->yexp))
		  {
		    case -1: head3=attach(p2->coef,p2->xexp,p2->yexp,p2->zexp,head3);
			     p2=p2->link;
			     break;

		    case 0:
			     if(p1->zexp > p2->zexp)
			     {
				head3=attach(p1->coef,p1->xexp,p1->yexp,p1->zexp,head3);
				p1=p1->link;
				break;
			     }
			      if(p1->zexp< p2->zexp)
			     {
				head3=attach(p2->coef,p2->xexp,p2->yexp,p2->zexp,head3);
				p2=p2->link;
				break;
			     }
			     break;
		    case 1: head3=attach(p1->coef,p1->xexp,p1->yexp,p1->zexp,head3);
			     p1=p1->link;
			     break;
			}
		break;
		}
		 if(p1->zexp!=0||p2->zexp!=0)
		{
		  switch(compare(p1->zexp,p2->zexp))
		  {
		    case -1: head3=attach(p2->coef,p2->xexp,p2->yexp,p2->zexp,head3);
			     p2=p2->link;
			     break;

		    case 1: head3=attach(p1->coef,p1->xexp,p1->yexp,p1->zexp,head3);
			     p1=p1->link;
			     break;
			}
		break;
		}
	     }
	  }
	while(p1!=head1)
	  {
	      head3=attach(p1->coef,p1->xexp,p1->yexp,p1->zexp,head3);
	      p1=p1->link;
	  }
	while(p2!=head2)
	   {
		head3=attach(p2->coef,p2->xexp,p2->yexp,p2->zexp,head3);
		p2=p2->link;
	   }
	   return head3;
    }

void main()
  {
    int ch,res;
    NODE head,head1,head2,head3;
    clrscr();
    head=getnode();
    head1=getnode();
    head2=getnode();
    head3=getnode();

    head = head->link;
    head1 = head1->link;
    head2 = head2->link;
    head3 = head3->link;

    while(1)
    {
      printf("\n___MENU___\n");
      printf("1.Represent and evaluate\n2.Sum of the polynomial\n");
      printf("Enter the choice\n");
      scanf("%d",&ch);
      switch(ch)
	{
	  case 1: printf("Polynomial P(x,y,z)\n");
		  head=read_poly(head);
		  printf("Represent the polynomial\n");
		  display(head);
		  printf("Then evaluate:\n");
		  res=eval(head);
		  printf("The result is %d\n",res);
		  break;

	  case 2: printf("Enter the polynomial P1\n");
		  head1= read_poly(head1);
		  printf("Polynomial:\n");
		  display(head1);
		   printf("Enter the polynomial P2\n");
		  head2= read_poly(head2);
		  printf("Polynomial:\n");
		  display(head2);
		  printf("The sum is :\n");
		  head3= add_poly(head1,head2,head3);
		  display(head3);
		  break;

	  case 3: exit(0); break;

	}
    }
    getch();
  }