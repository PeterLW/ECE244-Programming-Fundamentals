// ����˹����1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdio.h"
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <malloc.h>
#include <io.h>
#include <time.h> 


typedef struct sisi           //��������ṹ�� 
{
	char xy[4][2];
	int ys;
}XY;



char * she = "��"; //�ô˷��Ż����� 
int sjs = 973;//��Ϊ�ҿ��±����Ƶ��û��������������ֻ�����԰ٶ���һ�¾��������ˣ�������ʱ�������ɣ����Ծʹ�������ô������ 
int wjfs[4];
int yyys;


void huibiankuang(char *);  //���ƿ�ʼ�߿� ��char ���ջ�����ͼ�� 
int gotoxy(int, int);//�趨������꣬===================================��������������Լ�д�ģ����ð��� Simon д ̰ʳ�ߵ�д�ĺ�������û��ѧ��windows��̣�д�������ֺ��� 
void chushibiankuang(); //��ʼ�߿� 
int nandu();//��Ϸ�Ѷ�ѡ�� 
int start(int);//��ʼ��Ϸ���β�Ϊ��Ϸ�Ѷ� 
void qingping(void);//���� 
void startjm(void);//���ƿ�ʼ��Ϸ�߿� 
void bcwj(char *);//�����ļ�
void dqwj(char *);//��ȡ�ļ�
void fkfx(XY *,int,int);//���ݷ��鷽����и�ֵ ,�����Ƿ�����״�ͷ���
void scfk(int *, int *);//���ɷ��飬ָ��ʽ���ط�����״�ͷ��� 
BOOL SetConsoleColor(WORD wAttributes);
void hfk(XY *,char *,int,int);//������
void xxyfs(int);
int jcdd(XY *, int, int);
int fkpz(int xy[10][25], XY, int, int);
int jcbxpz(int xy[10][25], XY, int, int, int, int);
int jtjc(int xy[10][25]);
int jsfs(int dfsz[4],int xy[10][25]);//�÷�����
int fkpzz(int xy[10][25], XY, int, int);
int fkpzy(int xy[10][25], XY, int, int);
void qch(int xy[10][25], int);





int main(void)
{ 
	int nan = 5;//��Ϸ�Ѷȴ��棬0=������1=�м���2=�߼���3=���� ,4=�˳� 
	int fen = 0;
	int xh = 0;
	while(1)
	{
		qingping();//���� 
		xxyfs(7);
		chushibiankuang();//��ʼ���߿� 
		if(access("elsfk.bin",0)==0)//��ⴢ������ļ��Ƿ����
		{
			dqwj("elsfk.bin");//��ȡ�ļ�
			gotoxy(56,3);
			printf("��¼��");
			gotoxy(46,7);
			printf("������߷֣�%d",wjfs[0]);
			gotoxy(46,9);
			printf("�м���߷֣�%d",wjfs[1]);
			gotoxy(46,11);
			printf("�߼���߷֣�%d",wjfs[2]);
			gotoxy(46,13);
			printf("������߷֣�%d",wjfs[3]);
		}
		else//�ļ�������
		{
			for(xh=0; xh<4; xh++)
				wjfs[xh] = 0;
			gotoxy(54,3);
			printf("û�з����ļ�");
		}
		nan = nandu();//�Ѷ�ѡ�� 
		if(nan == 4)
		{
			break;
		}
		fen = start(nan);//��ʼ��Ϸ������ֵΪ��Ϸ����ʱ���� ,nan����Ϸ�Ѷ�
		gotoxy(30,8);
		printf("�~�~�~�~�~�~");
		gotoxy(30,9);
		printf("�~��Ϸ�����~");
		gotoxy(30,10);
		printf("�~�~�~�~�~�~");
		if(fen > wjfs[nan])//�����ǰģʽ�ķ��������ļ�������ķ������Ͱ����·�����������
		{
			wjfs[nan] = fen;
			bcwj("elsfk.bin");
		}
		getch();
	}  
	return 0;
} 





