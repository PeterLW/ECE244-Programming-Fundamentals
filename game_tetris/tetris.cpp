// 俄罗斯方块1.cpp : 定义控制台应用程序的入口点。
//

#include "stdio.h"
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <malloc.h>
#include <io.h>
#include <time.h> 


typedef struct sisi           //运行下落结构体 
{
	char xy[4][2];
	int ys;
}XY;



char * she = "■"; //用此符号画方块 
int sjs = 973;//因为我看郝斌的视频里没有随机数，随机数只是稍稍百度了一下就拿来用了，不会用时间来生成，所以就创建了这么个变量 
int wjfs[4];
int yyys;


void huibiankuang(char *);  //绘制开始边框 ，char 接收绘制用图形 
int gotoxy(int, int);//设定光标坐标，===================================这个函数不是我自己写的，是用吧里 Simon 写 贪食蛇的写的函数，我没有学到windows编程，写不出这种函数 
void chushibiankuang(); //初始边框 
int nandu();//游戏难度选择 
int start(int);//开始游戏，形参为游戏难度 
void qingping(void);//清屏 
void startjm(void);//绘制开始游戏边框 
void bcwj(char *);//保存文件
void dqwj(char *);//读取文件
void fkfx(XY *,int,int);//根据方块方向进行赋值 ,后面是方块形状和方向
void scfk(int *, int *);//生成方块，指针式返回方块形状和方向； 
BOOL SetConsoleColor(WORD wAttributes);
void hfk(XY *,char *,int,int);//画方块
void xxyfs(int);
int jcdd(XY *, int, int);
int fkpz(int xy[10][25], XY, int, int);
int jcbxpz(int xy[10][25], XY, int, int, int, int);
int jtjc(int xy[10][25]);
int jsfs(int dfsz[4],int xy[10][25]);//得分数组
int fkpzz(int xy[10][25], XY, int, int);
int fkpzy(int xy[10][25], XY, int, int);
void qch(int xy[10][25], int);





int main(void)
{ 
	int nan = 5;//游戏难度储存，0=初级，1=中级，2=高级，3=进化 ,4=退出 
	int fen = 0;
	int xh = 0;
	while(1)
	{
		qingping();//清屏 
		xxyfs(7);
		chushibiankuang();//初始化边框 
		if(access("elsfk.bin",0)==0)//检测储存分数文件是否存在
		{
			dqwj("elsfk.bin");//读取文件
			gotoxy(56,3);
			printf("记录榜");
			gotoxy(46,7);
			printf("初级最高分：%d",wjfs[0]);
			gotoxy(46,9);
			printf("中级最高分：%d",wjfs[1]);
			gotoxy(46,11);
			printf("高级最高分：%d",wjfs[2]);
			gotoxy(46,13);
			printf("进化最高分：%d",wjfs[3]);
		}
		else//文件不存在
		{
			for(xh=0; xh<4; xh++)
				wjfs[xh] = 0;
			gotoxy(54,3);
			printf("没有分数文件");
		}
		nan = nandu();//难度选择 
		if(nan == 4)
		{
			break;
		}
		fen = start(nan);//开始游戏，返回值为游戏结束时分数 ,nan是游戏难度
		gotoxy(30,8);
		printf("▇▇▇▇▇▇");
		gotoxy(30,9);
		printf("▇游戏结束▇");
		gotoxy(30,10);
		printf("▇▇▇▇▇▇");
		if(fen > wjfs[nan])//如果当前模式的分数大于文件所保存的分数，就把最新分数保存起来
		{
			wjfs[nan] = fen;
			bcwj("elsfk.bin");
		}
		getch();
	}  
	return 0;
} 





