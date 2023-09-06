// SortStrings.cpp		C-�ַ�����������
#include "SortStrings.h"
#include <cstring>

void GetStrings0(char**& dest, const char* const source[], int n)	// 11. ��һ������ΪʲôҪ���ݶ���ָ������ã�
{
	dest = new char* [n];
	if (dest == NULL) return;
	dest[0] = new char[n * NUM];
	if (dest[0] == NULL)
	{
		delete[] dest;				// �ͷ�����ɹ��Ķѿռ䵥Ԫ
		dest = NULL;
		return;
	}
	for (int i = 1; i < n; i++)										// 12. ��ָ����ѭ��������
		dest[i] = dest[i - 1] + NUM;
	for (int i = 0; i < n; i++)
	{
		strncpy(dest[i], source[i], NUM);							// 13. �˴�ΪʲôҪ��strncpy������
		dest[i][NUM - 1] = '\0';									// 14. ������������ʲô��
	}
}

void GetStrings1(char**& dest, const char* const source[], int n)
{
	dest = new char* [n];
	if (dest == NULL) return;
	for (int i = 0; i < n; i++)
	{
		dest[i] = new char[NUM];
		strncpy(dest[i], source[i], NUM);
		dest[i][NUM - 1] = '\0';
	}
}

void GetStrings2(char**& dest, const char* const source[], int n)
{
	dest = new char* [n];
	if (dest == NULL) return;
	size_t len;
	for (int i = 0; i < n; i++)
	{
		len = strlen(source[i]);
		dest[i] = new char[len + 1];
		strcpy(dest[i], source[i]);
	}
}

void FreeStrings(char**& strs, int n, bool flag)					// 15. ��һ������ΪʲôҪ���ݶ���ָ������ã�
{
	if (strs != NULL)
	{
		if (flag)
		{
			char* temp = strs[0];
			for (int i = 1; i < n; i++)								// 16. ��һ�δ����������ʲô��
				if (strs[i] < temp)
					temp = strs[i];
			if (temp != NULL)
				delete[] temp;
		}
		else
		{
			for (int i = 0; i < n; i++)
				if (strs[i] != NULL)
					delete[] strs[i];
		}
		delete[] strs;												// 17. �˴��ͷŵ�������ʲô���飿
		strs = NULL;
	}
}

void BubbleA(char (*strs)[NUM], int n)
{
	char temp[NUM];
	for (int i = 1; i < n; i++)						// ������ size-1 �ֱȽϺͽ���
	{
		for (int j = 0; j < n - i; j++)
		{
			if (strcmp(strs[j], strs[j + 1]) > 0)	// ����Ԫ��֮��Ƚϣ���Ҫʱ
			{
				strcpy(temp, strs[j]);				// ����ָ��strs[j] �� strs[j+1]������
				strcpy(strs[j], strs[j + 1]);
				strcpy(strs[j + 1], temp);
			}
		}
	}
}

void BubbleA(char** strs, int n)					// ����BubbleA����������Ӧ��ͬ��ʵ��
{
	char temp[NUM];
	for (int i = 1; i < n; i++)						// ������ size-1 �ֱȽϺͽ���
	{
		for (int j = 0; j < n - i; j++)
		{
			if (strcmp(strs[j], strs[j + 1]) > 0)	// ����Ԫ��֮��Ƚϣ���Ҫʱ
			{
				strcpy(temp, strs[j]);				// ����ָ��strs[j] �� strs[j+1]������
				strcpy(strs[j], strs[j + 1]);
				strcpy(strs[j + 1], temp);
			}
		}
	}
}

void BubbleB(char** strs, int n)
{
	char* temp;
	for (int i = 1; i < n; i++)						// ������ size-1 �ֱȽϺͽ���
	{
		for (int j = 0; j < n - i; j++)
		{
			if (strcmp(strs[j], strs[j + 1]) > 0)	// ����Ԫ��֮��Ƚϣ���Ҫʱ
			{
				temp = strs[j];						// ����ָ��strs[j] �� strs[j+1]��ָ��
				strs[j] = strs[j + 1];
				strs[j + 1] = temp;
			}
		}
	}
}
