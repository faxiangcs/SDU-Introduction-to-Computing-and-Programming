/*������
���ߣ�yfx
ʱ�䣺2022��11��27�ա���2022��12��21��*/
/*��־��1.����ز�  2.�������   3.�������  4.�ж���Ӯ  5.�жϺ���  6.���ƽ���  
        7.�����ж�   8.������Ϸ  9.���̹���  10.�������� 11.�˻���ս 12.������ս*/

#include <graphics.h>   //ͼ�ο⣬��easyx����
#include <windows.h>   
#include<math.h>
#include<stdio.h>


int flag = 0;//�������
int board[21][21] = { 0 };//0��ʾû������
int sta[21][21] = { 0 };//�洢����
int score[21][21] = { 0 };//�˻���ս����
int judge(int a, int b); //�ж���Ӯ
int isfull(int a, int b);//�ж������Ƿ�����
void  save_chess(int sta[21][21], int a, int b); //����Ծ�����
void replay_chess(int flag); //����
void playpve();//�˻���ս
void playchess();//���˶�ս
void playeve();//������ս
int a = 0, b = 0,x2 = 0,y2 = 0;

void init()    //�������̵Ĵ���
{
	initgraph(758, 623);      //ͼƬ��С
	loadimage(0, "�ز�/����.jpg");   //����ͼƬ,д��ַ
	setbkmode(TRANSPARENT);//�������屳��͸����Ĭ�ϲ�͸��
	settextcolor(BLACK);
	outtextxy(645, 80, "yfx��������");
	
}

