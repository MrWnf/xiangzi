#include"function.h"





void init() {

	//该段代码功能是隐藏光标，调用了win32编程接口，不需要掌握
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//获取窗口句柄
	CONSOLE_CURSOR_INFO cci;//实列化一个控制台光标信息类
	GetConsoleCursorInfo(hOut, &cci);//获取光标信息
	cci.bVisible = FALSE;//隐藏光标
	SetConsoleCursorInfo(hOut, &cci);//设置光标信息

	system("title 推箱子1.0");//设定窗口名称
	system("mode con cols=120 lines=30");//设定窗口大小
}
//0:空的 1:▆ 3：☆ 4：★ 5：@7:⊙ 8：※



int  map[2][7][8] =
{
	
	{
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 0, 0, 0, 0, 0, 0, 1,
	1, 3, 1, 0, 1, 1, 3, 1,
	1, 4, 0, 0, 4, 0, 3, 1,
	1, 0, 1, 0, 1, 1, 4, 1,
	1, 0, 0, 5, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 1, 1, 1
	},
	{
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 3, 1, 0, 1, 1, 3, 1,
		1, 3, 4, 5, 4, 0, 3, 1,
		1, 4, 1, 0, 1, 1, 4, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1
	}
};



int cas = 0;	//为0表示第一关
//记录每一关的箱子数 或者是项目和目的在一起的总数
int boxSum[2] = { 3,4 };
//地图绘图


void drawMap()
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (j == 0)
				printf("\t\t");
			switch (map[cas][i][j])
			{
				//	//0:空的 1:▆ :墙
			case 0:
				printf("  ");
				break;
			case 1:
				printf("▆");
				break;
				//3：☆ 4：★  //目的地和箱子
			case 3:
				printf("☆");
				break;
			case 4:
				printf("★");
				break;
				//5：@	  //人
			case 5:
			case 8:
				printf("※");
				break;
			case 7:
				printf("⊙");
				break;
				
			}
		}
		printf("\n");
	}
}




