// C-String.cpp
#include "C-String.h"
#include <cstring>

int StrLen(const char* str)
{
	int n;
	for (n = 0; str[n] != '\0'; n++)
		;
	return n;
}

char* StrCpy(char* dest, const char* source)
{
	char* temp = dest;
	while (*dest++ = *source++)					// 1. ����ͱ�ѭ����ִ�й��̣���ʱ����ѭ����Ϊʲô��ָ����α仯��ָ���Ŀ����α仯��
		;
	return temp;								// 2. ΪʲôҪʹ��ָ�����temp���˴��ܷ�ĳ�return dest;��
}

char* StrCat(char* str1, const char* str2)
{
	char* temp = str1;
	while (*str1)								// 3. ��ѭ������ʱָ��str1��Ŀ����ʲô�ַ���
		str1++;
	while (*str1++ = *str2++)
		;
	return temp;
}

int StrCmp(const char* str1, char* str2)
{
	unsigned char* p = (unsigned char*)str1;	// 4. ΪʲôҪ����������ָ�����p��q��
	unsigned char* q = (unsigned char*)str2;
	while (*p && *q && *p == *q)				// 5. ����Щ������ܵ��±�ѭ������������ܾ���˵������
		p++, q++;
	return *p > * q ? 1 : (*p < *q ? -1 : 0);	// 6. ��������־�ַ�'\0'��ֵ���ڶ��٣���ʲô���ã�
}

int AtoI(const char* str)
{
	int sgn = 1, num = 0, i;
	for (i = 0; str[i] == ' ' || str[i] == '\t' || str[i] == '\n'; i++)
		;
	if (str[i] == '+' || str[i] == '-')
	{
		sgn = (str[i] == '+') ? 1 : -1;
		i++;
	}
	for (; str[i]; i++)
	{
		if ('0' <= str[i] && str[i] <= '9')		// 7. �������ʽ�Ƿ���д�� ('0' <= str[i] <= '9') ��
			num = 10 * num + (str[i] - '0');	// 8. ���ʽ��ΪʲôҪ��ȥ'0'��
		else
			break;
	}
	return sgn * num;
}

void swap(char* str1, char* str2)				// ������������C++ϵͳ�ṩ�ĺ���ģ��swap
{
	char* temp = new char[StrLen(str1) + 1];
	StrCpy(temp, str1);
	StrCpy(str1, str2);
	StrCpy(str2, temp);
	delete[] temp;
}

// �����ַ����������Զ���չ����
char* GetHeapString(char*& str, const char* source)	// 9. �˴�ΪʲôҪ��ƴ���ָ������ã�
{
	if (str == NULL)							// ���������������ζ�ű��������Դ����ָ��
	{
		str = new char[1];
		str[0] = '\0';
	}
	if (source == NULL) return str;
	char* temp = new char[strlen(str) + strlen(source) + 1];	// ����������Դ�ռ�
	strcpy(temp, str);							// ����ԭ������
	strcat(temp, source);						// ׷��������
	delete[] str;								// �ͷ�ԭ������Դ
	str = temp;									// ����Ϊ�µĶѵ�ֵַ
	return str;
}

void FreeHeapString(char*& str)
{
	if (str != NULL)
		delete[] str;
	str = NULL;									// 10. ΪʲôҪ��strΪNULL��
}