int start(int nan)//开始游戏 ，nan是游戏难度，0,1,2,3 
{
	int dfhs;//得分行数
	int dfsz[4];//得分数组
	int sspd=1;//生死判定
	int zzz;//临时使用，用完删除
	int zzz1;
	int xss=1;//检测是否快速左右移动而跳过延迟
	int xhbl1;//循环变量1
	int xhbl=0;//循环变量，多长时间下落一格
	int bd=0;//判定方块是否有变化
	int ys;//
	int xlxz;//下落形状
	int xiax=20;//下落基准变量x
	int xiay=0;//下落基准变量y
	int xiaxf;//左右变量
	int xiayf;//下落变量
	int xxing=0;//下行变量 
	int xz;//形状
	int fx;//当前方向
	int xxz;//下一个方块形状 
	int xfx;//下一个方块方向 
	int xy[10][25]={0};//定义界面数组
	struct sisi xialuo;  //下落变量 
	struct sisi xiayige; //下一个储存变量 
	char jcbl=0;//检测变量 
	char jsxz;//接收形状 
	char xzfx;  //接收形状方向 
	int shijian;//分数加成 
	int lsfs=0;//临时分数 
	int dq;//读取键盘输入  
	int fen=0;//游戏分数 
	startjm();//绘制开始游戏边框 
	if(nan == 0)        //根据难度调整方块的速度
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
		printf("初  级");
	if(nan == 1)
		printf("中  级");
	if(nan == 2)
		printf("高  级");
	if(nan == 3)
	{
		printf("进  化");
		gotoxy(70,11);
		xxyfs(3);
		printf("%d%%",(int)(((float)shijian)/35.0*100));
	}
	gotoxy(69,8);
	xxyfs(3);
	printf("%d",wjfs[nan]);//显示最高分

	//初始化 
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
	printf("%d",fen);//显示当前分数
	while(sspd)//正式运行 
	{
		xhbl++;
		sjs++;

		if(jcbl == 0)//没有下落的方块时，生成方块 
		{
			fx = xfx;
			xialuo = xiayige;
			xz = xxz;
			fx = xfx;
			hfk(&xiayige, "  ", 50, 9); 
			scfk(&xxz, &xfx);//调用生成下一个方块函数 
			fkfx(&xiayige, xxz, xfx);  //赋坐标值
			xiayige.ys = (rand())%6+2;//生成下一个方块颜色
			xxyfs(xiayige.ys);
			hfk(&xiayige, she, 50, 9);//画下一个方块 
			jcbl = 1; //改为有方块下落
			xiayf=-3;//下落上下变量赋值
			xiaxf=8;//下落左右变量赋值
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
				dfhs = jsfs(dfsz,xy);//计算分数
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
					printf("%d",fen);//显示当前分数

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
		if(kbhit())//检测键盘输入 
		{
			dq = getch();
			if(dq == 32)//当按下空格时，暂停 
			{
				gotoxy(68,22); // 
				printf("游戏暂停");
				getch(); 
				gotoxy(68,22); // 
				printf("        ");         
			}  
			if(dq == 224)//可能输入控制按键的时候 
			{
				dq = getch();
				if((dq == 72))//检测是否向上 
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



void fkfx(XY * kuai,int xz,int fx)//根据形状方向给结构体赋值 
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
	default:printf("程序错误！\n");
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



void scfk(int * xz, int * fx)//生成方块，第一个是形状，第二个是方向 
{
	srand(time(NULL));
	sjs=sjs%10*4;
	*fx = (rand())%4;//生成方向
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



void dqwj(char * fi)//读取分数文件
{
	FILE * fp;
	fp = NULL;
	int xh;
	fp = fopen(fi, "rb");
	if(fp == NULL)
	{
		gotoxy(54,3);
		printf("文件打开失败");
		return;
	}
	else
	{
		fscanf(fp,"%d,%d,%d,%d",&wjfs[0],&wjfs[1],&wjfs[2],&wjfs[3]);
		fclose(fp);
	}
}


void bcwj(char * fi)//保存分数文件
{
	FILE * fp;
	fp = NULL;
	int xh;
	fp = fopen(fi, "wb+");
	if(fp == NULL)
	{
		gotoxy(54,3);
		printf("文件保存失败");
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
	qingping();//清屏 
	xxyfs(7);
	gotoxy(0,lin1);
	lin1++;
	printf("┏━━━━━━━━━┳━━━━━━━━━━┳━━━━━━━━━━┳━━━━━━┓");gotoxy(0,lin1);lin1++;
	printf("┃                  ┃                    ┃                    ┃            ┃");gotoxy(0,lin1);lin1++;
	printf("┃                  ┃                    ┃                    ┃    分数    ┃");gotoxy(0,lin1);lin1++;
	printf("┃                  ┃                    ┃                    ┃            ┃");gotoxy(0,lin1);lin1++;
	printf("┃                  ┃                    ┃                    ┃            ┃");gotoxy(0,lin1);lin1++;
	printf("┃                  ┃                    ┃                    ┃            ┃");gotoxy(0,lin1);lin1++;
	printf("┃                  ┃                    ┃                    ┣━━━━━━┫");gotoxy(0,lin1);lin1++;
	printf("┃                  ┃                    ┃       下一个       ┃   最高分   ┃");gotoxy(0,lin1);lin1++;
	printf("┃                  ┃                    ┃                    ┃            ┃");gotoxy(0,lin1);lin1++;
	printf("┃                  ┃                    ┃                    ┣━━━━━━┫");gotoxy(0,lin1);lin1++;
	printf("┃                  ┃                    ┃                    ┃            ┃");gotoxy(0,lin1);lin1++;
	printf("┃                  ┃                    ┃                    ┃            ┃");gotoxy(0,lin1);lin1++;
	printf("┃                  ┃                    ┃                    ┣━━━━━━┫");gotoxy(0,lin1);lin1++;
	printf("┃                  ┃                    ┃                    ┃ 变形： ↑  ┃");gotoxy(0,lin1);lin1++;
	printf("┃                  ┃                    ┃                    ┃            ┃");gotoxy(0,lin1);lin1++;
	printf("┃                  ┃                    ┃                    ┃ 下落： ↓  ┃");gotoxy(0,lin1);lin1++;
	printf("┃                  ┃                    ┃                    ┃            ┃");gotoxy(0,lin1);lin1++;
	printf("┃                  ┃                    ┃                    ┃ 左移： ←  ┃");gotoxy(0,lin1);lin1++;
	printf("┃                  ┃                    ┃                    ┃            ┃");gotoxy(0,lin1);lin1++;
	printf("┃                  ┃                    ┃                    ┃ 右移： →  ┃");gotoxy(0,lin1);lin1++;
	printf("┃                  ┃                    ┃                    ┃            ┃");gotoxy(0,lin1);lin1++;
	printf("┃                  ┃                    ┃                    ┃ 暂停：空格 ┃");gotoxy(0,lin1);lin1++;
	printf("┃                  ┃                    ┃                    ┃            ┃");gotoxy(0,lin1);lin1++;
	printf("┗━━━━━━━━━┻━━━━━━━━━━┻━━━━━━━━━━┻━━━━━━┛"); 
} 


void qingping(void)//清屏 
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


int nandu()//游戏难度选择 
{
	int lin1 = 16;//目录第一字符纵坐标 
	int jizhi = 7; //选择项从此行开始 
	int pd = 0;//判定选择箭头位置 
	int gb;//记录输入按键 
	gotoxy(lin1,jizhi);
	printf("初    级");
	gotoxy(lin1,jizhi+2);
	printf("中    级");
	gotoxy(lin1,jizhi+4);
	printf("高    级");
	gotoxy(lin1,jizhi+6);
	printf("进    化");
	gotoxy(lin1,jizhi+8);
	printf("退    出");
	while(1)
	{
		Sleep(200);
		gotoxy(lin1-3,jizhi+pd*2);//绘制选择箭头 
		printf("→");
		gotoxy(lin1+9,jizhi+pd*2);
		printf("←");
		if(kbhit())//判定是否有键盘输入 
		{
			gotoxy(lin1-3,jizhi+pd*2);//删除选择箭头 
			printf("  ");
			gotoxy(lin1+9,jizhi+pd*2);
			printf("  ");
			gb = getch();//读取输入字符 
			if(gb == 13)//回车时返回主函数 
			{
				return pd;
			} 
			if(gb == 224)//224就是可能有按上或者下箭头 
			{
				gb = getch();//读取按键信息 
				if(gb == 72)//按上的时候 
				{
					pd--;
				} 
				if(gb == 80)//按下的时候 
				{
					pd++;
				}
			} 
			if(pd < 0)//防止箭头移出目录 
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



void chushibiankuang()//初始边框 
{
	int lin1 = 40;
	int lin2 = 1;
	huibiankuang("◇");         //绘制开始界面四周边框 用菱形 
	for(lin2=1; lin2<23; lin2++)
	{
		gotoxy(lin1, lin2);
		printf("◇");
	}
	gotoxy(15,3);
	printf("俄罗斯方块"); 
}



int gotoxy(int x, int y) //定位光标位置
{  
	HANDLE handle; //定义句柄变量handle
	COORD coord; //定义结构体coord (坐标系coord)
	coord.X = x; //横坐标x
	coord.Y = y; //纵坐标y
	handle = GetStdHandle(STD_OUTPUT_HANDLE); //获取控制台输出句柄(值为-11)
	SetConsoleCursorPosition(handle, coord); //移动光标
	return 0;
} 



void huibiankuang(char * xz)                //绘制边框 
{
	int lin1 = 0;
	int lin2 = 0;
	for(lin2=0; lin2<40; lin2++)  //上部 
	{
		gotoxy(lin2*2,lin1);
		printf("%s",xz);
	}
	for(lin1=1; lin1<23; lin1++)//中部 
	{
		gotoxy(0,lin1);
		printf("%s",xz);
		gotoxy(78,lin1);
		printf("%s",xz);
	}
	for(lin2=0; lin2<40; lin2++)//下部 
	{
		gotoxy(lin2*2,lin1);
		printf("%s",xz);
	}
}


