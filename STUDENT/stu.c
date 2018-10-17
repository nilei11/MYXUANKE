#include<stdio.h>
#include"stu.h"
#include<string.h>
#include<stdlib.h>
#include"pub.h"
void keyboards()//录入学生信息子函数（从键盘录入） 
{
    int i;
    struct student *p1,*p2;
    N2=0;
    p1=p2=(struct student *)malloc(sizeof(struct student));
    printf("学生学号\t学生姓名\n");
    scanf("%d",&p1->num2);
    if(p1->num2 == 0)
    {
    	return;
	}
	if(p1->num2 < 0 || p1->num2 >9999999)
    {
    	printf("请重新录入！\n\n");
    	keyboards();
	}
    scanf("%s",p1->name2);
    p1->nelen=0;
    p1->nelescore=0;
    for (i=0;i<20;i++) p1->nelenum[i]=0;
    head2=NULL;
    while(1) 
    {
        N2=N2+1;
        if(N2==1)head2=p1; else p2->next=p1;
        p2=p1;
        p1=(struct student * )malloc(sizeof(struct student));
        scanf("%d",&p1->num2);
        if(p1->num2 == 0)
    	{
    		break;
		}
    	scanf("%s",p1->name2);
        p1->nelen=0;
        p1->nelescore=0;
        for (i=0;i<20;i++) p1->nelenum[i]=0;
    }
    p2->next=NULL;
    printf("录入成功!\n");
}

void inputs()//录入学生信息主函数 
{
    int i;
    printf("\t\t\t录入学生信息\n");
    printf("\n1.从键盘录入\n");
    printf("2.从文件录入\n");
    printf("3.返回\n");
    printf("请选择(1~3):\n");
    scanf("%d",&i);
    switch(i) 
    {
        case(1):keyboards();
        break;
        case(2):files();
        break;
        case(3):break;
    }
}



void inserts()//学生信息管理子函数(填加学生信息) 
{
    struct student *p0,*p1,*p2;
    struct student * incouse;
    p1=head2;
incouse=(struct student *)malloc(sizeof(struct student));
            incouse->nelen=0;
            incouse->nelescore=0;
            incouse->nelenum[0]=0;
            printf("学生学号\t学生姓名\n");
            scanf("%d%s",&incouse->num2,incouse->name2);
    p0=incouse;
    if(head2==NULL) 
    {
        head2=p0;
        p0->next=NULL;
    } else
    {
        while((p0->num2 > p1->num2) && (p1->next!=NULL)) 
        {
            p2=p1;
            p1=p1->next;
        }
        if(p0->num2 <= p1->num2) 
        {
            if(head2==p1) head2=p0; else p2->next=p0;
            p0->next=p1;
        } else
        {
            p1->next=p0;
            p0->next=NULL;
        }
    }
    N2=N2+1;
    printf("增添成功!\n\n");
}

void dels(int num2)//学生信息管理子函数（删除学生信息) 
{
    struct student *p1,*p2;
    struct couse *p;
    p = head1;
    if(head2==NULL) 
    {
        printf("\n没有该学生信息,无法删除!\n");
        return;
    }
    p1=head2;
    while(num2!=p1->num2 && p1->next!=NULL) 
    {
        p2=p1;
        p1=p1->next;
    }
    if(num2==p1->num2) 
    {
        if(p1==head2) head2=p1->next; else p2->next=p1->next;
        printf("已删除该学生信息!\n");
        	int i;
        	for(i = 0; i < p1->nelen; i++)
        	{
        		if(p->num1 == p1->nelenum[i])
        		{
        			(p->nelepeo)--;
					p = p -> next;
				}
			}
			printf("选课人数发生变化!\n");
        N2=N2-1;
    } else printf("无该学号的学生!\n");   
}

