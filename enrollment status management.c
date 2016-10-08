#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Student
{
        int xh;            // xh is the ID number of student
        int bj;            // bj is the class number of student
        char name[10];
        float a;           // a is the score of a course named a
        float b;           // the same as a
        float c;           // the same as a
        float sum;
}temp;
struct Student stu[5]={0};
int x=0;
struct Student *r;


int main()
{
     void center();
	 center();
	 return 0;
}


void center()
{
    void regist(char p[]);
    void cancel(char p[]);
    void query(char p[]);
    void score_sort();
    void show();

    int z,j;
	char p[5]={0},c[]={"yes"};
	strcpy(p,c);
     for(j=0;j<5;j++)
	   stu[j].sum=stu[j].a+stu[j].b+stu[j].c;
	printf("1.regist\n2.cancel\n3.query\n4.sort\n5.show\n6.quit\nplease input your option\n");
	scanf("%d",&z);

	if(z==1)
	 regist(p);
	if(z==2)
	 cancel(p);
	if(z==3)
     query(p);
	 if(z==4)
     score_sort();
	 if(z==5)
	  show();
}


void regist(char p[])
{
	   static int i=0;

	   if(strcmp(p,"yes")==0)
	   {
	     printf("Id ");
        scanf("%d",&stu[i].xh);
        printf("class ");
        scanf("%d",&stu[i].bj);
        printf("name ");
        scanf("%s",stu[i].name);

        printf("score1 ");
		scanf("%f",&stu[i].a);
        printf("score2 ");
        scanf("%f",&stu[i].b);
        printf("score3 ");
        scanf("%f",&stu[i].c);

        x=i;
		i++;
		printf("continue?\n");
        scanf("%s",p);
	    regist(p);
	   }
	   else if(strcmp(p,"no")==0) center();
}


void cancel(char p[])
{

	char m[10];
    int y,t,b,g;
          if(strcmp(p,"yes")==0)
		  {
	         scanf("%s",m);
             if(strcmp(m,"9")<0)
			 b=atoi(m);
		       for(y=0,t=0;stu[y].xh!=0;y++)
			   {
			     if(b!=stu[y].xh&&strcmp(m,stu[y].name)!=0)
				 {
                  printf("%d,%d,%s,%.1f,%.1f,%.1f,%.1f\n",stu[y].xh,stu[y].bj,stu[y].name,stu[y].a,stu[y].b,stu[y].c,stu[y].sum);
				  stu[t++]=stu[y];
				 }
			     else x--;
			   }
			   for(g=t;g<5;g++)
				   stu[g]=stu[4];
               printf("continue?\n");
               scanf("%s",p);
			   cancel(p);
		  }
               else if(strcmp(p,"no")==0) center();
}


void query(char p[])
{
	int a,k,j,t=0;
    if(strcmp(p,"yes")==0)
	{
	    scanf("%d",&a);
		for(k=0;k<5;k++)
			if(a==stu[k].xh||a==stu[k].bj)
			{t=1;break;}
       if(t)
	   {
     	for(j=0;j<5;j++)
	     if(a==stu[j].xh||a==stu[j].bj)
		    printf("%d,%d,%s,%.1f,%.1f,%.1f,%.1f\n",stu[j].xh,stu[j].bj,stu[j].name,stu[j].a,stu[j].b,stu[j].c,stu[j].sum);
	   }
    else printf(" there is no eligible student\n");
           printf("continue?\n");
               scanf("%s",p);
			   query(p);
	}
	else if(strcmp(p,"no")==0) center();
}


void score_sort()
{
	    int z;
		r=stu;
        for(z=0;z<1;z++)
             for(r=stu;r<stu+1-z;r++)
             {
                 if((*r).bj>(*(r+1)).bj)
                 {
                     temp=*r;
                     *r=*(r+1);
                     *(r+1)=temp;
                 }
                if((*r).bj==(*(r+1)).bj)
                if((*r).sum<(*(r+1)).sum)
                    {
                        temp=*r;
                        *r=*(r+1);
                        *(r+1)=temp;
                    }
             }
               for(r=stu;r<stu+2;r++)
           printf("%d,%d,%s,%.1f,%.1f,%.1f,%.1f\n",(*r).xh,(*r).bj,(*r).name,(*r).a,(*r).b,(*r).c,(*r).sum);
			   center();
}


void show()
{
	int j;
	for(j=0;j<2;j++)
        printf("%d,%d,%s,%.1f,%.1f,%.1f,%.1f\n",stu[j].xh,stu[j].bj,stu[j].name,stu[j].a,stu[j].b,stu[j].c,stu[j].sum);
	center();
}






































