int start(int nan)//��ʼ��Ϸ ��nan����Ϸ�Ѷȣ�0,1,2,3 
{
	int dfhs;//�÷�����
	int dfsz[4];//�÷�����
	int sspd=1;//�����ж�
	int zzz;//��ʱʹ�ã�����ɾ��
	int zzz1;
	int xss=1;//����Ƿ���������ƶ��������ӳ�
	int xhbl1;//ѭ������1
	int xhbl=0;//ѭ���������೤ʱ������һ��
	int bd=0;//�ж������Ƿ��б仯
	int ys;//
	int xlxz;//������״
	int xiax=20;//�����׼����x
	int xiay=0;//�����׼����y
	int xiaxf;//���ұ���
	int xiayf;//�������
	int xxing=0;//���б��� 
	int xz;//��״
	int fx;//��ǰ����
	int xxz;//��һ��������״ 
	int xfx;//��һ�����鷽�� 
	int xy[10][25]={0};//�����������
	struct sisi xialuo;  //������� 
	struct sisi xiayige; //��һ��������� 
	char jcbl=0;//������ 
	char jsxz;//������״ 
	char xzfx;  //������״���� 
	int shijian;//�����ӳ� 
	int lsfs=0;//��ʱ���� 
	int dq;//��ȡ��������  
	int fen=0;//��Ϸ���� 
	startjm();//���ƿ�ʼ��Ϸ�߿� 
	if(nan == 0)        //�����Ѷȵ���������ٶ�
	{
		shijian = 50;
	}
	if(nan == 1)
	{
		shijian = 35;
	}
	if(nan == 2)
	{
		shijian = 20;
	}
	if(nan == 3)
	{
		shijian = 35;
	}
	gotoxy(69, 10);
	if(nan == 0)
		printf("��  ��");
	if(nan == 1)
		printf("��  ��");
	if(nan == 2)
		printf("��  ��");
	if(nan == 3)
	{
		printf("��  ��");
		gotoxy(70,11);
		xxyfs(3);
		printf("%d%%",(int)(((float)shijian)/35.0*100));
	}
	gotoxy(69,8);
	xxyfs(3);
	printf("%d",wjfs[nan]);//��ʾ��߷�

	//��ʼ�� 
	SetConsoleColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN );
	scfk(&xxz, &xfx);
	fkfx(&xiayige, xxz, xfx); 
	xiayige.ys = time(NULL)%6+2;
	xxyfs(xiayige.ys);
	hfk(&xiayige, she, 50, 9);
	gotoxy(69, 4);
	if(wjfs[nan]<fen)
		xxyfs(2);
	else
		xxyfs(1);
	printf("%d",fen);//��ʾ��ǰ����
	while(sspd)//��ʽ���� 
	{
		xhbl++;
		sjs++;

		if(jcbl == 0)//û������ķ���ʱ�����ɷ��� 
		{
			fx = xfx;
			xialuo = xiayige;
			xz = xxz;
			fx = xfx;
			hfk(&xiayige, "  ", 50, 9); 
			scfk(&xxz, &xfx);//����������һ�����麯�� 
			fkfx(&xiayige, xxz, xfx);  //������ֵ
			xiayige.ys = (rand())%6+2;//������һ��������ɫ
			xxyfs(xiayige.ys);
			hfk(&xiayige, she, 50, 9);//����һ������ 
			jcbl = 1; //��Ϊ�з�������
			xiayf=-3;//�������±�����ֵ
			xiaxf=8;//�������ұ�����ֵ
		} 
		if((xhbl%5) == 0)
		{

			if(jcdd(&xialuo,xiax+xiaxf, xiay+xiayf) || fkpz(xy,xialuo, xiaxf, xiayf))
			{
				if(jtjc(xy))
				{
					return fen;
				}
				for(xhbl1=0; xhbl1<4; xhbl1++)
				{
					xy[(xialuo.xy[xhbl1][0]*2+xiaxf)/2-1][xialuo.xy[xhbl1][1]+xiayf] = xialuo.ys;
				}
				dfhs = jsfs(dfsz,xy);//�������
				if(dfhs > 0)
				{
					if(nan == 3)
					{
						lsfs=lsfs+dfhs;
						if(lsfs%40==0)
							shijian--;
						if(shijian<10)
						{
							shijian=10;
						}
						gotoxy(70,11);
						xxyfs(3);
						printf("%d%%",(int)(((float)shijian)/35.0*100));
					}
					if(dfhs == 1)
					{
						fen++;
					}
					else
					{
						fen=fen+(1<<dfhs);
					}
					gotoxy(69, 4);
					if(wjfs[nan]>fen)
						xxyfs(1);
					else
						xxyfs(2);
					printf("%d",fen);//��ʾ��ǰ����

					dfhs=0;
				}
				jcbl = 0; 
				continue;
			}
			xhbl = 0;
			hfk(&xialuo, "  ", xiax+xiaxf, xiay+xiayf);
			xiayf++;
			xxyfs(xialuo.ys);
			hfk(&xialuo, she, xiax+xiaxf, xiay+xiayf);
		}
		if(xss >0)
			Sleep(shijian);
		xss = 1;
		if(kbhit())//���������� 
		{
			dq = getch();
			if(dq == 32)//�����¿ո�ʱ����ͣ 
			{
				gotoxy(68,22); // 
				printf("��Ϸ��ͣ");
				getch(); 
				gotoxy(68,22); // 
				printf("        ");         
			}  
			if(dq == 224)//����������ư�����ʱ�� 
			{
				dq = getch();
				if((dq == 72))//����Ƿ����� 
				{
					if(jcbxpz(xy, xialuo, xz, fx, xiaxf, xiayf))
					{
						fx++;
						if(fx==4)
						{
							fx = 0;
						}
						if(xz == 4 || xz == 2 || xz == 3)
						{
							if(fx>1)
								fx=fx-2;
						}
						hfk(&xialuo, "  ", xiax+xiaxf, xiay+xiayf);
						fkfx(&xialuo, xz, fx);
						hfk(&xialuo, she, xiax+xiaxf, xiay+xiayf);
						xss = 0;
					}
				}
				if(dq == 80)
				{
					xhbl = -1;
				}
				if(dq == 75 && xialuo.xy[0][0]+xiaxf>2 && xialuo.xy[1][0]+xiaxf>2 && xialuo.xy[2][0]+xiaxf>2 && xialuo.xy[3][0]+xiaxf>2 && fkpzz(xy, xialuo, xiaxf, xiayf))
				{
					hfk(&xialuo, "  ", xiax+xiaxf, xiay+xiayf);
					xiaxf=xiaxf-2;
					xxyfs(xialuo.ys);
					hfk(&xialuo, she, xiax+xiaxf, xiay+xiayf);
					xss = 0;
				}
				if(dq == 77 && (xialuo.xy[0][0]*2+xiaxf)/2-1<9 && (xialuo.xy[1][0]*2+xiaxf)/2-1<9 && (xialuo.xy[2][0]*2+xiaxf)/2-1<9 && (xialuo.xy[3][0]*2+xiaxf)/2-1<9 && fkpzy(xy, xialuo, xiaxf, xiayf))
				{
					hfk(&xialuo, "  ", xiax+xiaxf, xiay+xiayf);
					xiaxf=xiaxf+2;
					xxyfs(xialuo.ys);
					hfk(&xialuo, she, xiax+xiaxf, xiay+xiayf);
					xss = 0;
				}
			}   
		}

	}  
	return fen;
}



