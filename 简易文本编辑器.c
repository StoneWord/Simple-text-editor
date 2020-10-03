#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100


struct hang 
{
   char wenben[MAX];
   int num;//行数 
   struct hang *next;//指向下一行的指针 
   struct hang *prior;//指向上一行的指针 
};

struct hang *start;//指向线性表第一行的指针 
struct hang *last;//指向线性表最后一行的指针
 
int pphh;//匹配到的行号 

int menu();


void cr(int hs);//行插入 
void crstr(char str[], int hs, int wz);//字符串插入
void load();//装入文件 
void print();//显示文件内容 
void bc();//保存文件 
void scstr(int hs, int wz, int lenth);//删除字符串 
int czstr(char * to_cz);//查找字符串位置 


int menu1();
int menu2();
void crkbh(int hs);
void scwenben(int hs);
void fuwei(int n, int incr);
struct hang *cz(int hs);

int main(int argc, char *argv[]) 
{
	char str[MAX];
	int choice;
	int hs=1;
	int number=0;
	start=NULL;
	last=NULL;
	load();
	print(); 
	
	do
	{
		choice=menu();
		switch(choice)
		{
		case 1:		
			choice = menu1();
			switch (choice)
			{
			case 1:   
				printf("\t行号:");
				scanf("%d", &hs);
				cr(hs);
				break;
			case 2:  
				printf("输入插入位置一行号：");
				scanf("%d", &hs);
				printf("输入插入位置-列号：");
				scanf("%d", &number);
				printf("要插入的字符串：");
				scanf("%s", str);
				crstr(str, hs, number);
				break;

			case 3:   
				break;
			}
			break;
		case 2:   
				printf("要删除的字符串：");
				scanf("%s", str);
				number = czstr(str);
				if (number == -1)
					printf("没有找到");
				else
					scstr(pphh, number, strlen(str));
				break;
		case 3:
                print();
				break;
		case 4:		
			    printf("输入想要查找的字符串：");
			    scanf("%s", str);
			    number = czstr(str);
			    if (number == -1)
				printf("没有找到");
			    else
				printf("要查找的字符串所在行号:%d，列号:%d\n", pphh, number+1);
			    break;
		case 5:		
			    printf("输入被替换的字符串：");
			    scanf("%s", str);
			    number = czstr(str);
			    if (number == -1)
				   printf("没有找到");
			    else
			    {
				  scstr(pphh, number, strlen(str));
				  printf("要替换的字符串：");
				  scanf("%s", str);
				  crstr(str, pphh, number + 1);
			     }
			    break;
			
		case 6:    
			    choice = menu2();  
			   switch (choice)
			  {
			    case 1:  
				     printf("输人要移动的字符串所在行号：");
				     scanf("%d", &hs);
				     crkbh(hs);
				     break;
			    case 2:   //向上移动一行
				     printf("输入要移动的字符串所在行号：");
				     scanf("%d", &hs);
				     scwenben(hs - 1);
				     break;
			    case 3:   //向右移动一列
				     printf("输人要移动的字符串所在行号：");
				     scanf("%d", &hs);
				     printf("输入要移动的字符串所在列号：");
				     scanf("%d", &number);
				     str[0] = ' ';
				     str[1] = '\0';
				     crstr(str, hs, number);
			         break;
				case 4:   
				     printf("输入要移动的字符串所在行号：");
				     scanf("%d", &hs);
				     printf("输入要移动的字符串所在列号：");
				     scanf("%d", &number);
				     if (number <= 0)
					 printf("该列不存在");
				     else
					  scstr(hs, number - 2, 1);
				      break;
			    case 5:   
				    break;
			    }
			    break;
		case 7:
				bc();
				break;
		case 8:
				load();
				break;
		case 9:
				exit(0);
				break;
		}
	 } while(1);
    system("pause");
	return 0;
}

int menu()//主菜单 
{
	int c;
	
	printf("\n****\(^o^)/~    欢迎使用      \(^o^)/~****\n");
	printf("*             [1]插入操作                  *\n");
	printf("*             [2]删除操作                  *\n");
	printf("*             [3]显示                      *\n");
	printf("*             [4]查找操作                  *\n"); 
	printf("*             [5]替换操作                  *\n");
	printf("*             [6]行列移动操作              *\n");
	printf("*             [7]保存文件                  *\n");
	printf("*             [8]载入文件                  *\n");
	printf("*             [9]退出                      *\n");
	printf("********************************************\n");
	do
	{
		printf("\t\n请输入选项：");
		scanf("%d",&c); 
	}while(!(c>=1&&c<=9));
	return(c);
}

