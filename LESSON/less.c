#include<stdio.h>
#include"less.h"
#include<string.h>
#include<stdlib.h>
#include"pub.h"
void filec()//录入键盘子函数(从文件自动录入) 
{
    FILE * fp;
    struct couse *p1,*p2;
    N1=0;
    if((fp=fopen("./class.txt","r"))==NULL) 
    {
        printf("找不到文件!\n");
        return;
    }
    p1=p2=(struct couse*)malloc(sizeof(struct couse));
    fscanf(fp,"%d%s%s%d%d%d%d",&p1->num1,p1->name1,p1->type,&p1->time,&p1->score,&p1->nelepeo,&p1->Melepeo);
    head1=NULL;
    while(!feof(fp)) 
    {
        N1=N1+1;
        if(N1==1)head1=p1; else p2->next=p1;
        p2=p1;
        p1=(struct couse * )malloc(sizeof(struct couse));
        fscanf(fp,"%d%s%s%d%d%d%d",&p1->num1,p1->name1,p1->type,&p1->time,&p1->score,&p1->nelepeo,&p1->Melepeo);
    }
    p2->next=NULL;
    printf("录入成功!\n\n");
}

void keyboardc()//录入课程子函数(从键盘录入) 
{
    struct couse *p1,*p2;
    N1=0;
    p1=p2=(struct couse*)malloc(sizeof(struct couse));
    printf("课程编号\t课程名称\t课程性质\t授课学时\t学分\t课程人数上限\n");
    scanf("%d", &p1->num1);
    if(p1->num1 == 0)
    {
    	return;
	}
	if(p1->num1 < 0 || p1->num1 >9999)
    {
    	printf("请重新输入!");
    	keyboardc();
	}
	scanf("%s%s%d%d%d",p1->name1,p1->type,&p1->time,&p1->score,&p1->Melepeo);
    p1->nelepeo=0;
    head1=NULL;
    while(1) 
    {
        N1=N1+1;
        if(N1==1)head1=p1; else p2->next=p1;
        p2=p1;
        p1=(struct couse * )malloc(sizeof(struct couse));
        scanf("%d", &p1->num1);
    	if(p1->num1 == 0)
    	{
    		break;
		}
		scanf("%s%s%d%d%d",p1->name1,p1->type,&p1->time,&p1->score,&p1->Melepeo);
        p1->nelepeo=0;
    }
    p2->next=NULL;
    printf("录入成功!\n\n");
}

void inputc()//录入课程主函数 
{
    int i;
    printf("\t\t\t录入课程信息\n");
    printf("1.从键盘录入\n");
    printf("2.从文件录入\n");
    printf("3.返回主菜单\n");
    printf("请选择(1~3):\n");
    scanf("%d",&i);
    switch(i) 
    {
        case(1):keyboardc();
        break;
        case(2):filec();
        break;
        case(3):break;
    }
}
void insertc()//课程管理子函数(增加课程) 
{
    struct couse *p0,*p1,*p2;
    struct couse *incouse;
    p1=head1;
incouse=(struct couse *)malloc(sizeof(struct couse));
            printf("课程编号\t课程名称\t课程性质\t授课学时\t学分\t课程人数上限\n");
            scanf("%d%s%s%d%d%d",&incouse->num1,incouse->name1,incouse->type,&incouse->time,&incouse->score,&incouse->Melepeo);
            incouse->nelepeo=0;
    p0=incouse;
    if(head1==NULL) 
    {
        head1=p0;
        p0->next=NULL;
    } 
	else
    {
        while((p0->num1 > p1->num1) && (p1->next!=NULL)) 
        {
            p2=p1;
            p1=p1->next;
        }
        if(p0->num1 <= p1->num1) 
        {
            if(head1==p1) head1=p0; else p2->next=p0;
            p0->next=p1;
        } 
		else
        {
            p1->next=p0;
            p0->next=NULL;
        }
    }
    N1=N1+1;
    printf("增添成功！\n\n");
}
void delc(int num1)//课程管理子函数(删除课程) 
{
    struct couse *p1,*p2;
    if(head1==NULL) 
    {
        printf("\n没有课程,无法删除!\n");
        return;
    }
    p1=head1;
    while(num1!=p1->num1 && p1->next!=NULL) 
    {
        p2=p1;
        p1=p1->next;
    }
    if(num1==p1->num1) 
    {
        if(p1==head1) head1=p1->next; else p2->next=p1->next;
        printf("已删除该编号课程!\n");
        N1=N1-1;
        //被动退课 
	struct student * p;
    int i,j;
    p=head2;
    while(p != NULL)
    {
    	for (i=0; i < p->nelen; i++)
    	{
    		if(p->nelenum[i] == num1)
    		{
    			for (j=i;p->nelenum[j]!=0;j++) p->nelenum[j]=p->nelenum[j+1];
    			p->nelenum[--j]=0;
    			(p->nelen)--;
    			p->nelescore = p->nelescore - p1->score; 
    			printf("选择该课程的学生退课成功!\n");
			}
		}
		p = p -> next;
	}    
    } 
	else printf("无该编号的课程!\n");
}