void qch(int xy[10][25], int hang)
{
	int xhbl;
	int xhbl1;
	if(time(NULL)%2)
	{
		for(xhbl=0; xhbl<10; xhbl++)
		{
			Sleep(20);
			gotoxy(22+xhbl*2,hang);
			printf("  ");
		}
	}
	else
	{
		for(xhbl=9; xhbl>=0; xhbl--)
		{
			Sleep(20);
			gotoxy(22+xhbl*2,hang);
			printf("  ");
		}
	}
	for(xhbl=hang; xhbl>1; xhbl--)
	{
		for(xhbl1=0; xhbl1<10; xhbl1++)
		{
			xy[xhbl1][xhbl]=xy[xhbl1][xhbl-1];
		}
		gotoxy(22,xhbl-1);
		printf("                    ");
		for(xhbl1=0; xhbl1<10; xhbl1++)
		{
			if(xy[xhbl1][xhbl]>0)
			{
				xxyfs(xy[xhbl1][xhbl]);
				gotoxy(22+xhbl1*2,xhbl);
				printf("%s",she);
			}
		}
	}
	return;
}



int jsfs(int dfsz[4],int xy[10][25])
{
	int xhbl;
	int xhbl1;
	int xb=0;
	int lj=0;
	for(xhbl=22; xhbl>=0; xhbl--)
	{
		for(xhbl1=0; xhbl1<10; xhbl1++)
		{
			if(xy[xhbl1][xhbl]>0)
			{
				lj++;
			}
		}
		if(lj == 10)
		{
			dfsz[xb] = xhbl;
			qch(xy, xhbl);
			xb++;
			xhbl++;
		}
		lj=0;
	}
	return xb;
}



