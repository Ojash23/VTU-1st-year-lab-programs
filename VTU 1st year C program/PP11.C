#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int reach[20],q[20],a[20][20],visited[20],i,j,n,count=0,f=0,r=-1;

void bfs(int v)
   {
     for(i=1;i<=n;i++)
     {
       if(a[v][i] && !visited[i])
	      q[++r]=i;
      }
	   if(f<=r)
	     {
	       visited[q[f]]=1;
	       bfs(q[f++]);
	     }
     }


void dfs(int v)
    {
     int i;
     reach[v]=1;
     for(i=1;i<=n;i++)
       {
	 if(a[v][i] && !reach[i])
	   {
	     printf("%d -> %d\n",v,i);
	     count++;
	     dfs(i);
	   }
       }
    }

void main()
   {
     int ch,v;
     clrscr();
     printf("Enter the number of the vertices: \n");
     scanf("%d",&n);
     for(i=1;i<=n;i++)
	{
	  visited[i]=0;
	  q[i]=0;
	}
     for(i=1;i<=n-1;i++)
	reach[i]=0;
     printf("Enter the elements in matrix form:\n");
     for(i=1;i<=n;i++)
     for(j=1;j<=n;j++)
     scanf("%d",&a[i][j]);
     printf("1.BFS\n2.DFS\n3.EXIT\n");
     printf("Enter the choice\n");
     scanf("%d",&ch);
     switch(ch)
	 {
	   case 1: printf("Enter the starting vertex:\n");
		   scanf("%d",&v);
		   bfs(v);
		   if((v<1)||(v>n))
		     {
		       printf("BFS is not possible \n");
		       return;
		     }
		   printf("The reachable nodes are: \n");
		   for(i=1;i<=n;i++)
		      {
			printf("%d\t",i);
		      }
		   break;

	   case 2: dfs(1);
		   if(count==n-1)
		      printf("Graph is connectex\n");
		   else
		      printf("Graph is not connected\n");
		   break;

	   case 3: exit(0);
		   break;

	 }
     getch();
   }