void playpve()//�˻���ս
{
	int x = 0, y = 0, a = 0, b = 0;
	void calculate();
	FILE* fp;
	HWND hwnd = GetHWnd();//������ǰ��ʾ����
	loadimage(0, "�ز�/����.jpg");
	outtextxy(630, 80, "��ǰģʽ��PVE");
	outtextxy(640, 120, "���1������");
	outtextxy(640, 160, "���ԣ�����");
	while (1)
	{
		MOUSEMSG msg = GetMouseMsg();  //��ȡ�����Ϣ������
		for (int i = 1; i < 20; i++)   //У������λ��
		{
			for (int j = 1; j < 20; j++)
			{
				if (abs(msg.x - 16 - i * 30) < 12 && abs(msg.y - 17 - j * 30) < 12)
				{
					x = i * 30 + 16;
					y = j * 30 + 17;
					a = i;
					b = j;
				}
			}
		}
		
		if (msg.uMsg == WM_LBUTTONDOWN)  //�������
		{
			//�ж��Ƿ�����
			if (abs(msg.x - 680) < 30 && abs(msg.y - 395) < 15)
			{
				if (flag % 2 == 0)
				{
					MessageBox(hwnd, "���1���䣬����ʤ��", "��Ϸ����", MB_OK);
					save_chess(sta, a, b);
					break;
				}
			}
			else if (board[a][b] != 0)
			{
				MessageBox(hwnd, "��λ���������ӣ������ԣ�", "��ʾ", MB_OK);
				continue;//�˳�ѭ�����½���
			}
			else if (flag % 2 == 0)
			{
				setfillcolor(BLACK);  //�ڰ׽���
				solidcircle(x, y, 12);//�ڵ�ǰλ�û�ȡ����
				board[a][b] = 1;   //1��ʾ����ռ��
				sta[a][b] = flag + 1;//��ʾ��n���µ���������
				flag++;
			}
			if (judge(a, b))
			{
				if (flag % 2 == 0)
				{
					MessageBox(hwnd, "����ʤ��", "��Ϸ����", MB_OK);
					save_chess(sta, a, b);
					break;
				}
				if (flag % 2 == 1)
				{
					MessageBox(hwnd, "���1ʤ��", "��Ϸ����", MB_OK);
					save_chess(sta, a, b);
					break;
				}
			}

			if (isfull(a, b) == 1) //�ж������Ƿ�����
			{
				MessageBox(hwnd, "���ֺ���", "��Ϸ����", MB_OK);
				save_chess(sta, a, b);
				break;
			}
			
			//��������
			setfillcolor(WHITE);
			Sleep(500);
			calculate();
			a = x2, b = y2;
			solidcircle(a * 30 + 16, b * 30 + 17, 12);//�ڵ�ǰλ�û�ȡ����
			board[a][b] = 2;   //2��ʾ����ռ��
			sta[a][b] = flag + 1;
			flag++;
		}
		
		if (judge(a, b))
		{
			if (flag % 2 == 0)
			{
				MessageBox(hwnd, "����ʤ��", "��Ϸ����", MB_OK);
				save_chess(sta, a, b);
				break;
			}
			if (flag % 2 == 1)
			{
				MessageBox(hwnd, "���1ʤ��", "��Ϸ����", MB_OK);
				save_chess(sta, a, b);
				break;
			}
		}
		if (isfull(a, b) == 1) //�ж������Ƿ�����
		{
			MessageBox(hwnd, "���ֺ���", "��Ϸ����", MB_OK);
			save_chess(sta, a, b);
			break;
		}
	}
	
	//��Ϸ������������̣���ʼ������
	x = 0, y = 0, a = 0, b = 0;
	for (int i = 1; i < 20; i++)
	{
		for (int j = 1; j < 20; j++)
		{
			board[i][j] = 0;
			sta[i][j] = 0;
			score[i][j] = 0;
		}
	}
	clearcircle(200, 300, 700);//�������
	loadimage(0, "�ز�/����.jpg");
	setbkmode(TRANSPARENT);//�������屳��͸����Ĭ�ϲ�͸��
	settextcolor(BLACK);
	outtextxy(650, 200, "������Ϸ");
	while (1)
	{
		MOUSEMSG m = GetMouseMsg();  //��ȡ�����Ϣ������
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			if (abs(m.x - 680) < 40 && abs(m.y - 200) < 15)
			{
				replay_chess(flag);//��ʼ����
				fp = fopen("Save_chess.txt", "w");//ɾ������
				fclose(fp);
				for (int i = 1; i < 20; i++)//��ʼ������
				{
					for (int j = 1; j < 20; j++)
					{
						sta[i][j] = 0;
					}
				}
				flag = 0;
				break;
			}
			else
				break;
		}
	}
	flag = 0;
}
void calculate()
{
	int personnum = 0; 
	int botnum = 0;
	int emptynum = 0;
	int m = 0;
	for (int i = 1; i < 20; i++)
	{
		for (int j = 1; j < 20; j++)
		{
			score[i][j] = 0;
		}
	}
	for (int row = 1; row < 20; row++)
	{
		for (int col = 1; col < 20; col++)
		{
			for (int x = -1; x <= 1; x++)
			{                            //Y�ķ�Χ��-1,0,1
				for (int y = -1; y <= 1; y++)
				{                            //X�ķ�Χ�� -1,0,1
					if (y == 0 && x == 0)
					{
						continue;
					}
					personnum = 0;
					botnum = 0;
					emptynum = 0;
						//�Ժ�������(����)
					for (int i = 1; i <= 4; i++)
					{
						int curRow = row + i * x;
						int curCol = col + i * y;
						if (curRow >= 1 && curRow < 20 &&
							curCol >= 1 && curCol < 20 && board[curRow][curCol] == 1)//�÷����t�����ӵ�����
						{
							personnum++;  //������ҵĺ���
						}
						else if (curRow >= 1 && curRow < 20 &&
							curCol >= 1 && curCol < 20 && board[curRow][curCol] == 0)
						{
							emptynum++; //�����հ�ֹͣ����
							break;
						}
						else
							break;  //���߽�����а���
					}    

						//�Ժ������֣�����
					for (int i = 1; i <= 4; i++)
						{
							int curRow = row - i * x;
							int curCol = col - i * y;
							if (curRow >= 1 && curRow < 20&&
								curCol >= 1 && curCol < 20&& board[curRow][curCol] == 1)//�÷����t�����ӵ�����
							{
								personnum++;  //������ҵĺ���
							}
							else if (curRow >= 1 && curRow < 20 &&
								curCol >= 1 && curCol < 20 && board[curRow][curCol] == 0)
							{
								emptynum++; //�����հ�ֹͣ����
								break;
							}
							else
								break;  //���߽�����а���
					}

						//��ʼ���
					if (personnum == 1)  //ɱ��
						score[row][col] += 10;
					else if (personnum == 2)
					{           //ɱ��
						if (emptynum == 1)  //����
							score[row][col] += 30;
						else if (emptynum == 2)//����
							score[row][col] += 40;
					}
					else if (personnum == 3)//ɱ��
					{
						if (emptynum == 1)//����
							score[row][col] += 60;
						else if (emptynum == 2)//����
							score[row][col] += 200;
					}
					else if (personnum == 4)//ɱ��
						score[row][col] += 20000;

					//���һ��
					emptynum = 0;
					//�԰�������(����)
					for (int i = 1; i <= 4; i++)
					{
						int curRow = row + i * x;
						int curCol = col + i * y;
						if (curRow >= 1 && curRow < 20 &&
							curCol >= 1 && curCol < 20 && board[curRow][curCol] == 2)//�÷����t�����ӵ�����
						{
							botnum++;  //��������
						}
						else if (curRow >= 1 && curRow < 20 &&
							curCol >= 1 && curCol < 20 && board[curRow][curCol] == 0)
						{
							emptynum++; //�����հ�ֹͣ����
							break;
						}
						else
							break;  //���߽�
					}

					//�԰������֣�����
					for (int i = 1; i <= 4; i++)
					{
						int curRow = row - i * x;
						int curCol = col - i * y;
						if (curRow >= 1 && curRow < 20 &&
							curCol >= 1 && curCol < 20 && board[curRow][curCol] == 2)//�÷����t�����ӵ�����
						{
							botnum++;  //��������
						}
						else if (curRow >= 1 && curRow < 20 &&
							curCol >= 1 && curCol < 20 && board[curRow][curCol] == 0)
						{
							emptynum++; //�����հ�ֹͣ����
							break;
						}
						else
							break;  //���߽�
					}
					//��ʼ���
					if (botnum == 0)  //��ͨ����
						score[row][col] += 5;
					else if (botnum == 1)//���
						score[row][col] += 10;
					else if (botnum == 2)
					{
						if (emptynum == 1)  //����
							score[row][col] += 25;
						else if (emptynum == 2)//����
							score[row][col] += 50;
					}
					else if (botnum == 3)
					{
						if (emptynum == 1)//����
							score[row][col] += 55;
						else if (emptynum == 2)//����
							score[row][col] += 1000;
					}
					else if (botnum == 4)
						score[row][col] += 30000;//����

					if (board[row][col] != 1 && board[row][col]!=2)
					{
						if (m < score[row][col])
						{
							m = score[row][col];
							x2 = row;
							y2 = col;
						}
					}
					else
						break;
				}
			}
		}
	}	
}