int jtjc(int xy[10][25])
{
	int xhbl;
	for(xhbl=0;xhbl<10;xhbl++)
	{
		if(xy[xhbl][1]>0)
		{
			return 1;
		}
	}
	return 0;
}



int jcbxpz(int xy[10][25], XY xialuo, int xz, int fx, int x, int y)
{
	int xhbl;
	fx++;
	if(fx == 4)
	{
		fx = 0;
	}
	if(xz == 4 || xz == 2 || xz == 3)
	{
		if(fx>1)
			fx=fx-2;
	}
	fkfx(&xialuo, xz, fx);
	for(xhbl=0; xhbl<4; xhbl++)
	{
		if(((xialuo.xy[xhbl][0]*2+x)/2-1)<0 || ((xialuo.xy[xhbl][0]*2+x)/2-1)>9 || xy[(xialuo.xy[xhbl][0]*2+x)/2-1][xialuo.xy[xhbl][1]+y]>0)
		{
			return 0;
		}
	}
	return 1;
}


int fkpzy(int xy[10][25], XY xialuo, int x, int y)
{
	int xhbl;
	for(xhbl=0; xhbl<4; xhbl++)
	{
		if(xy[(xialuo.xy[xhbl][0]*2+x)/2][xialuo.xy[xhbl][1]+y]>0)
		{
			return 0;
		}
	}
	return 1;
}



int fkpzz(int xy[10][25], XY xialuo, int x, int y)
{
	int xhbl;
	for(xhbl=0; xhbl<4; xhbl++)
	{
		if(xy[(xialuo.xy[xhbl][0]*2+x)/2-2][xialuo.xy[xhbl][1]+y]>0)
		{
			return 0;
		}
	}
	return 1;
}



int fkpz(int xy[10][25], XY xialuo, int x, int y)
{
	int xhbl;
	for(xhbl=0; xhbl<4; xhbl++)
	{
		if(xy[(xialuo.xy[xhbl][0]*2+x)/2-1][xialuo.xy[xhbl][1]+y+1]>0)
		{
			return 1;
		}
	}
	return 0;
}




int jcdd(XY * xialuo, int x, int y)
{
	int xh;
	for(xh=0; xh<4; xh++)
	{
		if(((xialuo->xy)[xh][1]) + y == 22)
		{
			return 1;
		}
	}
	return 0;
}


void hfk(XY * kuai,char * sh, int xxx, int yyy)
{
	int lll=0;
	for(lll=0;lll<4;lll++)
	{
		if((yyy+(kuai->xy)[lll][1]) > 0)
		{
			gotoxy(xxx+((kuai->xy)[lll][0]*2),yyy+((kuai->xy)[lll][1]));
			printf("%s",sh);
		}
	}
	return;
}