void changec(int num1)//课程管理子函数(修改课程)
{
	struct couse *p1;
	struct student * p;
	int i,j, tmp = 0, num2, tmp1 = 0;
	start:
		tmp1=num1;
    if(head1==NULL) 
    {
        printf("\n没有课程,无法修改!\n");
        return;
    }
    p1=head1;
    while(num1!=p1->num1 && p1->next!=NULL) 
    {
        p1=p1->next;
    }
    if(num1==p1->num1) 
    {
        tmp = p1 -> score;
		printf("课程编号 课程名称 课程性质 授课学时 学分 课程已选人数 课程人数上限\n");
    	printf("%-5d%10s%10s%7d%6d%11d%12d\n\n",p1->num1,p1->name1,p1->type,p1->time,p1->score,p1->nelepeo,p1->Melepeo); 
    	printf("已选该课程学生信息:\n");
    if(p1->nelepeo==0) 
    {
        printf("没有学生选课!\n");
        return;
    }
    p=head2;
    printf("学生学号 学生姓名 已选课程数量 已选课程总计学分\n");
    for (i=0; i < p1 -> nelepeo; i++) 
    {
        for(j = 0; j < p->nelen; j++)
        {
        	if(p->nelenum[j] == p1->num1)
        	{
        		printf("%-4d %10s %8d %13d\n",p->num2,p->name2,p->nelen,p->nelescore);
        		break;
			}
		 }
		 if(j >= p -> nelen)
		 {
		 	p = p -> next;
		 	i--;
		  } 
		  else
		  {
		  	p = p -> next;
		  }
    }
    	printf("\n1.修改课程编号\n");
    	printf("2.修改课程名称\n");
		printf("3.修改授课学时\n");
		printf("4.修改学分\n"); 
		printf("5.修改课程人数\n");
		printf("6.修改课程人数上限\n");
		printf("7.返回主页面\n");
		printf("请输入(1~7):\n");
		scanf("%d", &i);
		printf("\n\n");
		p=head2;
		switch(i)
		{
			case(1):
				printf("请输入新的课程编号: ");
				scanf("%d", &p1->num1);
				num1=p1->num1;
				while(p)
				{
					for (i=0;i < p->nelen;i++)
					{
						if(p->nelenum[i]==tmp1)
						{
							p->nelenum[i]=num1;
						}
					}
					p = p -> next;
				}
				printf("课程编号修改成功!\n\n"); 
				goto start;
				break;
			case(2):
				printf("请输入新的课程名称: ");
				scanf("%d", p1->name1);
				printf("课程名称修改成功!\n\n"); 
				goto start;
				break;
			case(3):
				printf("请输入新的学时: ");
				scanf("%d", &p1->time);
				printf("课程信息修改成功!\n\n"); 
				goto start;
				break;
			case(4):
				printf("请输入新的学分: ");
				scanf("%d", &p1->score);
				//被动改课 
    while(p != NULL)
    {
    	for (i=0; i < p->nelen; i++)
    	{
    		if(p->nelenum[i] == num1)
    		{
    			p->nelescore = p->nelescore - tmp + p1 -> score;
			}
		}
		p = p -> next;
	}
				printf("课程信息修改成功!\n\n"); 
				goto start;
				break;
			case(5):
				printf("1.删除学生\n");
				printf("2.增加学生\n");
				printf("3.返回主页面\n");
				printf("请输入(1~2)\n");
				scanf("%d", &i);
				switch(i)
				{
					case(1)://被动退课 
						printf("\n请输入要删除的学生学号:");
						scanf("%d", &num2);
						while(num2!=p->num2 && p->next!=NULL) 
    					{
        					p=p->next;
    					}
						if(num2 == p->num2)
						{
							for (i=0;p->nelenum[i]!=num1;i++);
    						for (j=i;p->nelenum[j]!=0;j++) p->nelenum[j]=p->nelenum[j+1];
    						p->nelenum[--j]=0;
    						(p1->nelepeo)--;
    						p->nelescore = p->nelescore - p1->score; 
    						(p->nelen)--;
    						printf("删除成功!\n\n");
						}
						else
					    {
					    	printf("\n无此学生!\n\n");
						}
						break;
					case(2)://被动选课 
						printf("\n请输入要增加的学生学号:");
						scanf("%d", &num2);
						while(num2!=p->num2 && p->next!=NULL) 
    					{
        					p=p->next;
    					}
						if(num2 == p->num2)
						{
							for (i=0;p->nelenum[i]!=0;i++);
    						p->nelenum[i]=num1;
    						(p->nelen)++;
    						(p1->nelepeo)++;
    						p->nelescore = p->nelescore + p1->score;
    						printf("添加成功!\n\n");
						} 
						else
					    {
					    	printf("\n无此学生!\n\n");
						}
						break;
					case(3):
						break;
				 } 
				goto start;
				break;
			case(6):
				printf("请输入新的人数上限: ");
				scanf("%d", &p1->Melepeo);
				printf("课程信息修改成功!\n\n"); 
				goto start;
				break;
			case(7):
				system("clear");
			break;
		}
    } 
	else printf("无该编号的课程!\n\n");
} 

