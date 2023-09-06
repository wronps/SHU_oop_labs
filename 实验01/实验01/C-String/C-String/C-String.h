// C-String.h
#ifndef C_STRING_H
#define C_STRING_H

// �Զ����C-�ַ�������������
int StrLen(const char* str);
char* StrCpy(char* dest, const char* source);
char* StrCat(char* str1, const char* str2);
int StrCmp(const char* str1, char* str2);
int AtoI(const char* str);
void swap(char* str1, char*  str2);		// ����C++ϵͳ�ṩ�ĺ���ģ��

// �����ַ����������Զ���չ����
char* GetHeapString(char*& str, const char* source);
void FreeHeapString(char*& str);

#endif