void fkfx(XY * kuai,int xz,int fx)//������״������ṹ�帳ֵ 
{
	switch(xz)
	{
	case 1: 
		(kuai->xy)[0][0]=1;
		(kuai->xy)[0][1]=1;
		(kuai->xy)[1][0]=2;
		(kuai->xy)[1][1]=1;
		(kuai->xy)[2][0]=1;
		(kuai->xy)[2][1]=2;
		(kuai->xy)[3][0]=2;
		(kuai->xy)[3][1]=2;
		break;
	case 2:
		if(fx == 0)
		{
			(kuai->xy)[0][0]=1;
			(kuai->xy)[0][1]=0;
			(kuai->xy)[1][0]=1;
			(kuai->xy)[1][1]=1;
			(kuai->xy)[2][0]=2;
			(kuai->xy)[2][1]=1;
			(kuai->xy)[3][0]=2;
			(kuai->xy)[3][1]=2;
		}
		if(fx == 1)
		{
			(kuai->xy)[0][0]=0;
			(kuai->xy)[0][1]=2;
			(kuai->xy)[1][0]=1;
			(kuai->xy)[1][1]=2;
			(kuai->xy)[2][0]=1;
			(kuai->xy)[2][1]=1;
			(kuai->xy)[3][0]=2;
			(kuai->xy)[3][1]=1;
		}
		break;
	case 3:
		if(fx == 0)
		{
			(kuai->xy)[0][0]=2;
			(kuai->xy)[0][1]=0;
			(kuai->xy)[1][0]=2;
			(kuai->xy)[1][1]=1;
			(kuai->xy)[2][0]=1;
			(kuai->xy)[2][1]=1;
			(kuai->xy)[3][0]=1;
			(kuai->xy)[3][1]=2;
		} 
		if(fx == 1)
		{
			(kuai->xy)[0][0]=0;
			(kuai->xy)[0][1]=1;
			(kuai->xy)[1][0]=1;
			(kuai->xy)[1][1]=1;
			(kuai->xy)[2][0]=1;
			(kuai->xy)[2][1]=2;
			(kuai->xy)[3][0]=2;
			(kuai->xy)[3][1]=2;
		}
		break;
	case 4:
		if(fx == 0)
		{
			(kuai->xy)[0][0]=1;
			(kuai->xy)[0][1]=0;
			(kuai->xy)[1][0]=1;
			(kuai->xy)[1][1]=1;
			(kuai->xy)[2][0]=1;
			(kuai->xy)[2][1]=2;
			(kuai->xy)[3][0]=1;
			(kuai->xy)[3][1]=3;
		}
		if(fx == 1)
		{
			(kuai->xy)[0][0]=0;
			(kuai->xy)[0][1]=3;
			(kuai->xy)[1][0]=1;
			(kuai->xy)[1][1]=3;
			(kuai->xy)[2][0]=2;
			(kuai->xy)[2][1]=3;
			(kuai->xy)[3][0]=3;
			(kuai->xy)[3][1]=3;
		} 
		break;
	case 5:
		if(fx == 0)
		{
			(kuai->xy)[0][0]=1;
			(kuai->xy)[0][1]=1;
			(kuai->xy)[1][0]=0;
			(kuai->xy)[1][1]=2;
			(kuai->xy)[2][0]=1;
			(kuai->xy)[2][1]=2;
			(kuai->xy)[3][0]=2;
			(kuai->xy)[3][1]=2;
		}
		if(fx == 1)
		{
			(kuai->xy)[0][0]=1;
			(kuai->xy)[0][1]=0;
			(kuai->xy)[1][0]=1;
			(kuai->xy)[1][1]=1;
			(kuai->xy)[2][0]=1;
			(kuai->xy)[2][1]=2;
			(kuai->xy)[3][0]=2;
			(kuai->xy)[3][1]=1;
		}
		if(fx == 2)
		{
			(kuai->xy)[0][0]=0;
			(kuai->xy)[0][1]=1;
			(kuai->xy)[1][0]=1;
			(kuai->xy)[1][1]=1;
			(kuai->xy)[2][0]=2;
			(kuai->xy)[2][1]=1;
			(kuai->xy)[3][0]=1;
			(kuai->xy)[3][1]=2;
		}
		if(fx == 3)
		{
			(kuai->xy)[0][0]=1;
			(kuai->xy)[0][1]=1;
			(kuai->xy)[1][0]=2;
			(kuai->xy)[1][1]=0;
			(kuai->xy)[2][0]=2;
			(kuai->xy)[2][1]=1;
			(kuai->xy)[3][0]=2;
			(kuai->xy)[3][1]=2;
		}
		break;
	case 6:
		if(fx == 0)
		{
			(kuai->xy)[0][0]=1;
			(kuai->xy)[0][1]=0;
			(kuai->xy)[1][0]=1;
			(kuai->xy)[1][1]=1;
			(kuai->xy)[2][0]=1;
			(kuai->xy)[2][1]=2;
			(kuai->xy)[3][0]=2;
			(kuai->xy)[3][1]=2;
		} 
		if(fx == 1)
		{
			(kuai->xy)[0][0]=0;
			(kuai->xy)[0][1]=1;
			(kuai->xy)[1][0]=1;
			(kuai->xy)[1][1]=1;
			(kuai->xy)[2][0]=2;
			(kuai->xy)[2][1]=1;
			(kuai->xy)[3][0]=0;
			(kuai->xy)[3][1]=2;
		}
		if(fx == 2)
		{
			(kuai->xy)[0][0]=1;
			(kuai->xy)[0][1]=0;
			(kuai->xy)[1][0]=2;
			(kuai->xy)[1][1]=0;
			(kuai->xy)[2][0]=2;
			(kuai->xy)[2][1]=1;
			(kuai->xy)[3][0]=2;
			(kuai->xy)[3][1]=2;
		}
		if(fx == 3)
		{
			(kuai->xy)[0][0]=0;
			(kuai->xy)[0][1]=2;
			(kuai->xy)[1][0]=1;
			(kuai->xy)[1][1]=2;
			(kuai->xy)[2][0]=2;
			(kuai->xy)[2][1]=2;
			(kuai->xy)[3][0]=2;
			(kuai->xy)[3][1]=1;
		}
		break;
	case 7:
		if(fx == 0)
		{
			(kuai->xy)[0][0]=2;
			(kuai->xy)[0][1]=0;
			(kuai->xy)[1][0]=2;
			(kuai->xy)[1][1]=1;
			(kuai->xy)[2][0]=2;
			(kuai->xy)[2][1]=2;
			(kuai->xy)[3][0]=1;
			(kuai->xy)[3][1]=2;
		}
		if(fx == 1)
		{
			(kuai->xy)[0][0]=0;
			(kuai->xy)[0][1]=1;
			(kuai->xy)[1][0]=0;
			(kuai->xy)[1][1]=2;
			(kuai->xy)[2][0]=1;
			(kuai->xy)[2][1]=2;
			(kuai->xy)[3][0]=2;
			(kuai->xy)[3][1]=2;
		}
		if(fx == 2)
		{
			(kuai->xy)[0][0]=1;
			(kuai->xy)[0][1]=0;
			(kuai->xy)[1][0]=2;
			(kuai->xy)[1][1]=0;
			(kuai->xy)[2][0]=1;
			(kuai->xy)[2][1]=1;
			(kuai->xy)[3][0]=1;
			(kuai->xy)[3][1]=2;
		}
		if(fx == 3)
		{
			(kuai->xy)[0][0]=0;
			(kuai->xy)[0][1]=1;
			(kuai->xy)[1][0]=1;
			(kuai->xy)[1][1]=1;
			(kuai->xy)[2][0]=2;
			(kuai->xy)[2][1]=1;
			(kuai->xy)[3][0]=2;
			(kuai->xy)[3][1]=2;
		}
		break;
	default:printf("�������\n");
		getchar();
		exit(1); 
	}
	return;
} 