void listc()//输出课程信息 (简单） 
{
    struct couse * p;
    p=head1;
    printf("课程编号 课程名称 课程性质 授课学时 学分 课程已选人数 课程人数上限\n");
    while(p!=NULL) 
    {
        printf("%-5d%10s%10s%7d%6d%11d%12d\n",p->num1,p->name1,p->type,p->time,p->score,p->nelepeo,p->Melepeo);
        p=p->next;
    }
}

void hstudent()//输出课程信息（详细） 
{
    struct couse * p0;
    struct student * p;
    int num1,i,j;
    printf("请输入课程编号:\n");
    scanf("%d",&num1);
    p0=head1;
    p=head2;
    while(p0->num1!=num1 && p0!=NULL) p0=p0->next;
    if(p0==NULL) 
    {
        printf("不存该课程的信息,请回主菜单录入信息:\n");
        goto end;
    }
    if(p0->nelepeo == 0)
    {
    	printf("尚无学生选择该课!\n\n");
		goto end;
	}
    printf("课程编号 课程名称 课程性质 授课学时 学分 课程已选人数 课程人数上限\n");
    printf("%-5d%10s%10s%7d%6d%11d%12d\n\n",p0->num1,p0->name1,p0->type,p0->time,p0->score,p0->nelepeo,p0->Melepeo);
    printf("已选该课程学生信息:\n");
    if(p0->nelepeo==0) 
    {
        printf("没有学生选课!\n");
        goto end;
    }
    printf("学生学号 学生姓名 已选课程数量 已选课程总计学分\n");
    for (i=0; i < p0 -> nelepeo; i++) 
    {
        for(j = 0; j < p->nelen; j++)
        {
        	if(p->nelenum[j] == p0->num1)
        	{
        		printf("%-4d %10s %8d %13d\n",p->num2,p->name2,p->nelen,p->nelescore);
        		break;
			}
		 }
		 if(j >= p -> nelen)
		 {
		 	p = p -> next;
		 	i--;
		  } 
		  else
		  {
		  	p = p -> next;
		  }
    }
    end:;
} 

void managementc()//课程管理主函数 
{
    int i,num1;
    start:
    printf("\t\t\t课程管理\n");
    printf("1.新增课程\n");
    printf("2.删除课程\n");
    printf("3.修改课程\n");
    printf("4.查看课程信息\n");
    printf("5.返回\n");
    printf("请选择(1~5):\n");
    scanf("%d",&i);
    printf("\n\n");
    switch(i) 
    {
        case(1): 
        { 
            insertc();
            printf("\n\n");
            goto start;
            break;
        }
        case(2): 
        {
            printf("请输入要删除课程的编号:\n");
            scanf("%d",&num1);
            delc(num1);
            printf("\n\n");
            goto start;
            break;
        }
        case(3):
		{
			printf("请输入要修改课程的编号:\n");
			scanf("%d",&num1);
			changec(num1);
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
				listc();
				break;	
				case(2):
				hstudent();
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

void intoc()//存储课程信息 
{
    FILE *fp;
    struct couse *p;
    char filepath[30];
    printf("输入课程信息要保存的文件路径:");
    getchar();
    gets(filepath);
    if((fp=fopen(filepath,"w"))==NULL) 
    {
        printf("\n保存失败!");
        return;
    }
    p=head1;
    while(p!=NULL) 
    {
        fprintf(fp,"%d %s %s %d %d %d %d\n",p->num1,p->name1,p->type,p->time,p->score,p->nelepeo,p->Melepeo);
        p=p->next;
    }
    fclose(fp);
    printf("课程信息已保存在%s中!\n",filepath);
}