//按键处理
void keyDown()
{
	



	//人有两种情况：第一个是：人，第二个：人站在目的上
	int i, j;
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (map[cas][i][j] == 5 || map[cas][i][j] == 8)
			{
				break;
			}
		}
		if (map[cas][i][j] == 5 || map[cas][i][j] == 8)
		{
			break;
		}
	}

	char ch = _getch();	//看不见的字符输入，+头文件 conio.h
	switch (ch)
	{
		//72 80   75 77
	case 'w':
	case 'W':
	case 72:
		//下一个地方等于空地或者是目的 能走
		if (map[cas][i - 1][j] == 0 || map[cas][i - 1][j] == 3)
		{
			//3+5=8 ：表示目的和人在一起
			//新地方(map[i-1][j])人（5）来了
			map[cas][i - 1][j] += 5;
			//老地方(map[i][j])人（5）走了
			map[cas][i][j] -= 5;
		}
		
		else if (map[cas][i - 1][j] == 4 || map[cas][i - 1][j] == 7)
		{
			//做箱子的下一个地方判断能不能走
			if (map[cas][i - 2][j] == 0 || map[cas][i - 2][j] == 3)
			{
				//新的地方箱子来了
				map[cas][i - 2][j] += 4;
				//箱子的位置：箱子（-4）走了 人来（+5）
				map[cas][i - 1][j] += 1;
				//原来的地方人走了
				map[cas][i][j] -= 5;
			}

		}



		break;
	case 's':
	case 'S':
	case 80:
		//下一个地方等于空地或者是目的 能走
		if (map[cas][i + 1][j] == 0 || map[cas][i + 1][j] == 3)
		{
			
			map[cas][i + 1][j] += 5;
			
			map[cas][i][j] -= 5;
		}
		else if (map[cas][i + 1][j] == 4 || map[cas][i + 1][j] == 7)
		{
			//做箱子的下一个地方判断能不能走
			if (map[cas][i + 2][j] == 0 || map[cas][i + 2][j] == 3)
			{
				//新的地方箱子来了
				map[cas][i + 2][j] += 4;
				//箱子的位置：箱子（-4）走了 人来（+5）
				map[cas][i + 1][j] += 1;
				//原来的地方人走了
				map[cas][i][j] -= 5;
			}

		}
		break;



	case 'a':
	case 'A':
	case 75:
		//下一个地方等于空地或者是目的 能走
		if (map[cas][i][j - 1] == 0 || map[cas][i][j - 1] == 3)
		{
			//3+5=8 ：表示目的和人在一起
			//新地方(map[i-1][j])人（5）来了
			map[cas][i][j - 1] = map[cas][i][j - 1] + 5;
			//老地方(map[i][j])人（5）走了
			map[cas][i][j] = map[cas][i][j] - 5;
			//j+=5  j=j+5

		}
		else if (map[cas][i][j - 1] == 4 || map[cas][i][j - 1] == 7)
		{
			//做箱子的下一个地方判断能不能走
			if (map[cas][i][j - 2] == 0 || map[cas][i][j - 2] == 3)
			{
				//新的地方箱子来了
				map[cas][i][j - 2] += 4;
				//箱子的位置：箱子（-4）走了 人来（+5）
				map[cas][i][j - 1] += 1;
				//原来的地方人走了
				map[cas][i][j] -= 5;
			}

		}

		break;



	case 'D':
	case 'd':
	case 77:
		//下一个地方等于空地或者是目的 能走
		if (map[cas][i][j + 1] == 0 || map[cas][i][j + 1] == 3)
		{
			
			map[cas][i][j + 1] += 5;
		
			map[cas][i][j] -= 5;
		}

		//下一个地方是箱子，判断箱子的下一个地方是不是目的和空地
		else if (map[cas][i][j + 1] == 4 || map[cas][i][j + 1] == 7)
		{
			//做箱子的下一个地方判断能不能走
			if (map[cas][i][j + 2] == 0 || map[cas][i][j + 2] == 3)
			{
				//新的地方箱子来了
				map[cas][i][j + 2] += 4;
				//箱子的位置：箱子（-4）走了 人来（+5）
				map[cas][i][j + 1] += 1;
				//原来的地方人走了
				map[cas][i][j] -= 5;
			}

		}
		break;
	}
}





//胜负判断
//用什么判断胜负： 箱子到达目的的个数
int gameOver()
{
	int count = 0;
	//所有的地方找一遍
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (map[cas][i][j] == 7)
				count++;
		}
	}
	return count;
}



//箱子数是零的时候也是胜利
int gameOver2()
{
	int count = 3;
	//所有的地方找一遍
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (map[cas][i][j] == 3)
				count--;
		}
	}
	return count;
}