void playeve()
{
	int x = 0, y = 0, a = 0, b = 0;
	FILE* fp;
	HWND hwnd = GetHWnd();//������ǰ��ʾ����
	loadimage(0, "�ز�/����.jpg");
	outtextxy(630, 80, "��ǰģʽ��EVE");
	outtextxy(640, 120, "����1������");
	outtextxy(640, 160, "����2������");
	while (1)
	{
		if (flag % 2 == 0)
		{
			setfillcolor(BLACK);
			Sleep(600);
			calculate();
			a = x2, b = y2;
			solidcircle(a * 30 + 16, b * 30 + 17, 12);//�ڵ�ǰλ�û�ȡ����
			board[a][b] = 1;   
			sta[a][b] = flag + 1;
			flag++;
		}
		//�ж���Ӯ
		if (judge(a, b))
		{
			if (flag % 2 == 0)
			{
				MessageBox(hwnd, "����2ʤ��", "��Ϸ����", MB_OK);
				save_chess(sta, a, b);
				break;

			}
			else if (flag % 2 == 1)
			{
				MessageBox(hwnd, "����1ʤ��", "��Ϸ����", MB_OK);
				save_chess(sta, a, b);
				break;

			}
		}
		if (isfull(a, b) == 1) //�ж������Ƿ�����
		{
			MessageBox(hwnd, "���ֺ���", "��Ϸ����", MB_OK);
			save_chess(sta, a, b);
			break;
		}
		if (flag % 2 == 1)
		{
			setfillcolor(WHITE);
			Sleep(600);
			calculate();
			a = x2, b = y2;
			solidcircle(a * 30 + 16, b * 30 + 17, 12);//�ڵ�ǰλ�û�ȡ����
			board[a][b] = 2;   //����ռ��
			sta[a][b] = flag + 1;
			flag++;
		}
		//�ж���Ӯ
		if (judge(a, b))
		{
			if (flag % 2 == 0)
			{
				MessageBox(hwnd, "����2ʤ��", "��Ϸ����", MB_OK);
				save_chess(sta, a, b);
				break;

			}
			else if (flag % 2 == 1)
			{
				MessageBox(hwnd, "����1ʤ��", "��Ϸ����", MB_OK);
				save_chess(sta, a, b);
				break;

			}
		}

		if (isfull(a, b) == 1) //�ж������Ƿ�����
		{
			MessageBox(hwnd, "���ֺ���", "��Ϸ����", MB_OK);
			save_chess(sta, a, b);
			break;
		}
	}
	//��Ϸ������������̣���ʼ������
	x = 0, y = 0, a = 0, b = 0;
	for (int i = 1; i < 20; i++)
	{
		for (int j = 1; j < 20; j++)
		{
			board[i][j] = 0;
			sta[i][j] = 0;
			score[i][j] = 0;
		}
	}
	clearcircle(200, 300, 700);//�������
	loadimage(0, "�ز�/����.jpg");
	setbkmode(TRANSPARENT);//�������屳��͸����Ĭ�ϲ�͸��
	settextcolor(BLACK);
	outtextxy(650, 200, "������Ϸ");
	while (1)
	{
		MOUSEMSG m = GetMouseMsg();  //��ȡ�����Ϣ������
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			if (abs(m.x - 680) < 40 && abs(m.y - 200) < 15)
			{
				replay_chess(flag);//��ʼ����
				fp = fopen("Save_chess.txt", "w");//ɾ������
				fclose(fp);
				for (int i = 1; i < 20; i++)//��ʼ������
				{
					for (int j = 1; j < 20; j++)
					{
						sta[i][j] = 0;
					}
				}
				flag = 0;
				break;
			}
			else
				break;
		}
	}
	flag = 0;
}
void playchess()   //�������ӿ�ʼ���˶�ս
{
	int x = 0, y = 0, a = 0, b = 0;
	FILE* fp;
	HWND hwnd = GetHWnd();//������ǰ��ʾ����
	loadimage(0, "�ز�/����.jpg");   
	outtextxy(630, 80, "��ǰģʽ��PVP");
	outtextxy(640, 120, "���1������");
	outtextxy(640, 160, "���2������");
	while (1)
	{
		MOUSEMSG msg = GetMouseMsg();  //��ȡ�����Ϣ������
		for (int i = 1; i < 20; i++)   //У������λ��
		{
			for (int j = 1; j < 20; j++)
			{
				if (abs(msg.x - 16 - i * 30) < 12 && abs(msg.y - 17 - j * 30) < 12)
				{
						x = i * 30 + 16;
						y = j * 30 + 17;
						a = i;
						b = j;
				}
			}
		}

		if (msg.uMsg == WM_LBUTTONDOWN)  //�������
		{
				//�ж��Ƿ�����
			if (abs(msg.x - 680) < 30 && abs(msg.y - 395) < 15)
			{
				if (flag % 2 == 0)
				{
					MessageBox(hwnd, "���1���䣬���2ʤ��", "��Ϸ����", MB_OK);
					save_chess(sta, a, b);
					break;
				}
				if (flag % 2 == 1)
				{
					MessageBox(hwnd, "���2���䣬���1ʤ��", "��Ϸ����", MB_OK);
					save_chess(sta, a, b);
					break;
				}
			}
			else if (board[a][b] != 0)
			{
				MessageBox(hwnd, "��λ���������ӣ������ԣ�", "��ʾ", MB_OK);
				continue;//�˳�ѭ�����½���
			}
			else if (flag % 2 == 0)
			{
				setfillcolor(BLACK);  //�ڰ׽���
				solidcircle(x, y, 12);//�ڵ�ǰλ�û�ȡ����
				board[a][b] = 1;   //1��ʾ����ռ��
				sta[a][b] = flag + 1;//��ʾ��n���µ���������

			}
			else if (flag % 2 == 1)
			{
				setfillcolor(WHITE);
				solidcircle(x, y, 12);
				board[a][b] = 2;   //2��ʾ����ռ��
				sta[a][b] = flag + 1;
			}
			flag++;
		}
		//�ж���Ӯ
		if (judge(a, b))
		{
			if (flag % 2 == 0)
			{
				MessageBox(hwnd, "���2ʤ��", "��Ϸ����", MB_OK);
				save_chess(sta, a, b);
				break;

			}
			else if (flag % 2 == 1)
			{
				MessageBox(hwnd, "���1ʤ��", "��Ϸ����", MB_OK);
				save_chess(sta, a, b);
				break;

			}
		}

		if (isfull(a, b) == 1) //�ж������Ƿ�����
		{
			MessageBox(hwnd, "���ֺ���", "��Ϸ����", MB_OK);
			break;
		}
	}
	
	//��Ϸ������������̣���ʼ������
	x = 0, y = 0, a = 0, b = 0;
	for (int i = 1; i < 20; i++)
	{
		for (int j = 1; j < 20; j++)
	    {
		 board[i][j] = 0;
		 sta[i][j] = 0;
		}
	}
	clearcircle(200, 300, 700);//�������
	loadimage(0, "�ز�/����.jpg");  
	setbkmode(TRANSPARENT);//�������屳��͸����Ĭ�ϲ�͸��
	settextcolor(BLACK);
	outtextxy(650, 200, "������Ϸ");
	while (1)
	{
		MOUSEMSG m = GetMouseMsg();  //��ȡ�����Ϣ������
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			if (abs(m.x - 680) < 40 && abs(m.y - 200) < 15)
			{
				replay_chess(flag);//��ʼ����
				fp = fopen("Save_chess.txt", "w");//ɾ������
				fclose(fp);
				for (int i = 1; i < 20; i++)//��ʼ������
				{
					for (int j = 1; j < 20; j++)
					{
						sta[i][j] = 0;
					}
				}
				flag = 0;
				break;
			}
			else
				break;
		}
	}
	flag = 0;
}

