#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"less.h"
#include"stu.h"
#include"pub.h"

int main()//主函数 
{
    int i;
    start:
    system("clear"); 
    printf("\n\t\t\t欢迎使用学生选课管理系统\n");
    printf("\t\t---------------------------------------\n");
    printf("\n\t\t\t\t 1.课程模块\n");
    printf("\n\t\t\t\t 2.学生模块\n");
    printf("\n\t\t\t   3.退 出 系 统\n");
    printf("\n\t\t\t  请 输 入 (1 ~ 3) :\n");
    scanf("%d", &i);
    printf("\n\n");
    switch(i)
    {
    	case(1):
    	{
    		les:
		printf("\t\t\t\t课程模块\n");
		printf("\t\t--------------------------------\n");
		printf("1.课程信息录入\n");
    		printf("2.课程信息管理\n");
    		printf("3.课程信息存储\n");
    		printf("4.返回主页面\n");
    		printf("请输入(1~4):\n");
    		scanf("%d", &i);
		printf("\n\n");
    		switch(i)
    		{
    			case(1):
    				inputc();
				printf("\n\n");
    				goto les;
    				break;
    			case(2):
    				managementc();
				printf("\n\n");    	
				goto les;
    				break;
    			case(3):
    				intoc();
				printf("\n\n");
				goto les;
    				break;
    			case(4):
				goto start;
    				break;
		}
	}
	case(2):
	{
		stu:
			printf("\t\t\t\t学生模块\n");
			printf("\t\t---------------------------------\n");
			printf("1.学生信息录入\n");
    			printf("2.学生信息管理\n");
    			printf("3.学生信息存储\n");
    			printf("4.返回主页面\n");
    			printf("请输入(1~4):\n");
    			scanf("%d", &i);
			printf("\n\n");
    			switch(i)
    			{
    				case(1):
    					inputs();
					printf("\n\n");
    					goto stu;
    					break;
    				case(2):
    					managements();
					printf("\n\n");
    					goto stu;
    					break;
    				case(3):
    					intos();
					printf("\n\n");
					goto stu;
    					break;
				case(4):
					goto start;
    					break;		
			}
	}
	case(3):
	{
	    system("clear");
	    printf("\t\t\t感谢使用本系统\n\t\t\t再见\n");
	}
    }
    return(0);
}