int menu1()
{
	int c;
	printf("\n\t\t*** 插入操作菜单 ***\n");
	printf("\n\t\t1.*插入一行文字*\n");
	printf("\t\t2.*插入一段文字*\n");
	printf("\t\t3.*返回上级菜单*\n");
	do{
		printf("\n\n\t\t请按数字选择：");
		scanf("%d", &c);
	} while (!(c >= 1 && c <= 3));
	return(c);
}

//移动操作子菜单 
int menu2()
{
	int c;
	printf("\n*** 移动操作菜单 ***\n");
	printf("\n1.*该行向下移动*\n");
	printf("2.*该行向上移动*\n");
	printf("3.*该列向右移动*\n");
	printf("4.*该列向左移动*\n");
	printf("5.*  退出      *\n");
	do{
		printf("\n\n\t\t请选择：");
		scanf("%d", &c);
	} while (!(c >= 1 && c <= 5));
	return(c);
}

void load()
{
	struct hang *o, *qian;  //o指向当前行，qian指向o的前驱行
	char c,name[50];
	FILE *fp;  //文件指针
	int inct, i;  //行计数器
	qian = NULL;
	printf("请输入文件的地址（如D:\\wenben.txt）：");
	scanf("%s",name); 
	if ((fp = fopen(name, "r")) == NULL)
	{
		printf("\t文件打不开！\n");
		exit(0);
	}
	printf("\n\t正在载入文件！\n");
	printf("\n\n");
	
	start = (struct hang*)malloc(sizeof(struct hang)); 
	o = start;
	inct = 1;
	while ((c=fgetc(fp)) != EOF)
	{	
		i=0;
		o->wenben[i] = c;
		i++;
		while ((c=fgetc(fp))!='\n')  
		{
			o->wenben[i] = c;
			i++;
		}
		
		o->wenben[i] = '\0';  
		o->num = inct++;  
		o->next = (struct hang*)malloc(sizeof(struct hang));
		if (!o->next)
		{
			printf("\n无内存");
			exit(0);
		}
		o->prior = qian;
		qian = o;
		o = o->next;
	}
	qian->next = NULL;
	last = qian;
	free(o);
	start->prior = NULL;
	fclose(fp);
}

void crstr(char str[], int hs, int wz)
{
	struct hang * o;
	int len, i;
	int lenth;
	char cunfang[MAX], nostr[2] = { " " };
	o = start;
	while (o && o->num != hs)   //查询要插入的行
	{
		o = o->next;
	}
	if (o == NULL)
		printf("不存在该行！\n");
	else if (wz < 0)
		printf("不存在该列！\n");
	else    //如果行和列都存在，则进行插入
	{
		lenth = strlen(o->wenben);
		if (lenth < wz)	//插入列大于本行文件列数
		{
			len = wz - lenth - 1;
			for (i = 0; i < len; i++)
				strcat(o->wenben, nostr);   //将空余的部分插入空格符
			strcat(o->wenben, str);    //插入字符到列的未尾
		}
		else   //插入列在本行文字的中间
		{
			strcpy(cunfang, &o->wenben[wz - 1]);
			strcpy(&o->wenben[wz - 1], str);
			strcat(o->wenben, cunfang);
		}
	}
}

void cr(int hs)
{
	struct hang * o, * q, * p;
	p = start;
	q = NULL;
	while (p && p->num != hs) //找到插入行
	{
		q = p;
		p = p->next;
	}
	if (p == NULL && (q->num + 1) != hs)	//指定行不存在，不能插入
	{
		printf("输入的行号不存在");
	}
	else // 指定行存在，进行插入
	{
		o = (struct hang *)malloc(sizeof(struct hang));
		printf("输入要插入的字符串:");
		scanf("%s", o->wenben);
		o->num = hs;
		if (hs == 1)  //插入在第一行
		{
			o->next = p;
			p->prior = o;
			o->prior = NULL;
			start = o;
		}
		else if (q->num != hs)  //插入在最后一行
		{
			q->next = o;
			o->next = p;
			o->prior = q;
		}
		else     //插入在其他行
		{
			q->next = o;
			o->next = p;
			p->prior = o;
			o->prior = q;
		}
		while (p)   //如果不是插入在最后一行，插入行后面的行号都加1
		{
			p->num = p->num + 1;
			p = p->next;
		}
	}
}


