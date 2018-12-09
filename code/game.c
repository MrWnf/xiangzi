#include"function.h"





void init() {

	//�öδ��빦�������ع�꣬������win32��̽ӿڣ�����Ҫ����
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ���ھ��
	CONSOLE_CURSOR_INFO cci;//ʵ�л�һ������̨�����Ϣ��
	GetConsoleCursorInfo(hOut, &cci);//��ȡ�����Ϣ
	cci.bVisible = FALSE;//���ع��
	SetConsoleCursorInfo(hOut, &cci);//���ù����Ϣ

	system("title ������1.0");//�趨��������
	system("mode con cols=120 lines=30");//�趨���ڴ�С
}
//0:�յ� 1:�} 3���� 4���� 5��@7:�� 8����



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



int cas = 0;	//Ϊ0��ʾ��һ��
//��¼ÿһ�ص������� ��������Ŀ��Ŀ����һ�������
int boxSum[2] = { 3,4 };
//��ͼ��ͼ


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
				//	//0:�յ� 1:�} :ǽ
			case 0:
				printf("  ");
				break;
			case 1:
				printf("�}");
				break;
				//3���� 4����  //Ŀ�ĵغ�����
			case 3:
				printf("��");
				break;
			case 4:
				printf("��");
				break;
				//5��@	  //��
			case 5:
			case 8:
				printf("��");
				break;
			case 7:
				printf("��");
				break;
				
			}
		}
		printf("\n");
	}
}




//��������
void keyDown()
{
	



	//���������������һ���ǣ��ˣ��ڶ�������վ��Ŀ����
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

	char ch = _getch();	//���������ַ����룬+ͷ�ļ� conio.h
	switch (ch)
	{
		//72 80   75 77
	case 'w':
	case 'W':
	case 72:
		//��һ���ط����ڿյػ�����Ŀ�� ����
		if (map[cas][i - 1][j] == 0 || map[cas][i - 1][j] == 3)
		{
			//3+5=8 ����ʾĿ�ĺ�����һ��
			//�µط�(map[i-1][j])�ˣ�5������
			map[cas][i - 1][j] += 5;
			//�ϵط�(map[i][j])�ˣ�5������
			map[cas][i][j] -= 5;
		}
		
		else if (map[cas][i - 1][j] == 4 || map[cas][i - 1][j] == 7)
		{
			//�����ӵ���һ���ط��ж��ܲ�����
			if (map[cas][i - 2][j] == 0 || map[cas][i - 2][j] == 3)
			{
				//�µĵط���������
				map[cas][i - 2][j] += 4;
				//���ӵ�λ�ã����ӣ�-4������ ������+5��
				map[cas][i - 1][j] += 1;
				//ԭ���ĵط�������
				map[cas][i][j] -= 5;
			}

		}



		break;
	case 's':
	case 'S':
	case 80:
		//��һ���ط����ڿյػ�����Ŀ�� ����
		if (map[cas][i + 1][j] == 0 || map[cas][i + 1][j] == 3)
		{
			
			map[cas][i + 1][j] += 5;
			
			map[cas][i][j] -= 5;
		}
		else if (map[cas][i + 1][j] == 4 || map[cas][i + 1][j] == 7)
		{
			//�����ӵ���һ���ط��ж��ܲ�����
			if (map[cas][i + 2][j] == 0 || map[cas][i + 2][j] == 3)
			{
				//�µĵط���������
				map[cas][i + 2][j] += 4;
				//���ӵ�λ�ã����ӣ�-4������ ������+5��
				map[cas][i + 1][j] += 1;
				//ԭ���ĵط�������
				map[cas][i][j] -= 5;
			}

		}
		break;



	case 'a':
	case 'A':
	case 75:
		//��һ���ط����ڿյػ�����Ŀ�� ����
		if (map[cas][i][j - 1] == 0 || map[cas][i][j - 1] == 3)
		{
			//3+5=8 ����ʾĿ�ĺ�����һ��
			//�µط�(map[i-1][j])�ˣ�5������
			map[cas][i][j - 1] = map[cas][i][j - 1] + 5;
			//�ϵط�(map[i][j])�ˣ�5������
			map[cas][i][j] = map[cas][i][j] - 5;
			//j+=5  j=j+5

		}
		else if (map[cas][i][j - 1] == 4 || map[cas][i][j - 1] == 7)
		{
			//�����ӵ���һ���ط��ж��ܲ�����
			if (map[cas][i][j - 2] == 0 || map[cas][i][j - 2] == 3)
			{
				//�µĵط���������
				map[cas][i][j - 2] += 4;
				//���ӵ�λ�ã����ӣ�-4������ ������+5��
				map[cas][i][j - 1] += 1;
				//ԭ���ĵط�������
				map[cas][i][j] -= 5;
			}

		}

		break;



	case 'D':
	case 'd':
	case 77:
		//��һ���ط����ڿյػ�����Ŀ�� ����
		if (map[cas][i][j + 1] == 0 || map[cas][i][j + 1] == 3)
		{
			
			map[cas][i][j + 1] += 5;
		
			map[cas][i][j] -= 5;
		}

		//��һ���ط������ӣ��ж����ӵ���һ���ط��ǲ���Ŀ�ĺͿյ�
		else if (map[cas][i][j + 1] == 4 || map[cas][i][j + 1] == 7)
		{
			//�����ӵ���һ���ط��ж��ܲ�����
			if (map[cas][i][j + 2] == 0 || map[cas][i][j + 2] == 3)
			{
				//�µĵط���������
				map[cas][i][j + 2] += 4;
				//���ӵ�λ�ã����ӣ�-4������ ������+5��
				map[cas][i][j + 1] += 1;
				//ԭ���ĵط�������
				map[cas][i][j] -= 5;
			}

		}
		break;
	}
}





