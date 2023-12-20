#include <stdio.h>

// ��char�����������
void charSort(char *charList, int charAmount);
// ��int�����������
void numberSort(int *numberList, int numberAmount);
// ���ݼ�¼��λ�ý���Ӧ����ĸװ������str
void loadChar(char *str, char *charList, int *charLoc, int charAmount);
// ���ݼ�¼��λ�ý���Ӧ������װ������str
void loadNumber(char *str, int *numberList, int *numberLoc, int numberAmount);
int main()
{
    // �ַ������ȣ��ַ�������ĸ�����������ֵ�����
    int amount, charAmount = 0, numberAmount = 0;
    char str[1001];
    // ��¼str��������ĸ���±�����ֵ��±�
    int charLoc[1001], numberLoc[1001];
    // char��������ĸ��ɵ�����
    char charList[1001];
    // str������������ɵ�����
    int numberList[1001];
    scanf("%d %s", &amount, str);
    // ����str����
    for (int i = 0; i < amount; i++)
    {
        char ch = str[i];
        // ��ÿ��λ�õ��ַ����з����ͳ��
        if (ch >= 'A' && ch <= 'Z')
        {
            // ��¼�����±�
            charLoc[charAmount] = i;
            // ��¼ֵ
            charList[charAmount++] = ch;
        }
        else if (ch >= '0' && ch <= '9')
        {
            //��¼�����±�
            numberLoc[numberAmount] = i;
            // ��¼ֵ
            numberList[numberAmount++] = ch - '0';
        }
    }

    // ���ö�Ӧ�ĺ���
    charSort(charList, charAmount);
    numberSort(numberList, numberAmount);
    loadChar(str, charList, charLoc, charAmount);
    loadNumber(str, numberList, numberLoc, numberAmount);

    printf("%s", str);
}

void charSort(char *charList, int charAmount)
{   int i,t=0;
    for(int j=0;j<charAmount-1; j++)
	    {
			for(int i=0;i<charAmount-1-j;i++)
		    {
				if(charList[i]>charList[i+1])
				{
					t=charList[i+1];
					charList[i+1]=charList[i];
					charList[i]=t;
				}
			}
		}                            //TODO: ��char��������
}

void numberSort(int *numberList, int numberAmount)
{
    int i,t=0;
	    for(int j=0;j<numberAmount-1;j++)
		    {
				for(int i=0;i<numberAmount-1-j;i++)
			    {
					if(numberList[i]<numberList[i+1])
					{
						t=numberList[i+1];
						numberList[i+1]=numberList[i];
						numberList[i]=t;
					}
				}
			}                                              //TODO: ��int��������
}

void loadChar(char *str, char *charList, int *charLoc, int charAmount)
{
    for(int k=0;k<charAmount;k++) 
	{
		for(int i=0;i<1001;i++)
		{
			if(charLoc[k]==i)
			{
				str[i]=charList[k];
			}
		}
	}                               //TODO: ���ݼ�¼��λ�ý���Ӧ����ĸװ������str
}

void loadNumber(char *str, int *numberList, int *numberLoc, int numberAmount)
{for(int k=0;k<numberAmount;k++) 
	{
		for(int i=0;i<1001;i++)
		{
			if(numberLoc[k]==i)
			{
				str[i]=numberList[k]+'0';
			}
		}
	}                                                  //TODO: ���ݼ�¼��λ�ý���Ӧ������װ������str
}
