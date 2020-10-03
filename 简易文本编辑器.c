#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100


struct hang 
{
   char wenben[MAX];
   int num;//���� 
   struct hang *next;//ָ����һ�е�ָ�� 
   struct hang *prior;//ָ����һ�е�ָ�� 
};

struct hang *start;//ָ�����Ա��һ�е�ָ�� 
struct hang *last;//ָ�����Ա����һ�е�ָ��
 
int pphh;//ƥ�䵽���к� 

int menu();


void cr(int hs);//�в��� 
void crstr(char str[], int hs, int wz);//�ַ�������
void load();//װ���ļ� 
void print();//��ʾ�ļ����� 
void bc();//�����ļ� 
void scstr(int hs, int wz, int lenth);//ɾ���ַ��� 
int czstr(char * to_cz);//�����ַ���λ�� 


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
				printf("\t�к�:");
				scanf("%d", &hs);
				cr(hs);
				break;
			case 2:  
				printf("�������λ��һ�кţ�");
				scanf("%d", &hs);
				printf("�������λ��-�кţ�");
				scanf("%d", &number);
				printf("Ҫ������ַ�����");
				scanf("%s", str);
				crstr(str, hs, number);
				break;

			case 3:   
				break;
			}
			break;
		case 2:   
				printf("Ҫɾ�����ַ�����");
				scanf("%s", str);
				number = czstr(str);
				if (number == -1)
					printf("û���ҵ�");
				else
					scstr(pphh, number, strlen(str));
				break;
		case 3:
                print();
				break;
		case 4:		
			    printf("������Ҫ���ҵ��ַ�����");
			    scanf("%s", str);
			    number = czstr(str);
			    if (number == -1)
				printf("û���ҵ�");
			    else
				printf("Ҫ���ҵ��ַ��������к�:%d���к�:%d\n", pphh, number+1);
			    break;
		case 5:		
			    printf("���뱻�滻���ַ�����");
			    scanf("%s", str);
			    number = czstr(str);
			    if (number == -1)
				   printf("û���ҵ�");
			    else
			    {
				  scstr(pphh, number, strlen(str));
				  printf("Ҫ�滻���ַ�����");
				  scanf("%s", str);
				  crstr(str, pphh, number + 1);
			     }
			    break;
			
		case 6:    
			    choice = menu2();  
			   switch (choice)
			  {
			    case 1:  
				     printf("����Ҫ�ƶ����ַ��������кţ�");
				     scanf("%d", &hs);
				     crkbh(hs);
				     break;
			    case 2:   //�����ƶ�һ��
				     printf("����Ҫ�ƶ����ַ��������кţ�");
				     scanf("%d", &hs);
				     scwenben(hs - 1);
				     break;
			    case 3:   //�����ƶ�һ��
				     printf("����Ҫ�ƶ����ַ��������кţ�");
				     scanf("%d", &hs);
				     printf("����Ҫ�ƶ����ַ��������кţ�");
				     scanf("%d", &number);
				     str[0] = ' ';
				     str[1] = '\0';
				     crstr(str, hs, number);
			         break;
				case 4:   
				     printf("����Ҫ�ƶ����ַ��������кţ�");
				     scanf("%d", &hs);
				     printf("����Ҫ�ƶ����ַ��������кţ�");
				     scanf("%d", &number);
				     if (number <= 0)
					 printf("���в�����");
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

int menu()//���˵� 
{
	int c;
	
	printf("\n****\(^o^)/~    ��ӭʹ��      \(^o^)/~****\n");
	printf("*             [1]�������                  *\n");
	printf("*             [2]ɾ������                  *\n");
	printf("*             [3]��ʾ                      *\n");
	printf("*             [4]���Ҳ���                  *\n"); 
	printf("*             [5]�滻����                  *\n");
	printf("*             [6]�����ƶ�����              *\n");
	printf("*             [7]�����ļ�                  *\n");
	printf("*             [8]�����ļ�                  *\n");
	printf("*             [9]�˳�                      *\n");
	printf("********************************************\n");
	do
	{
		printf("\t\n������ѡ�");
		scanf("%d",&c); 
	}while(!(c>=1&&c<=9));
	return(c);
}

int menu1()
{
	int c;
	printf("\n\t\t*** ��������˵� ***\n");
	printf("\n\t\t1.*����һ������*\n");
	printf("\t\t2.*����һ������*\n");
	printf("\t\t3.*�����ϼ��˵�*\n");
	do{
		printf("\n\n\t\t�밴����ѡ��");
		scanf("%d", &c);
	} while (!(c >= 1 && c <= 3));
	return(c);
}

//�ƶ������Ӳ˵� 
int menu2()
{
	int c;
	printf("\n*** �ƶ������˵� ***\n");
	printf("\n1.*���������ƶ�*\n");
	printf("2.*���������ƶ�*\n");
	printf("3.*���������ƶ�*\n");
	printf("4.*���������ƶ�*\n");
	printf("5.*  �˳�      *\n");
	do{
		printf("\n\n\t\t��ѡ��");
		scanf("%d", &c);
	} while (!(c >= 1 && c <= 5));
	return(c);
}

void load()
{
	struct hang *o, *qian;  //oָ��ǰ�У�qianָ��o��ǰ����
	char c,name[50];
	FILE *fp;  //�ļ�ָ��
	int inct, i;  //�м�����
	qian = NULL;
	printf("�������ļ��ĵ�ַ����D:\\wenben.txt����");
	scanf("%s",name); 
	if ((fp = fopen(name, "r")) == NULL)
	{
		printf("\t�ļ��򲻿���\n");
		exit(0);
	}
	printf("\n\t���������ļ���\n");
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
			printf("\n���ڴ�");
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
	while (o && o->num != hs)   //��ѯҪ�������
	{
		o = o->next;
	}
	if (o == NULL)
		printf("�����ڸ��У�\n");
	else if (wz < 0)
		printf("�����ڸ��У�\n");
	else    //����к��ж����ڣ�����в���
	{
		lenth = strlen(o->wenben);
		if (lenth < wz)	//�����д��ڱ����ļ�����
		{
			len = wz - lenth - 1;
			for (i = 0; i < len; i++)
				strcat(o->wenben, nostr);   //������Ĳ��ֲ���ո��
			strcat(o->wenben, str);    //�����ַ����е�δβ
		}
		else   //�������ڱ������ֵ��м�
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
	while (p && p->num != hs) //�ҵ�������
	{
		q = p;
		p = p->next;
	}
	if (p == NULL && (q->num + 1) != hs)	//ָ���в����ڣ����ܲ���
	{
		printf("������кŲ�����");
	}
	else // ָ���д��ڣ����в���
	{
		o = (struct hang *)malloc(sizeof(struct hang));
		printf("����Ҫ������ַ���:");
		scanf("%s", o->wenben);
		o->num = hs;
		if (hs == 1)  //�����ڵ�һ��
		{
			o->next = p;
			p->prior = o;
			o->prior = NULL;
			start = o;
		}
		else if (q->num != hs)  //���������һ��
		{
			q->next = o;
			o->next = p;
			o->prior = q;
		}
		else     //������������
		{
			q->next = o;
			o->next = p;
			p->prior = o;
			o->prior = q;
		}
		while (p)   //������ǲ��������һ�У������к�����кŶ���1
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
	printf("������Ҫ������ļ���ַ��");
	scanf("%s",name); 
	if ((fp = fopen(name, "w")) == NULL){
		printf("\t�ļ��򲻿���n");
		exit(0);
	}
	printf("\t���ڴ����ļ���\n");

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
	printf("�ļ�����Ϊ��\n");
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
	pphh = 0;  //ƥ�䵽���к�
	cz_len = strlen(to_cz);
	while (o && !found)   //��ѯ
	{
		i = 0;  //�м�ѭ��
		while (!found && (i <= strlen(o->wenben) - cz_len))  //���ڲ���ѭ��
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
	if (found)  //���ҳɹ�
		wz = i;
	else   //���Ҳ��ɹ�
		wz = -1;
	return(wz);
}

void scstr(int hs, int wz, int lenth)
{
	struct hang * o;
	char cunfang[MAX];
	o=cz(hs);
	if (o == NULL)
		printf("����û���ַ���n");
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
		printf("\t���ڴ治����\n");
		exit(0);
	}
	o->wenben[0] = ' ';
	o->wenben[1] = '\0';
	o->num = hs;
	if (cz(hs))    //���Ҫ���˵��кŴ��ڣ�����в���
	{
		p = start;
		if (hs == 1)    //����������
		{
			o->next = p;
			start = o;
			o->prior = NULL;
			p->prior = o;
		}
		else  //������������
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
		printf("���в�����");
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
		printf("���в�����");
	else
	{
		p = o->next;
		if (start == o) //���ɾ�����ǵ�һ��
		{
			start = o->next;
			if (start)  //���ɾ���󣬲�Ϊ��
				start->prior = NULL;
			else  //ɾ����Ϊ��
				last = NULL;
		}
		else
		{
			o->prior->next = o->next;  //ָ���е���һ��ָ��ָ���е���һ��
			if (o != last) //����������һ��
				o->next->prior = o->prior;  //�޸�����һ�е�ָ��ͷ��ָ�� 
			else  //��������һ�У��޸�βָ��
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