//ʤ���ж�
//��ʲô�ж�ʤ���� ���ӵ���Ŀ�ĵĸ���
int gameOver()
{
	int count = 0;
	//���еĵط���һ��
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



//�����������ʱ��Ҳ��ʤ��
int gameOver2()
{
	int count = 3;
	//���еĵط���һ��
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
		printf("\n\n\t\t   ��%d��\n", cas + 1);
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
	printf("ʤ��");
	system("pause");
	return 0;
}



		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		/*
		
		
		
		
		//�ҳ�ʼλ��
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
		printf("���ĵ�ǰ���꣨%d��%d��", i, j);
		input = _getch();
		switch (input)
		{
		case 'w':
			//0����յ�  6������  //3����Ŀ�ĵ�
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
			//�����ǰ�������ӡ�//4��������   //7���ӽ���Ŀ�ĵ�
			else if (map[i - 1][j] == 4)
			{

				if (map[i - 2][j] == 0)
				{
					map[i - 2][j] = 4; //����������ǰ��һ�����ѿյ�ID�޸�Ϊ����ID����
					//�����Ƕ�����ԭ�ؽ����ж�
					if (map[i - 1][j] == 7)
						map[i - 1][j] = 9;
					else
						map[i - 1][j] = 6;
					//�����Ƕ���ԭ�ؽ����ж�
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
				//����˵�ǰ�������ӣ�������ǰ����Ŀ�ĵء�
				else if (map[i - 2][j] == 3)
				{
					map[i - 2][j] = 7;
					count++;
					//�����Ƕ�����ԭ��λ�õ��ж�
					if (map[i - 1][j] == 7)
						map[i - 1][j] = 9;
					else
						map[i - 1][j] = 6;
					//�����Ƕ���ԭ��λ�ý����ж�
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
			}
			//�����ǰ�����Ѿ�����ĳĿ�ĵص����ӣ�
			else if (map[i - 1][j] == 7)
			{
				//�����ǰ�����Ѿ�����ĳĿ�ĵص�����,������ǰ���ǿյء�
				if (map[i - 2][j] == 0)
				{
					count--;
					map[i - 2][j] = 4;
					map[i - 1][j] = 9;
					//�����Ƕ���ԭ�ȵؽ����ж�
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
				//�����ǰ�����Ѿ�����ĳĿ�ĵص����ӣ�������ǰ������һĿ�ĵء�
				if (map[i - 2][j] == 3)
				{
					map[i - 2][j] = 7;
					map[i - 1][j] = 9;
					//�����Ƕ���ԭ��վ���ؽ����ж�
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
			}
			break;
		case 's':
			//�����ǰ���ǿյء�
			if (map[i + 1][j] == 0)
			{
				map[i + 1][j] = 6 + 0;
				if (map[i][j] == 9)
					map[i][j] = 3;
				else
					map[i][j] = 0;
			}
			//�����ǰ����Ŀ�ĵء�
			else if (map[i + 1][j] == 3)
			{
				map[i + 1][j] = 6 + 3;
				if (map[i][j] == 9)
					map[i][j] = 3;
				else
					map[i][j] = 0;
			}
			//�����ǰ�������ӡ�
			else if (map[i + 1][j] == 4)
			{
				//�����ǰ�������ӣ�������ǰ���ǿյء�
				if (map[i + 2][j] == 0)
				{
					map[i + 2][j] = 4;
					//�����Ƕ�����ԭ�ؽ����ж�
					if (map[i + 1][j] == 7)
						map[i + 1][j] = 9;
					else
						map[i + 1][j] = 6;
					//�����Ƕ���ԭ�ؽ����ж�
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
				//����˵�ǰ�������ӣ�������ǰ����Ŀ�ĵء�
				else if (map[i + 2][j] == 3)
				{
					map[i - 2][j] = 7;
					count++;
					//�����Ƕ�����ԭ��λ�õ��ж�
					if (map[i + 1][j] == 7)
						map[i + 1][j] = 9;
					else
						map[i + 1][j] = 6;
					//�����Ƕ���ԭ��λ�ý����ж�
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
			}
			//�����ǰ�����Ѿ�����ĳĿ�ĵص�����
			else if (map[i + 1][j] == 7)
			{
				//�����ǰ�����Ѿ�����ĳĿ�ĵص�����,������ǰ���ǿյء�
				if (map[i + 2][j] == 0)
				{
					count--;
					map[i + 2][j] = 4;
					map[i + 1][j] = 9;
					//�����Ƕ���ԭ�ȵؽ����ж�
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
				//�����ǰ�����Ѿ�����ĳĿ�ĵص����ӣ�������ǰ������һĿ�ĵء�
				if (map[i + 2][j] == 3)
				{
					map[i + 2][j] = 7;
					map[i + 1][j] = 9;
					//�����Ƕ���ԭ��վ���ؽ����ж�
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
			}
			break;
		case 'a':
			//�����ǰ���ǿյء�
			if (map[i][j - 1] == 0)
			{
				map[i][j - 1] = 6 + 0;
				if (map[i][j] == 9)
					map[i][j] = 3;
				else
					map[i][j] = 0;
			}
			//�����ǰ����Ŀ�ĵء�
			else if (map[i][j - 1] == 3)
			{
				map[i][j - 1] = 6 + 3;
				if (map[i][j] == 9)
					map[i][j] = 3;
				else
					map[i][j] = 0;
			}
			//�����ǰ�������ӡ�
			else if (map[i][j - 1] == 4)
			{
				//�����ǰ�������ӣ�������ǰ���ǿյء�
				if (map[i][j - 2] == 0)
				{
					map[i][j - 2] = 4;
					//�����Ƕ�����ԭ�ؽ����ж�
					if (map[i][j - 1] == 7)
						map[i][j - 1] = 9;
					else
						map[i][j - 1] = 6;
					//�����Ƕ���ԭ�ؽ����ж�
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
				//����˵�ǰ�������ӣ�������ǰ����Ŀ�ĵء�
				else if (map[i][j - 2] == 3)
				{
					count++;
					map[i][j - 2] = 7;
					if (map[i][j - 1] == 7)
						map[i][j - 1] = 9;
					else
						map[i][j - 1] = 6;
					//�����Ƕ���ԭ��λ�ý����ж�
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
			}
			//�����ǰ�����Ѿ�����ĳĿ�ĵص����ӣ�ID=7����
			else if (map[i][j - 1] == 7)
			{
				//�����ǰ�����Ѿ�����ĳĿ�ĵص�����,������ǰ���ǿյء�
				if (map[i][j - 2] == 0)
				{
					count--;
					map[i][j - 2] = 4;
					map[i][j - 1] = 9;
					//�����Ƕ���ԭ�ȵؽ����ж�
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
				//�����ǰ�����Ѿ�����ĳĿ�ĵص����ӣ�������ǰ������һĿ�ĵء�
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
			//�����ǰ���ǿյء�
			if (map[i][j + 1] == 0)
			{
				map[i][j + 1] = 6 + 0;
				if (map[i][j] == 9)
					map[i][j] = 3;
				else
					map[i][j] = 0;
			}
			//�����ǰ����Ŀ�ĵء�
			else if (map[i][j + 1] == 3)
			{
				map[i][j + 1] = 6 + 3;
				if (map[i][j] == 9)
					map[i][j] = 3;
				else
					map[i][j] = 0;
			}
			//�����ǰ�������ӡ�
			else if (map[i][j + 1] == 4)
			{
				//�����ǰ�������ӣ�������ǰ���ǿյء�
				if (map[i][j + 2] == 0)
				{
					map[i][j + 2] = 4;
					//�����Ƕ�����ԭ�ؽ����ж�
					if (map[i][j + 1] == 7)
						map[i][j + 1] = 9;
					else
						map[i][j + 1] = 6;
					//�����Ƕ���ԭ�ؽ����ж�
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
				//����˵�ǰ�������ӣ�������ǰ����Ŀ�ĵء�
				else if (map[i][j + 2] == 3)
				{
					count++;
					map[i][j + 2] = 7;
					//�����Ƕ�����ԭ��λ�õ��ж�
					if (map[i][j + 1] == 7)
						map[i][j + 1] = 9;
					else
						map[i][j + 1] = 6;
					//�����Ƕ���ԭ��λ�ý����ж�
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
			}

			else if (map[i][j + 1] == 7)
			{
				//�����ǰ�����Ѿ�����ĳĿ�ĵص�����,������ǰ���ǿյء�
				if (map[i][j + 2] == 0)
				{
					count--;
					map[i][j + 2] = 4;
					map[i][j + 1] = 9;
					//�����Ƕ���ԭ�ȵؽ����ж�
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
				//�����ǰ�����Ѿ�����ĳĿ�ĵص�����
				if (map[i][j + 2] == 3)
				{
					map[i][j + 2] = 7;
					map[i][j + 1] = 9;
					//�����Ƕ���ԭ��վ���ؽ����ж�
					if (map[i][j] == 9)
						map[i][j] = 3;
					else
						map[i][j] = 0;
				}
			}
			break;
		}
		if (count == 8)   //��������ﵽ��
		{
			system("CLS"); //����
			draw_map(map);
			break;    //�˳���ѭ��
		}
	}
	printf("\n��ϲ�㣬�����ˣ���\n"); //������ʾ
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
				printf(" "); //���ִ����·
				break;
			case 1:
				printf("#"); //���ִ���ǽ��
				break;
			case 2:
				printf(" "); //��������Ϸ�߿�Ŀհײ���
				break;
			case 3:
				printf("!"); //���ִ���Ŀ�ĵ�
				break;
			case 4:
				printf("*"); //���ִ�������
				break;
			case 7:
				printf("$"); //���ִ������ӽ���Ŀ�ĵ�
				break;
			case 6:
				printf("@"); //���ִ�����
				break;
			case 9:
				printf("@"); //���ִ����˽���Ŀ�ĵ�

			}
		}
		printf("\n");    //�������
	}
}
*/