void changes(int num2)//学生信息管理子函数（修改学生信息) 
{
	struct student *p1;
    struct couse *p;
    int i;
    start:
    p = head1;
    if(head2==NULL) 
    {
        printf("\n没有该学生信息,无法修改!\n");
        return;
    }
    p1=head2;
    while(num2!=p1->num2 && p1->next!=NULL) 
    {
        p1=p1->next;
    }
    if(num2==p1->num2) 
    {
		printf("学生学号 学生姓名 已选课程数量 已选课程总计学分\n");
    	printf("%-4d %10s %8d %13d\n\n",p1->num2,p1->name2,p1->nelen,p1->nelescore);
    	printf("1.修改学生学号\n");
    	printf("2.修改学生姓名\n");
    	printf("3.返回\n");
    	printf("请输入(1~3):\n");
    	scanf("%d", &i);
    	printf("\n\n");
    	switch(i)
    	{
    		case(1):
    			printf("请输入新的学号:");
    			scanf("%d", &p1->num2);
    			num2=p1->num2;
    			printf("学号修改成功！\n\n");
    			goto start;
    			break;
    		case(2):
    			printf("请输入新的姓名:");
    			scanf("%s", &p1->name2);
    			printf("姓名修改成功！\n\n");
    			goto start;
    			break;
    		case(3):break; 
		}
		printf("选课状况发生变化!\n");		
    } 
	else printf("无该学号的学生!\n");   
}

void lists()//输出学生信息 (简单)
{
    struct student * p;
    p=head2;
    printf("学生学号 学生姓名 已选课程数量 已选课程总计学分\n");
    while(p!=NULL) 
    {
        printf("%-4d %10s %8d %13d\n",p->num2,p->name2,p->nelen,p->nelescore);
        p=p->next;
    }
}

void scheak()//输出学生信息（详细) 
{
    char c;
    struct couse * p0;
    struct student * p;
    int num2,i,f=0;
    printf("请输入学号:\n");
    scanf("%d",&num2);
    p=head2;
    while(p->num2!=num2 && p!=NULL) p=p->next;
    if(p==NULL) 
    {
        printf("不存在该生的信息,请回主菜单录入信息:\n");
        goto end;
    }
    printf("学生学号 学生姓名 已选课程数量 已选课程总计学分\n");
    printf("%-4d %10s %8d %13d\n\n",p->num2,p->name2,p->nelen,p->nelescore);
    printf("已选课程:\n");
    if(p->nelenum[0]==0) 
    {
        printf("该生尚未选课!\n");
        goto end;
    }
    printf("课程编号 课程名称 课程性质 授课学时 学分 课程已选人数 课程人数上限\n");
    for (i=0;p->nelenum[i]!=0;i++) 
    {
        p0=head1;
        while(p0->num1!=p->nelenum[i]) p0=p0->next;
        printf("%-5d%10s%10s%7d%6d%11d%12d\n\n",p0->num1,p0->name1,p0->type,p0->time,p0->score,p0->nelepeo,p0->Melepeo);
        f=f+p0->score;
        p->nelescore=f;
    }
    printf("总学分:%d\n",f);
    end:;
}

void managements()//学生信息管理主函数 
{
    struct student * incouse;
    int i,num2;
    start:
    printf("\t\t\t学生信息管理\n");
    printf("1.新增学生信息\n");
    printf("2.删除学生信息\n");
    printf("3.修改学生信息\n");
    printf("4.查看学生信息\n");
    printf("5.返回\n");
    printf("请选择(1~5):\n");
    scanf("%d",&i);
    printf("\n\n");
    switch(i) 
    {
        case(1): 
        {
            inserts();
            printf("\n\n");
            goto start;
            break;
        }
        case(2): 
        {
            printf("请输入要删除学生的学号:\n");
            scanf("%d",&num2);
            dels(num2);
            printf("\n\n");
            goto start;
            break;
        }
        case(3):
		 {
            printf("请输入要修改学生的学号:\n");
            scanf("%d",&num2);
            changes(num2);
            printf("\n\n");
            goto start;
            break;
         }
        case(4):
        {
        	printf("\n1.总体概况\n");
			printf("2.详细信息\n");
			printf("3.返回主页面\n");
			printf("4.请输入(1~3)：\n");
			scanf("%d", &i);
			switch(i)
			{
				case(1):
				lists();
				break;	
				case(2):
				scheak();
				break;
				case(3):
				system("clear");
				break;	
			}
			printf("\n\n");
			goto start;
            break;		
		}
        case(5):
		system("clear");
		break;
    }
}