void bc()
{
	struct hang	*o;
	char *p;
	FILE *fp;
	char name[50];
	printf("请输入要保存的文件地址：");
	scanf("%s",name); 
	if ((fp = fopen(name, "w")) == NULL){
		printf("\t文件打不开！n");
		exit(0);
	}
	printf("\t正在存入文件！\n");

	o = start;
	while (o)
	{
		p = o->wenben;
		while (*p)
			putc(*p++, fp);
		putc('\n', fp);
		o = o->next;
	}
	fclose(fp);
}

void print()
{
	struct hang * o;
	o = start;
	printf("文件内容为：\n");
	while (o)
	{
		printf("%d:%s\n", o->num, o->wenben);
		o = o->next;
	}
	printf("\n\n");
}



struct hang * cz(int hs)
{
	struct hang * o;
	o = start;
	while (o)
	{
		if (hs != o->num)
			o = o->next;
		else
			break;
	}
	return (o);
}

int czstr(char * to_cz)
{
	struct hang *o;
	int i=0, cz_len, found = 0, wz,w,j;
	char substring[MAX];
	o = start;
	pphh = 0;  //匹配到的行号
	cz_len = strlen(to_cz);
	while (o && !found)   //查询
	{
		i = 0;  //行间循环
		while (!found && (i <= strlen(o->wenben) - cz_len))  //行内查找循环
		{
            w=i;
			for(j=0;j<cz_len;j++,w++)
		    {
		    	substring[j]=o->wenben[w];	    
			}
			substring[cz_len] = '\0';
			if (strcmp(substring, to_cz) == 0)
			{
				found = 1;
				pphh = o->num;
			}
			else
			{
			    ++i;	
			}
				
		}
		o = o->next;
	}
	if (found)  //查找成功
		wz = i;
	else   //查找不成功
		wz = -1;
	return(wz);
}

void scstr(int hs, int wz, int lenth)
{
	struct hang * o;
	char cunfang[MAX];
	o=cz(hs);
	if (o == NULL)
		printf("该行没有字符！n");
	else
	{
		if (strlen(o->wenben) <= (wz + lenth))  
			o->wenben[wz] = '\0';
		else
		{
			strcpy(cunfang, &o->wenben[wz + lenth]);
			strcpy(&o->wenben[wz], cunfang);
		}
	}
}

void crkbh(int hs)
{
	struct hang *o, *p;
	o = (struct hang *)malloc(sizeof(struct hang));
	if (!o)
	{
		printf("\t！内存不够！\n");
		exit(0);
	}
	o->wenben[0] = ' ';
	o->wenben[1] = '\0';
	o->num = hs;
	if (cz(hs))    //如果要插人的行号存在，则进行插入
	{
		p = start;
		if (hs == 1)    //插入在首行
		{
			o->next = p;
			start = o;
			o->prior = NULL;
			p->prior = o;
		}
		else  //插入在其他行
		{
			while (p->next->num != hs)
				p = p->next;
			o->next = p->next;
			p->next->prior = o;
			p->next = o;
			o->prior = p;
		}
		fuwei(hs, 1);
	}
	else
		printf("该行不存在");
}


void fuwei(int n, int incr)
{
	struct hang *i;
	i = cz(n);
	i = i->next;
	while (i)
	{
		i->num = i->num + incr;
		i = i->next;
	}
}


void scwenben(int hs)
{
	struct hang * o, *p;
	o = start;
	while ((o->num < hs) && o)
		o = o->next;
	if (o->next == NULL)
		printf("该行不存在");
	else
	{
		p = o->next;
		if (start == o) //如果删除的是第一行
		{
			start = o->next;
			if (start)  //如果删除后，不为空
				start->prior = NULL;
			else  //删除后为空
				last = NULL;
		}
		else
		{
			o->prior->next = o->next;  //指定行的上一行指向指定行的下一行
			if (o != last) //如果不是最后一行
				o->next->prior = o->prior;  //修改其下一行的指向头的指针 
			else  //如果是最后一行，修改尾指针
				last = o->prior;
		}
		free(o);
		while (p)
		{
			p->num = p->num - 1;
			p = p->next;
		}
	}
}


