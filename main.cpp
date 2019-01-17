#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<string.h>
#include<stdio.h>
#include<fstream.h>
#include<process.h>
#include<stdlib.h>

struct user
{
 char name[20];
 char date[11];
 char stat[20];
}store;

//global variables
int count=0,B_user=0,B_comp=0;
int user_check[5][5] , comp_check[5][5] , user_arr[5][5] , comp_arr[5][5];
int n=0; //total moves count

//various function used in the programme
void intro();
void initialize();//to intitialize user, computer and check matrix with default value
void display(int a[5][5]);
void comp_entry();//for generating bingo matrix for computer
void user_entry();//to take input from user for its bingo matrix
//parameter b can have values only 0 and 1,0=user,1=computer
void play (int num);
void rcheck(int a[5][5] , int b ); //bingo check row wise
void ccheck(int a[5][5] , int b ); //bingo check coloum wise
void dcheck(int a[5][5] , int b ); //bingo check diagonal wise
int  bingo_check(int a[5] , int b ); //Bingo array check
int  comp(int u[5],int p[5]);//Essential aid to bing_check()
void bingo_entry(int a[5] , int b ); //Move entry in B array
void bingo(int b);
void total_check();
void call(int b); //functionn to call  above function during runtime

//start of main

void main()
{randomize();
 clrscr();
 int u,c,check,i,t=0,temp[25];
 int bu=0,bc=1;
 intro();
 //initialize();
 user_entry();
 comp_entry();
 while(n<=25)
 {clrscr();
  check=0;
  if(n%2==0)
  {
   cout<<"\n Don't enter a number twice!!!!!";
   cout<<"\n Don't enter number greater than 25 or 0 !!!!!!";
   cout<<"\n Violating these will result in exiting the current game!!!!!";
   cout<<"\n User Bingo matrix:";
   display(user_arr);
   cout<<"\n User please enter the no:";
   cin>>u;
   clrscr();
   for(i=0;i<=t;i++)
    if(temp[i]==u)
     check++;
   if(check==0)
     {temp[t]=u;
      play(u);
      t++;
      cout<<"\n Your Matrix: \n";
      display(user_arr);
      if(n>=5)
       {rcheck(user_arr,bu);
	ccheck(user_arr,bu);
	dcheck(user_arr,bu);
	total_check();
       }
     }
   else
   {cout<<"\n Protocol Violated!!!";
    delay(1000);
    cout<<"\n Exiting!!!";
    exit(0);
   }
  }
  else
  {clrscr();
   p:
   c=random(25)+1;
   for(i=0;i<=t;i++)
    if(c==temp[i])
     check++ ;
   if(check!=0)
      goto p;
   temp[t]=c;
   clrscr();
   cout<<"\n Number from computer is :"<<c;
   play(c);
   t++;
   display(comp_arr);
   if(n>=5)
   {rcheck(comp_arr,bc);
    ccheck(comp_arr,bc);
    dcheck(comp_arr,bc);
    total_check();
   }
   cout<<"\n Your matrix: \n";
   display(user_arr);
  }
  cout<<"\n";
  display(user_check);
  cout<<"\n";
  display(comp_check);
  cout<<"\n Press enter to continue!!!!";
  getch();
  n++;
 }
}

//end of main

void intro()
{
 cout<<"\n          ^^^^^welcome to the BINGO game^^^^^";
 cout<<"\n\n\n Plese enter your Details-";
 cout<<"\n Name: "; gets(store.name);
 cout<<"\n Date(dd/mm/yyyy):"; gets(store.date);
 cout<<"\n Here are the basic rules!!!!";
 cout<<"\n 1. You should know how to play bingo.";
 cout<<"\n The number you play will be replaced by 0";
 cout<<"\n Press Enter to continue....";
 getch();
}

void initialize()
{int i,j;
 for(i=0;i<5;i++)
  for(j=0;j<5;j++)
   {
    user_arr[i][j]=comp_arr[i][j]=0;

    user_check[i][j]=comp_check[i][j]=60;
   }
}

void display(int a[5][5])
{
  for(int i=0;i<5;i++)
  {cout<<"\n";
   for(int j=0;j<5;j++)
    {if(a[i][j]<=9)
     cout<<"0";
     cout<<a[i][j]<<" ";
    }
  }
}

void comp_entry()
{
 cout<<"\n Bingo matrix generation for computer......";
 randomize();
 int i,j,p,k=0,a,arr[25];
 //int x=0,y=0;
 while(k<25)
 {l:
  a=random(25)+1;
  p=0;
  for(j=0;j<=k;j++)
    if(a==arr[j])
     p++;
  if(p==0)
  {arr[k]=a;
   k++;
  }
  else
   goto l;
 };
 k=0;
 for( i=0;i<5;i++)
  for(j=0;j<5;j++)
   {comp_arr[i][j]=arr[k];
    k++;
   };
  delay(2000);
 cout<<"\n Matrix generation complete....";
 display(comp_arr);
 getch();
}

void user_entry()
{clrscr();
 int a,i,j,p,k=0;
 int temp [25];
 cout<<"\n Your matrix is already initialize by default value 0";
 for(a=0; a<3;a++)
   {clrscr();
    cout<<"\n WARNING!!!  ";
    delay(200);
   }
 cout<<"\n No number should be enter twice!!!";
 cout<<"\n Don't enter number grater than 25 or 0 !!!";
 cout<<"\n Violating this protocol will result in exiting the game!!";
 for(i=0;i<5;i++)
 {cout<<"\n Enter data coloumn wise....";
   for(j=0;j<5;j++,k++)
    {cout<<"\n Enter data : ";
     cin>>a;
     if((a>25)||(a==0))
     {cout<<"\n Violation of Protocol!!!!!!";
      cout<<"\n Exiting...";
      delay(1000);
      exit(0);
     }
     for(p=0;p<k;p++)
      if(temp[p]==a)
     {
       cout<<"\n Violation of protocol!!!!!";
       cout<<"\n Exiting...";
       delay(1000);
       exit(0);
      }
     temp[k]=a;
     user_arr[i][j]=a;
    }
 }
 cout<<"\n Matrix Entry complete!!!";
 clrscr();
 cout<<"\n Your Matrix: \n ";
 display(user_arr);

}