void xxyfs(int ys)
{
	if(ys == 1)
	{
		SetConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	}
	if(ys == 2)
	{
		SetConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	}
	if(ys == 3)
	{
		SetConsoleColor( FOREGROUND_GREEN  | FOREGROUND_INTENSITY);
	}
	if(ys == 4)
	{
		SetConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	}
	if(ys == 5)
	{
		SetConsoleColor( FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	}
	if(ys == 6)
	{
		SetConsoleColor(FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	}
	if(ys == 7)
	{
		SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	}
	return;
}



void scfk(int * xz, int * fx)//���ɷ��飬��һ������״���ڶ����Ƿ��� 
{
	srand(time(NULL));
	sjs=sjs%10*4;
	*fx = (rand())%4;//���ɷ���
	*xz = (rand())%7+1;
	if(*xz == 4 || *xz == 2 || *xz == 3)
	{
		if(*fx >1)
		{
			*fx = (*fx)-2;
		}    
	} 
	return;
} 



void dqwj(char * fi)//��ȡ�����ļ�
{
	FILE * fp;
	fp = NULL;
	int xh;
	fp = fopen(fi, "rb");
	if(fp == NULL)
	{
		gotoxy(54,3);
		printf("�ļ���ʧ��");
		return;
	}
	else
	{
		fscanf(fp,"%d,%d,%d,%d",&wjfs[0],&wjfs[1],&wjfs[2],&wjfs[3]);
		fclose(fp);
	}
}


void bcwj(char * fi)//��������ļ�
{
	FILE * fp;
	fp = NULL;
	int xh;
	fp = fopen(fi, "wb+");
	if(fp == NULL)
	{
		gotoxy(54,3);
		printf("�ļ�����ʧ��");
		return;
	}
	else
	{
		fprintf(fp,"%d,%d,%d,%d",wjfs[0],wjfs[1],wjfs[2],wjfs[3]);
		fclose(fp);
	}

}





void startjm()
{
	int lin1=0; 
	qingping();//���� 
	xxyfs(7);
	gotoxy(0,lin1);
	lin1++;
	printf("���������������������ש��������������������ש��������������������ש�������������");gotoxy(0,lin1);lin1++;
	printf("��                  ��                    ��                    ��            ��");gotoxy(0,lin1);lin1++;
	printf("��                  ��                    ��                    ��    ����    ��");gotoxy(0,lin1);lin1++;
	printf("��                  ��                    ��                    ��            ��");gotoxy(0,lin1);lin1++;
	printf("��                  ��                    ��                    ��            ��");gotoxy(0,lin1);lin1++;
	printf("��                  ��                    ��                    ��            ��");gotoxy(0,lin1);lin1++;
	printf("��                  ��                    ��                    �ǩ�������������");gotoxy(0,lin1);lin1++;
	printf("��                  ��                    ��       ��һ��       ��   ��߷�   ��");gotoxy(0,lin1);lin1++;
	printf("��                  ��                    ��                    ��            ��");gotoxy(0,lin1);lin1++;
	printf("��                  ��                    ��                    �ǩ�������������");gotoxy(0,lin1);lin1++;
	printf("��                  ��                    ��                    ��            ��");gotoxy(0,lin1);lin1++;
	printf("��                  ��                    ��                    ��            ��");gotoxy(0,lin1);lin1++;
	printf("��                  ��                    ��                    �ǩ�������������");gotoxy(0,lin1);lin1++;
	printf("��                  ��                    ��                    �� ���Σ� ��  ��");gotoxy(0,lin1);lin1++;
	printf("��                  ��                    ��                    ��            ��");gotoxy(0,lin1);lin1++;
	printf("��                  ��                    ��                    �� ���䣺 ��  ��");gotoxy(0,lin1);lin1++;
	printf("��                  ��                    ��                    ��            ��");gotoxy(0,lin1);lin1++;
	printf("��                  ��                    ��                    �� ���ƣ� ��  ��");gotoxy(0,lin1);lin1++;
	printf("��                  ��                    ��                    ��            ��");gotoxy(0,lin1);lin1++;
	printf("��                  ��                    ��                    �� ���ƣ� ��  ��");gotoxy(0,lin1);lin1++;
	printf("��                  ��                    ��                    ��            ��");gotoxy(0,lin1);lin1++;
	printf("��                  ��                    ��                    �� ��ͣ���ո� ��");gotoxy(0,lin1);lin1++;
	printf("��                  ��                    ��                    ��            ��");gotoxy(0,lin1);lin1++;
	printf("���������������������ߩ��������������������ߩ��������������������ߩ�������������"); 
} 


void qingping(void)//���� 
{
	int y;
	gotoxy(0,1);
	for(y=0; y<24; y++)
	{
		printf("                                                                                ");
	}
	return;
} 


BOOL SetConsoleColor(WORD wAttributes)  
{  
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  
	if (hConsole == INVALID_HANDLE_VALUE)  
		return FALSE;  

	return SetConsoleTextAttribute(hConsole, wAttributes);  
} 


int nandu()//��Ϸ�Ѷ�ѡ�� 
{
	int lin1 = 16;//Ŀ¼��һ�ַ������� 
	int jizhi = 7; //ѡ����Ӵ��п�ʼ 
	int pd = 0;//�ж�ѡ���ͷλ�� 
	int gb;//��¼���밴�� 
	gotoxy(lin1,jizhi);
	printf("��    ��");
	gotoxy(lin1,jizhi+2);
	printf("��    ��");
	gotoxy(lin1,jizhi+4);
	printf("��    ��");
	gotoxy(lin1,jizhi+6);
	printf("��    ��");
	gotoxy(lin1,jizhi+8);
	printf("��    ��");
	while(1)
	{
		Sleep(200);
		gotoxy(lin1-3,jizhi+pd*2);//����ѡ���ͷ 
		printf("��");
		gotoxy(lin1+9,jizhi+pd*2);
		printf("��");
		if(kbhit())//�ж��Ƿ��м������� 
		{
			gotoxy(lin1-3,jizhi+pd*2);//ɾ��ѡ���ͷ 
			printf("  ");
			gotoxy(lin1+9,jizhi+pd*2);
			printf("  ");
			gb = getch();//��ȡ�����ַ� 
			if(gb == 13)//�س�ʱ���������� 
			{
				return pd;
			} 
			if(gb == 224)//224���ǿ����а��ϻ����¼�ͷ 
			{
				gb = getch();//��ȡ������Ϣ 
				if(gb == 72)//���ϵ�ʱ�� 
				{
					pd--;
				} 
				if(gb == 80)//���µ�ʱ�� 
				{
					pd++;
				}
			} 
			if(pd < 0)//��ֹ��ͷ�Ƴ�Ŀ¼ 
			{
				pd = 0;
			}
			if(pd > 4)
			{
				pd = 4;
			}
		}


	} 
} 



void chushibiankuang()//��ʼ�߿� 
{
	int lin1 = 40;
	int lin2 = 1;
	huibiankuang("��");         //���ƿ�ʼ�������ܱ߿� ������ 
	for(lin2=1; lin2<23; lin2++)
	{
		gotoxy(lin1, lin2);
		printf("��");
	}
	gotoxy(15,3);
	printf("����˹����"); 
}



int gotoxy(int x, int y) //��λ���λ��
{  
	HANDLE handle; //����������handle
	COORD coord; //����ṹ��coord (����ϵcoord)
	coord.X = x; //������x
	coord.Y = y; //������y
	handle = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ����̨������(ֵΪ-11)
	SetConsoleCursorPosition(handle, coord); //�ƶ����
	return 0;
} 



void huibiankuang(char * xz)                //���Ʊ߿� 
{
	int lin1 = 0;
	int lin2 = 0;
	for(lin2=0; lin2<40; lin2++)  //�ϲ� 
	{
		gotoxy(lin2*2,lin1);
		printf("%s",xz);
	}
	for(lin1=1; lin1<23; lin1++)//�в� 
	{
		gotoxy(0,lin1);
		printf("%s",xz);
		gotoxy(78,lin1);
		printf("%s",xz);
	}
	for(lin2=0; lin2<40; lin2++)//�²� 
	{
		gotoxy(lin2*2,lin1);
		printf("%s",xz);
	}
}