//�ж���Ӯ
int judge(int a, int b)
{
	int i, j;
	int t = 2 - flag % 2; //1��ʾ���壬2��ʾ����
	for (i = a - 4, j = b; i <= a; i++)  //���ж�
	{
		if (i >= 0 && i < 16 && t == board[i][j] && t == board[i + 1][j] && t == board[i + 2][j] && t == board[i + 3][j] && t == board[i + 4][j])
		{
			return 1;
		}
	}
	for (i = a, j = b - 4; j <= b; j++)  //���ж�
	{
		if (i >= 0 && i < 16 && t == board[i][j] && t == board[i][j + 1] && t == board[i][j + 2] && t == board[i][j + 3] && t == board[i][j + 4])
		{
			return 1;
		}
	}
	for (i = a - 4, j = b - 4;i <= a ,j <= b; i++,j++)  //б�ж�
	{
		if (i >= 0 && i < 16 && t == board[i][j] && t == board[i + 1][j + 1] && t == board[i + 2][j + 2] && t == board[i + 3][j + 3] && t == board[i + 4][j + 4])
		{
			return 1;
		}
	}
	for (i = a - 4, j = b + 4; i <= a , j >= 1; i++, j--)  //б�ж�
	{
		if (i >= 0 && i < 16 && t == board[i][j] && t == board[i + 1][j - 1] && t == board[i + 2][j - 2] && t == board[i + 3][j - 3] && t == board[i + 4][j - 4])
		{
			return 1;
		}
	}
}

