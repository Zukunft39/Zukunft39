/*��Ʒ���۽���*/
/*�����Ʒ����*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#include <windows.h>
struct comments{//�ṹ�� 
	int num;
	char type[50];
	char judgeMent[20];	
	char name[100];	
	char com[200];
	char attitude;
	int timeWait ;
	char yourJudgeMent[200]; 	
};
struct comments com[] = {//�ṹ������� 
	{10001,"�������ȱ�","������","�ϵ»���үү","Oh��Honey mom��",'Y',28},
	{10002,"ը����","������","��������������","�����~���ϣ���ó�",'Y',17},
	{10003,"����","������","W","�����ܴ�����ȥ��������һ��",'Y',10},
	{10004,"ţ�Ɽ","������","������","ţ���ʸк�Ӳ������ʱ��̫���ˣ����Ǻܺó�",'N',43},	
	{10005,"����","������","������","��~���ֺúú�",'Y',19},
	{10006,"������","������","������","ʲô������������Ǳ��ɣ����ǵ����������......",'Y',25}	
};
int comment(void)//��ӡ��Ʒ���� 
{
	struct comments *p;
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("|�û�����\t          ��Ʒ����\t\t\t��Ʒ����\t\t   �ǳ�\t\t\t        �������\t\t                           �Ƿ����(Y/N)  �ȴ�ʱ��/min|\n");
	for(p = com;p<com+6;p++)
	{
		printf("|%-5d  \t\t  %-20s\t\t%-20s       %-20s         %-50s  %-5c         %-6d      |\n",p->num,p->type,p->judgeMent,p->name,p->com,p->attitude,p->timeWait);
	}
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
} 
int commentAndYours(char judgeMentByStarByChar[],char yourJudgeMent[],char yesOrNotByChar)//��ӡ��Ʒ�����Լ������� 
{
	int i = 10006;
	int timeRand = 0; 
	struct comments *p;
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("|�û�����\t          ��Ʒ����\t\t\t��Ʒ����\t\t   �ǳ�\t\t\t        �������\t\t                           �Ƿ����(Y/N)  �ȴ�ʱ��/min|\n");
	for(p = com;p<com+6;p++)
	{
		printf("|%-5d  \t\t  %-20s\t\t%-20s       %-20s         %-50s  %-5c         %-6d      |\n",p->num,p->type,p->judgeMent,p->name,p->com,p->attitude,p->timeWait);
	}
	srand((unsigned int)time(NULL));
	while(timeRand != 1)
	{
		if(timeRand<40&&timeRand>20) break;
		else timeRand = rand();
	}
	p->num = i + 1 ; 
	strcpy(p->type,"�㹺�����Ʒ");		
 	strcpy(p->judgeMent,judgeMentByStarByChar); 
 	strcpy(p->name,"��");
 	strcpy(p->com,yourJudgeMent);//p->com = yourJudgeMent;
 	p->attitude = yesOrNotByChar;
 	p->timeWait =  timeRand;
	printf("|%-5d  \t\t  %-20s\t\t%-20s       %-20s         %-50s  %-5c         %-6d      |\n",p->num,p->type,p->judgeMent,p->name,p->com,p->attitude,p->timeWait); 
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
} 
void humanTest()//������֤��������ǲ����˻� 
{
	int randNum = 0;
	int enterNum = 0;
	srand((unsigned int)time(NULL));
	while(randNum != 1)
	{
		if(randNum<=9999&&randNum>=1000) break;
		else randNum = rand();
	}
	printf("Ϊ���ж�������ݣ����������Ҳ����֤��:%d\n",randNum);
	scanf("%d",&enterNum);
	while(enterNum != randNum)
	{
		printf("������֤��������������룺");
		scanf("%d",&enterNum); 
	}
	printf("��֤�ɹ�~ >W< ");	
}
void errorYesOrNot()//�ж����Ƿ�鿴�����۽��� ������Ϊ�� 
{
	printf("��ȡ���鿴�������\n\n");
} 
void remainComment()//�ж����Ƿ�鿴�����۽��棨����Ϊ�ǣ� 
{
	comment();
}
void clearScreen()//���ٴβ鿴����ʱ�����鿴 
{
	system("cls");
}
void loadYourComment(char arr[])//����������� 
{	
	char loadScene[8] = "\0";
	for(int i = 0;i<7;i++)
	{
		loadScene[i] = arr[i]; 
		printf("�����ϴ���%s\n",loadScene);
		Sleep(1000);
	}
	printf("�ϴ��ɹ���\n");
	humanTest(); 
} 
void writeComment()//��ӡ�˵�ʱ����������� 
{
	printf("���ٴ��������������Ա������Ǹ��õļ�¼���� >W< (�����۽����������˵���ӡ����)\n");
	char loadScene[8] = " ......";
	char ch[200];
	FILE*fp;
	fp = fopen("�����˵�", "w");
 	if(fp==NULL)
	{
		perror("�����˵�");
		return;
	}
	scanf("%s",ch);   
	fprintf(fp,"%s",ch);	
	fclose(fp);
	fp=NULL;	 
	loadYourComment(loadScene); //���������ϴ����� 	
}
int readComment()//��ȡ���˵��ϵ����� 
{
	char str[200];
	FILE*fp;
	fp = fopen("�����˵�", "r"); 
	if(fp==NULL)
	{
		perror("�����˵�");
		return 1;
	}
	fgets(str,200,fp);
	printf("%s",str);	
	fclose(fp);
	fp=NULL;	
} 
int main(void)//���۽��������� 
{
	int yesOrNot;
	char yesOrNotByChar; 
	int judgeMentByStar = 0; 
	char judgeMentByStarByChar[20] = "\0"; 
	char yourJudgeMent[200];
	char loadScene[8] = " ......";
	char judgeMentStar1[20] = "������";
	char judgeMentStar2[20] = "������";
	char judgeMentStar3[20] = "������";
	char judgeMentStar4[20] = "������";
	char judgeMentStar5[20] = "������";
	
	
	struct comments *pJudge;
	
		
	printf("�Ƿ�鿴���ڸõ��̵��й����ۣ�����1��ʾȷ�ϣ���0��ʾȡ����\n");//��ʾ���۽��� 
	scanf("%d",&yesOrNot);
	while (yesOrNot!=65500) 
	{
		switch (yesOrNot)
		{
			case 0:errorYesOrNot();
			break;
			case 1:comment();
			printf("\n");
			break;
			default:printf("�޴�ѡ��!\n\n"); 
			printf("�Ƿ�鿴���ڸõ��̵��й����ۣ�����1��ʾȷ�ϣ���0��ʾȡ����\n");//��ʾ���۽��� 
			scanf("%d",&yesOrNot);
			continue;	
		}	
		break;
	} 
	
		
	printf("��Ҫȡ����ʾ������0���,��Ҫ������ʾ��������1\n\n");//�Ƿ�������ʾ���۽��� 
	scanf("%d",&yesOrNot);
	while(yesOrNot!=65500)
	{
		switch (yesOrNot)
		{
			case 0:clearScreen();
			break;
			case 1:clearScreen();
			remainComment();
			break; 
			default:printf("�޴�ѡ��!\n\n"); 
			printf("��Ҫȡ����ʾ������0���,��Ҫ������ʾ��������1\n\n");
			scanf("%d",&yesOrNot);
			continue;
		}
		break;
	}
	
	
	
	printf("�ף�����Ʒһ�����۰ɣ�(1��ʾ������0��ʾ����)\n");//����Ʒ����&���� 
	printf("�ҵ����ۣ�");		 
	while(yesOrNot!=65500) 
	{
		scanf("%d",&yesOrNot);
		switch(yesOrNot)
		{
			case 1:printf("��л���ĺ��������ǻ�Խ��Խ�õ� >W<���� \n\n"); 
			yesOrNotByChar = 'Y';
			break;
			case 0:printf("��л�������ۣ����ǻ᲻�ϸĽ��� QAQ������\n\n"); 
			yesOrNotByChar = 'N';
			break;
			default :printf("�޴�ѡ�\n\n");
			printf("�ҵ����ۣ�");	
			continue; 
		}		
		break;
	}
	
	
	
	printf("�׾��������������Ʒ��ô��������ʹ�����ְɣ�\n\n");//����Ʒ���� 
	printf("����������Ŀ�͵�����̶�(����1~5��֮�ڴ��)��");	
	while(judgeMentByStar!=65500) 
	{
		scanf("%d",&judgeMentByStar); 
		switch (judgeMentByStar)
		{
			case 1:printf("\n\n%s\n\n",judgeMentStar1);
			strcpy(judgeMentByStarByChar,judgeMentStar1);
			break;
			case 2:printf("\n\n%s\n\n",judgeMentStar2);
			strcpy(judgeMentByStarByChar,judgeMentStar2);
			break;
			case 3:printf("\n\n%s\n\n",judgeMentStar3);
			strcpy(judgeMentByStarByChar,judgeMentStar3);
			break;
			case 4:printf("\n\n%s\n\n",judgeMentStar4);
			strcpy(judgeMentByStarByChar,judgeMentStar4);
			break;
			case 5:printf("\n\n%s\n\n",judgeMentStar5);
			strcpy(judgeMentByStarByChar,judgeMentStar5);
			break;
			default:printf("�޴�ѡ��!\n\n"); 
			printf("����������Ŀ�͵�����̶�(����1~5��֮�ڴ��)��");
			continue;						
		}
		break;			
	}
	
	
	printf("�������Ʒдһ�����۰ɣ����������뽨���Ƕ���������֧��!\n");//��¼������� 
	scanf("%s",yourJudgeMent); 
	
	writeComment();//д���� 
		
	
	printf("��л�������ۣ�\n");//��¼������� 
	printf("�밴��1����ʾ�������µ����ۣ�����2����ʾ�������ۣ�����0���·���ѡ����Ʒ������:");//��ʾ���µ�����&�˳����۽��� 
	scanf("%d",&yesOrNot);
	while(yesOrNot)
	{
		switch (yesOrNot)
		{
			case 0://������Ʒѡ����� ���˳����۽��棩 
			break; 
			case 1: commentAndYours(judgeMentByStarByChar,yourJudgeMent,yesOrNotByChar);//��ʾ�������� 
			break;
			case 2: readComment();//ֻ��ʾ������� 
			break; 
			default:printf("�޴�ѡ��!\n\n");
			printf("�밴��1����ʾ�������µ����ۣ�����2����ʾ�������ۣ�����0���·���ѡ����Ʒ������:");
			scanf("%d",&yesOrNot);
			continue;
		}
		break;
	} 	
} 