void intos()//存储学生信息 
{
    FILE *fp;
    struct couse *p1;
    struct student *p2; 
    char filepath[30];
    printf("输入学生选课信息要保存的文件路径:");
    getchar();
    gets(filepath);
    if((fp=fopen(filepath,"w"))==NULL) 
    {
        printf("\n保存失败!");
        return;
    }
    p1=head1;
    p2=head2;
    while(p2!=NULL) 
    {
        fprintf(fp,"%d %s %d %d\n",p2->num2,p2->name2,p2->nelen,p2->nelescore);
        int i;
        for(i = 0; i < p2->nelen; i++)
        {
        	fprintf(fp,"%d\t",p2->nelenum[i]);
		}
		fprintf(fp,"\n\n");
        p2=p2->next;
    }
    fclose(fp);
    printf("学生信息已保存在%s中!\n",filepath);
}
void files()//录入学生信息子函数（从文件自动录入） 
{
    FILE * fp;
    struct student *p3,*p4;
    int i;
    N2=0;
    if((fp=fopen("./student.txt","r"))==NULL) 
    {
        printf("找不到文件!\n");
        exit(0);
    }
    p3=p4=(struct student*)malloc(sizeof(struct student));
    fscanf(fp,"%d%s%d%d",&p3->num2,p3->name2,&p3->nelen,&p3->nelescore);
    for(i = 0; i < p3->nelen; i++)
    {
        fscanf(fp,"%d",&p3->nelenum[i]);
	}
    head2=NULL;
    while(!feof(fp)) 
    {
        N2=N2+1;
        if(N2==1)
		{
			head2=p3;
		} 
		else
		{
			p4->next=p3;
		} 
        p4=p3;
        p3=(struct student * )malloc(sizeof(struct student));
        fscanf(fp,"%d%s%d%d",&p3->num2,p3->name2,&p3->nelen,&p3->nelescore);
        for(i = 0; i < p3->nelen; i++)
        {
        	fscanf(fp,"%d",&p3->nelenum[i]);
		}
    }
    p4->next=NULL;
    printf("录入成功!\n\n");
}


void cheak()//学生选课子函数(查询可选课程) 
{
    char e;
    struct couse * c, *p0;
    struct student * s;
    int num2,i,j=0,t=0, num1;
    printf("请输入你的学号:");
    scanf("%d",&num2);
    s=head2;
    while(s->num2!=num2 && s->next!=NULL) s=s->next;
    if(s->num2!=num2) 
    {
        printf("不存在你的信息,请进入主菜单录入你的信息!\n");
        return;
    }
    c=head1;
    printf("学生学号 学生姓名 已选课程数量 已选课程总计学分\n");
    printf("%-4d %10s %8d %13d\n\n",s->num2,s->name2,s->nelen,s->nelescore);
    printf("你的可选课程:\n");
    printf("课程编号 课程名称 课程性质 授课学时 学分 课程已选人数 课程人数上限\n");
    while(c!=NULL) 
    {
        for (t=0,i=0;s->nelenum[i]!=0;i++) 
        {
            if(c->num1==s->nelenum[i]) t=1;
        }
        if(t==0 && (c->nelepeo!=c->Melepeo)) 
        {
			printf("%-5d%10s%10s%7d%6d%11d%12d\n\n",c->num1,c->name1,c->type,c->time,c->score,c->nelepeo,c->Melepeo);
            j++;
        }
        c=c->next;
    }
    if(j==0) 
    {
        printf("你已选完所有课程，无法再多选!\n");
        return;
    }
    printf("选课(y/n)?:\n");
    getchar();
    e=getchar();
    i=0;
    while(e=='y') 
    {
        printf("\n\n");
    printf("请输入要选课的编号:\n");
    scanf("%d",&num1);
    p0=head1;
    while(p0->num1!=num1 && p0!=NULL) p0=p0->next;
    if(p0==NULL) 
    {
        printf("不存在该课程的信息,请回主菜单录入信息:\n");
        return;
    }
    for (i=0;s->nelenum[i]!=0;i++);
    s->nelenum[i]=num1;
    (s->nelen)++;
    c=head1;
    while(c->num1!=num1) c=c->next;
    (c->nelepeo)++;
    s->nelescore = s->nelescore + c->score;
        printf("继续选课(y/n)?:\n");
        getchar();
        e=getchar();
    }
}