void play(int num)
{int i,j,x;
      x=num;
 if((num>25)||(num==0))
  {cout<<"\n Protocol Violated!!!!";
   delay(2000);
   exit(0);
  }
 for(i=0;i<5;i++)
  for(j=0;j<5;j++)
  { if(user_arr[i][j]==num)
	user_arr[i][j]=0;
    if(comp_arr[i][j]==x)
       comp_arr[i][j]=0;
  }
}

void rcheck(int a[5][5] , int b )
{cout<<"\n Rcheck started!!";
 int temp[5];
 int x,y,c,bc,t=0;
 for(x=0;x<5;x++)
   {c=0;
    for(y=0;y<5;y++)
     {
       if(a[x][y]==0)
	{ c+=1;
	  temp[t]=((x*10)+y);
	  t++;
	}
       else
	 goto p;
      if(c==5)
      {
	 bc=bingo_check(&temp[5] , b  );
	 if(bc==1)
	 bingo_entry(&temp[5], b  );
      }
      p:
     }
   }
  cout<<"\n Rcheck stopped!!!";
  getch();
}

void ccheck(int a[5][5] , int b )
{cout<<"\n ccheck started!!!";
 int temp[5];
 int x,y,c,bc,t=0;
 for(y=0;y<5;y++)
   {c=0;
    for(x=0;x<5;x++)
     {
       if(a[x][y]==0)
	{ c++;
	  temp[t]=(x*10)+y;
	  t++;
	}
       else
	 break;
       if(c==5)
	{
	 bc=bingo_check(&temp[5], b  );
	 if(bc==1)
	 bingo_entry(&temp[5], b  );
	}
     }
   }
   cout<<"\n Ccheck stopped";

} getch();

void dcheck(int a[5][5] ,int b )
{cout<<"\n Dcheck started!!!";
 int temp[5];
 int x,y,c,bc,t=0;
 for(x=0;x<5;x++)
   {
    if(a[x][x]==0)
    {c++ ;
     temp[t]=(x*10) + x;
     t++;
    }
    else
     break;
    if(c==5)
    {bc=bingo_check(&temp[5],b);
    if(bc==1)
      bingo_entry(&temp[5],b);
    }
   }
  t=0;
  for(x=0,y=4;x<5;x++,y--)
  {if(a[x][y]==0)
    { c++;
      temp[t]=(x*10) + y;
      t++;
    }
   else
     break;
   if(c==5)
    {bc=bingo_check(&temp[5] , b);
     if(bc==1)
      bingo_entry(&temp[5] , b);
    }
  }
  cout<<"\n Dcheck stopped";
  getch();
}

int bingo_check(int a[5], int b)
{cout<<"\n Bingo check started";
 int x,y,t=0;
 int c[5],temp[5];
  if(b==0)
   {for(x=0;x<B_user;x++)
     {
      for(y=0;y<5;y++)
	temp[y]=user_check[x][y];
      c[x]=comp(&temp[5],&a[5]);
     }

   }
  else
   {for(x=0;x<B_comp;x++)
    {
      for(y=0;y<5;y++)
	temp[y]=comp_check[x][y];
      c[x]=comp(&temp[5],&a[5]);
     }
   }
  for(int i=0;i<5;i++)
   if((c[i]==5)||(c[i]==4))
    t++;
  cout<<"\n Bingo check stopped";
  if(t==0)
    return 1;
  else
    return 0;

}

//comparision of check arrays
int comp(int u[5],int p[5])
{
 int i,r=0;
   for(i=0;i<5;i++)
    if(u[i]==p[i])
     r++;
 return r;
}

void bingo_entry(int a[5], int b)
{ int y;
  if(b==0)
  {for(y=0;y<5;y++)
     user_check[B_user][y]=a[y];
   B_user++;
  }
 if(b==1)
  {for(y=0;y<5;y++)
    comp_check[B_comp][y]=a[y];
   B_comp++;
  }
  cout<<"\n Bingo Entry stopped";
  getch();
}

void total_check()
{int bu=0,bc=0;
 if(B_user==4)
  bingo(bu);
 else
  {
   if(B_comp==4)
     bingo(bc);
   else
    if(n==25)
     {strcmp(store.stat,"Draw");
      cout<<"\n Its a Draw....\n Exiting...." ;
      exit(0);
     }
  }

}

void bingo(int b)
{
 if(b==0)
  {cout<<"\n !! ";puts(store.name);cout<<" won";
   strcmp(store.stat,store.name);
   ofstream a;
   a.open("store.dat",ios::binary|ios::out|ios::app);
   a.write((char*)&store,sizeof(store));
   a.close();
   clrscr();
   cout<<"\n Game data have been saved to disk !!!\n Thank you for playing>>";
   exit(0);
  }
  else
  {cout<<"\n !! Computer won !!";
   strcmp(store.stat,"computer");//store.stat="computer";
   ofstream a;
   a.open("store.dat",ios::binary|ios::out|ios::app);
   a.write((char*)&store,sizeof(store));
   a.close();
   clrscr();
   cout<<"\n Game data have been saved to disk !!!\n Thank you for playing>>";
   exit(0);
  }
}