int main()
{
	while (1)
	{
		printf("\n\n\t\t   第%d关\n", cas + 1);
		drawMap();
		if (gameOver() == boxSum[cas])
		{
			cas++;
			if (cas == 2)
				break;
		}
		keyDown();
		system("cls");
	}
	printf("胜利");
	system("pause");
	return 0;
}



		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		/*
		
		
		
		
		//找初始位置
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				if (map[i][j] == 6 || map[i][j] == 9)
					break;
			}
			if (map[i][j] == 6 || map[i][j] == 9)
				break;
		}
		printf("您的当前坐标（%d，%d）", i, j);
		input = _getch();
		switch (input)
		{
		case 'w':
			//0代表空地  6代表人  //3代表目的地
			if (map[i - 1][j] == 0)
			{
				map[i - 1][j] = 6 + 0;
				if (map[i][j] == 9)
					map[i][j] = 3;
				else
					map[i][j] = 0;
			}

			else if ((map[i - 1][j] == 3) || (map[i - 1][j] == 9))
			{
				map[i - 1][j] = 6 + 3;
				if (map[i][j] == 9)
					map[i][j] = 3;
				else
					map[i][j] = 0;
			}
			//如果人前面是箱子。//4代表箱子   //7箱子进入目的地
			else if (map[i - 1][j] == 4)
			{

				if (map[i - 2][j] == 0)
				{
					map[i - 2][j] = 4; //人推箱子往前走一步，把空地ID修改为箱子ID（）
					//下面是对箱子原地进行判断
					if (map[i - 1][j] == 7)
						map[i - 1][j] = 9;
					else
						map[i - 1][j] = 6;
					//下面是对人原地进行判断
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
				//如果人的前面是箱子，而箱子前面是目的地。
				else if (map[i - 2][j] == 3)
				{
					map[i - 2][j] = 7;
					count++;
					//下面是对箱子原先位置的判断
					if (map[i - 1][j] == 7)
						map[i - 1][j] = 9;
					else
						map[i - 1][j] = 6;
					//下面是对人原先位置进行判断
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
			}
			//如果人前面是已经进入某目的地的箱子（
			else if (map[i - 1][j] == 7)
			{
				//如果人前面是已经进入某目的地的箱子,而箱子前面是空地。
				if (map[i - 2][j] == 0)
				{
					count--;
					map[i - 2][j] = 4;
					map[i - 1][j] = 9;
					//下面是对人原先地进行判断
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
				//如果人前面是已经进入某目的地的箱子，而箱子前面是另一目的地。
				if (map[i - 2][j] == 3)
				{
					map[i - 2][j] = 7;
					map[i - 1][j] = 9;
					//下面是对人原先站立地进行判断
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
			}
			break;
		case 's':
			//如果人前面是空地。
			if (map[i + 1][j] == 0)
			{
				map[i + 1][j] = 6 + 0;
				if (map[i][j] == 9)
					map[i][j] = 3;
				else
					map[i][j] = 0;
			}
			//如果人前面是目的地。
			else if (map[i + 1][j] == 3)
			{
				map[i + 1][j] = 6 + 3;
				if (map[i][j] == 9)
					map[i][j] = 3;
				else
					map[i][j] = 0;
			}
			//如果人前面是箱子。
			else if (map[i + 1][j] == 4)
			{
				//如果人前面是箱子，而箱子前面是空地。
				if (map[i + 2][j] == 0)
				{
					map[i + 2][j] = 4;
					//下面是对箱子原地进行判断
					if (map[i + 1][j] == 7)
						map[i + 1][j] = 9;
					else
						map[i + 1][j] = 6;
					//下面是对人原地进行判断
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
				//如果人的前面是箱子，而箱子前面是目的地。
				else if (map[i + 2][j] == 3)
				{
					map[i - 2][j] = 7;
					count++;
					//下面是对箱子原先位置的判断
					if (map[i + 1][j] == 7)
						map[i + 1][j] = 9;
					else
						map[i + 1][j] = 6;
					//下面是对人原先位置进行判断
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
			}
			//如果人前面是已经进入某目的地的箱子
			else if (map[i + 1][j] == 7)
			{
				//如果人前面是已经进入某目的地的箱子,而箱子前面是空地。
				if (map[i + 2][j] == 0)
				{
					count--;
					map[i + 2][j] = 4;
					map[i + 1][j] = 9;
					//下面是对人原先地进行判断
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
				//如果人前面是已经进入某目的地的箱子，而箱子前面是另一目的地。
				if (map[i + 2][j] == 3)
				{
					map[i + 2][j] = 7;
					map[i + 1][j] = 9;
					//下面是对人原先站立地进行判断
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
			}
			break;
		case 'a':
			//如果人前面是空地。
			if (map[i][j - 1] == 0)
			{
				map[i][j - 1] = 6 + 0;
				if (map[i][j] == 9)
					map[i][j] = 3;
				else
					map[i][j] = 0;
			}
			//如果人前面是目的地。
			else if (map[i][j - 1] == 3)
			{
				map[i][j - 1] = 6 + 3;
				if (map[i][j] == 9)
					map[i][j] = 3;
				else
					map[i][j] = 0;
			}
			//如果人前面是箱子。
			else if (map[i][j - 1] == 4)
			{
				//如果人前面是箱子，而箱子前面是空地。
				if (map[i][j - 2] == 0)
				{
					map[i][j - 2] = 4;
					//下面是对箱子原地进行判断
					if (map[i][j - 1] == 7)
						map[i][j - 1] = 9;
					else
						map[i][j - 1] = 6;
					//下面是对人原地进行判断
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
				//如果人的前面是箱子，而箱子前面是目的地。
				else if (map[i][j - 2] == 3)
				{
					count++;
					map[i][j - 2] = 7;
					if (map[i][j - 1] == 7)
						map[i][j - 1] = 9;
					else
						map[i][j - 1] = 6;
					//下面是对人原先位置进行判断
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
			}
			//如果人前面是已经进入某目的地的箱子（ID=7）。
			else if (map[i][j - 1] == 7)
			{
				//如果人前面是已经进入某目的地的箱子,而箱子前面是空地。
				if (map[i][j - 2] == 0)
				{
					count--;
					map[i][j - 2] = 4;
					map[i][j - 1] = 9;
					//下面是对人原先地进行判断
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
				//如果人前面是已经进入某目的地的箱子，而箱子前面是另一目的地。
				if (map[i][j - 2] == 3)
				{
					map[i][j - 2] = 7;
					map[i][j - 1] = 9;

					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
			}
			break;
		case 'd':
			//如果人前面是空地。
			if (map[i][j + 1] == 0)
			{
				map[i][j + 1] = 6 + 0;
				if (map[i][j] == 9)
					map[i][j] = 3;
				else
					map[i][j] = 0;
			}
			//如果人前面是目的地。
			else if (map[i][j + 1] == 3)
			{
				map[i][j + 1] = 6 + 3;
				if (map[i][j] == 9)
					map[i][j] = 3;
				else
					map[i][j] = 0;
			}
			//如果人前面是箱子。
			else if (map[i][j + 1] == 4)
			{
				//如果人前面是箱子，而箱子前面是空地。
				if (map[i][j + 2] == 0)
				{
					map[i][j + 2] = 4;
					//下面是对箱子原地进行判断
					if (map[i][j + 1] == 7)
						map[i][j + 1] = 9;
					else
						map[i][j + 1] = 6;
					//下面是对人原地进行判断
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
				//如果人的前面是箱子，而箱子前面是目的地。
				else if (map[i][j + 2] == 3)
				{
					count++;
					map[i][j + 2] = 7;
					//下面是对箱子原先位置的判断
					if (map[i][j + 1] == 7)
						map[i][j + 1] = 9;
					else
						map[i][j + 1] = 6;
					//下面是对人原先位置进行判断
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
			}

			else if (map[i][j + 1] == 7)
			{
				//如果人前面是已经进入某目的地的箱子,而箱子前面是空地。
				if (map[i][j + 2] == 0)
				{
					count--;
					map[i][j + 2] = 4;
					map[i][j + 1] = 9;
					//下面是对人原先地进行判断
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
				//如果人前面是已经进入某目的地的箱子
				if (map[i][j + 2] == 3)
				{
					map[i][j + 2] = 7;
					map[i][j + 1] = 9;
					//下面是对人原先站立地进行判断
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
			}
			break;
		}
		if (count == 8)   //如果分数达到分
		{
			system("CLS"); //清屏
			draw_map(map);
			break;    //退出死循环
		}
	}
	printf("\n恭喜你，过关了！！\n"); //过关提示
	return 0;
}
void draw_map(int map[10][12])
{

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 12; j++)
		{
			switch (map[i][j])
			{
			case 0:
				printf(" "); //数字代表道路
				break;
			case 1:
				printf("#"); //数字代表墙壁
				break;
			case 2:
				printf(" "); //数字是游戏边框的空白部分
				break;
			case 3:
				printf("!"); //数字代表目的地
				break;
			case 4:
				printf("*"); //数字代表箱子
				break;
			case 7:
				printf("$"); //数字代表箱子进入目的地
				break;
			case 6:
				printf("@"); //数字代表人
				break;
			case 9:
				printf("@"); //数字代表人进入目的地

			}
		}
		printf("\n");    //分行输出
	}
}
*/