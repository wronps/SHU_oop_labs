// SortStrings.h
#ifndef SORTSTRINGS_H
#define SORTSTRINGS_H
#include <iostream>
using namespace std;

#define NUM 20

// ����3�������Ĺ��ܣ�ͨ���������ַ������飬���첻ͬ��ŷ�ʽ�Ķ�̬C-�ַ�������
void GetStrings0(char**& dest, const char* const source[], int n);
void GetStrings1(char**& dest, const char* const source[], int n);
void GetStrings2(char**& dest, const char* const source[], int n);

void FreeStrings(char**& strs, int n, bool flag = false);			// �ͷŶ�̬C-�ַ�������flagΪtrueָ������ţ�flaseָ��������ţ�

void BubbleA(char (*strs)[NUM], int n);								// ͨ������C-�ַ��������ݣ�ʵ������
void BubbleA(char** strs, int n);									// ͨ������C-�ַ��������ݣ�ʵ������
void BubbleB(char** strs, int n);									// ͨ������C-�ַ�����ָ��

template <typename T> void ShowStrings(const char* prompt, const T* const strs, int n)
{																	// �˴�T������char*, char (*)[NUM]
	if (n > 0)
		cout << prompt << strs[0];
	for (int i = 1; i < n; i++)
		cout << ", " << strs[i];
	cout << endl;
}
#endif