int isfull(int a, int b)  //�ж������Ƿ�����
{
	int i, j;
	int ret = 1;
	for (i = 1; i < 20; i++)
	{
		for (j = 1; j < 20; j++)
		{
			if (board[i][j] == 0)         //�������飬����һ��λ��Ϊ�գ������̲���
			{
				ret = 0;
				break;
			}
		}
	}
	return ret;
}

void  save_chess(int sta[21][21], int a, int b)  //����Ծ�����
{
	FILE* fp;
	fp = fopen("Save_chess.txt", "w");
	if ((fp = fopen("Save_chess.txt", "w")) == NULL) 
		printf("�洢ʧ��");
	else 
	{
		for (int i = 1; i <= flag; i++)
		{
			for (int j = 1; j < 20; j++)
			{
				for (int k = 1; k < 20; k++)
				{
					if (sta[j][k] == i)
					{
						fprintf(fp, "%d %d ", j, k);
					}
				}
			}
		}
		fclose(fp);
	}
}

void replay_chess(int flag)//������Ϸ
{
	FILE* fp;
	loadimage(0, "�ز�/����.jpg"); 
	setbkmode(TRANSPARENT);//�������屳��͸����Ĭ�ϲ�͸��
	settextcolor(BLACK);
	outtextxy(630, 80, "��ǰģʽ������");
	fp = fopen("Save_chess.txt", "r");
	if (fp== NULL)
	{
		printf("����ʧ��");
		exit(1);
	}
	else 
	{
		for (int a = 0; a < flag; a++)
		{
			int i = 0, j = 0;
			fscanf(fp, "%d %d", &i, &j);
			if (a % 2 == 0)
			{
				setfillcolor(BLACK);
				solidcircle(i * 30 + 16, j * 30 + 17, 12);
			}
			else if (a % 2 == 1)
			{
				setfillcolor(WHITE);
				solidcircle(i * 30 + 16, j * 30 + 17, 12);
			}
			Sleep(600);
		}
		fclose(fp);
	}
}

int main()
{
	init(); //��ʼ������
	FILE* fp;
	while (1)
	{
		flag = 0;
		MOUSEMSG msg = GetMouseMsg();  //��ȡ�����Ϣ������
		if (msg.uMsg == WM_LBUTTONDOWN)
		{
			if (abs(msg.x - 680) < 40 && abs(msg.y - 260) < 15)//�㿪ʼ
			{
				fp = fopen("Save_chess.txt", "w");//ɾ������
				fclose(fp);
				loadimage(0, "�ز�/����.jpg");
				outtextxy(658, 80, "��ѡ��");
	            outtextxy(650, 120, "���˶�ս");
	            outtextxy(650, 160, "�˻���ս");
				outtextxy(650, 200, "������ս");
			}
			if (abs(msg.x - 680) < 40 && abs(msg.y - 120) < 15)
			{
				playchess();//�������Ӳ���ʼ���˶�ս
			}
			if (abs(msg.x - 680) < 40 && abs(msg.y - 160) < 15)
			{
				playpve();//�˻���ս
			}
			if (abs(msg.x - 680) < 40 && abs(msg.y - 200) < 15)
			{
				playeve();//������ս
			}
		}
	}
    system("pause");
    return 0;
}