void hcheak()//学生选课子函数（查询已选课程) 
{
    char c;
    struct couse * p0;
    struct student * p;
    int num2,i,f=0,j,num1;
    printf("请输入学号:\n");
    scanf("%d",&num2);
    p=head2;
    while(p->num2!=num2 && p!=NULL) p=p->next;
    if(p==NULL) 
    {
        printf("不存在你的信息,请回主菜单录入信息:\n");
        goto end;
    }
    printf("学生学号 学生姓名 已选课程数量 已选课程总计学分\n");
    printf("%-4d %10s %8d %13d\n\n",p->num2,p->name2,p->nelen,p->nelescore);
    printf("已选课程:\n");
    if(p->nelenum[0]==0) 
    {
        printf("你还没选课!\n");
        goto end;
    }
    printf("课程编号 课程名称 课程性质 授课学时 学分 课程已选人数 课程人数上限\n");
    for (i=0;p->nelenum[i]!=0;i++) 
    {
        p0=head1;
        while(p0->num1!=p->nelenum[i]) p0=p0->next;
        printf("%-5d%10s%10s%7d%6d%11d%12d\n\n",p0->num1,p0->name1,p0->type,p0->time,p0->score,p0->nelepeo,p0->Melepeo);
        f=f+p0->score;
        p->nelescore=f;
    }
    printf("总学分:%d\n",f);
    printf("是否进行退课(y/n)?");
    getchar();
    c=getchar();
    while(c=='y') 
    {
        printf("请输入你要退掉的课程编号:\n");
    	scanf("%d",&num1);
    	p0=head1;
    	while(p0->num1!=num1) p0=p0->next;
    	for (i=0;p->nelenum[i]!=num1;i++);
    	for (j=i;p->nelenum[j]!=0;j++) p->nelenum[j]=p->nelenum[j+1];
   	p->nelenum[--j]=0;
    	(p0->nelepeo)--;
    	p->nelescore = p->nelescore - p0->score; 
    	printf("退课成功!\n");
        printf("继续退课(y/n)?");
        getchar();
        c=getchar();
        (p->nelen)--;
    }
    end:;
}


void intos1()//存储学生信息 
{
    FILE *fp;
    struct couse *p1;
    struct student *p2; 
    if((fp=fopen("./student.txt","w"))==NULL) 
    {
        printf("\n保存失败!");
        return;
    }
    p1=head1;
    p2=head2;
    while(p2!=NULL) 
    {
        fprintf(fp,"%d %s %d %d\n",p2->num2,p2->name2,p2->nelen,p2->nelescore);
        int i;
        for(i = 0; i < p2->nelen; i++)
        {
        	fprintf(fp,"%d\t",p2->nelenum[i]);
		}
		fprintf(fp,"\n\n");
        p2=p2->next;
    }
    fclose(fp);
}

void elective()//学生选课主函数 
{
    int i;
    start:
    printf("\t\t\t学生选课\n");
    printf("1.查询可选课程\n");
    printf("2.查询已选课程\n");
    printf("3.存储选课信息\n");
    printf("4.返回\n");
    printf("请输入(1~4):\n");
    scanf("%d",&i);
    printf("\n\n");
    switch(i) 
    {
        case(1):cheak();
        printf("\n\n");
        goto start;
        break;
        case(2):hcheak();
        printf("\n\n");
        goto start;
        break;
        case(3):intos1();
        printf("\n\n");
        goto start;
        break;
        case(4):
	break;
    }
}
