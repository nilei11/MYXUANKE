#ifndef _PUB_H
#define _PUB_H

int N1,N2;
struct couse//课程信息结构体 
{
    int num1;
    char name1[20];
    char type[20];
    int time;
    int score;
    int nelepeo;//课程已选人数
    int Melepeo;//课程人数上限
    struct couse * next;
};

struct student//学生信息结构体 
{
    int num2;
    char name2[20];
    int nelenum[50];//已选课程编号
    int nelen;//已选课程总量
    int nelescore; //总计学分
    struct student *next;
};

struct couse * head1;
struct student * head2;

#endif
