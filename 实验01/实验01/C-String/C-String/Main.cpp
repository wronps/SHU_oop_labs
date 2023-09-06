// Main.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib> 					// for atoi
#include <conio.h>
#include "C-String.h"
#include "SortStrings.h"
using namespace std;

// �Զ����C-�ַ������������ԣ������׼C-�ַ����������Ƚ�
void TestStr()
{
	char str[][20] = {"", "abc", "abcd", "�Ϻ���ѧ"};
	char s0[80], s1[80];
	int n = sizeof(str) / sizeof(*str);

	cout << "\n���Զ����C-�ַ������������ԣ������׼C-�ַ����������Ƚϡ�";
	for (int i = 0; i < n; i++)
	{
		cout << "\nStrLen(\"" << str[i] << "\") : " << StrLen(str[i]);
		cout << "\nstrlen(\"" << str[i] << "\") : " << strlen(str[i]) << endl;

		cout << "\nStrCpy(s0, \"" << str[i] << "\") : \"" << StrCpy(s0, str[i]) << "\"";
		cout << "\nstrcpy(s1, \"" << str[i] << "\") : \"" << strcpy(s1, str[i]) << "\"";
		cout << "\nstrcmp(s0, s1) : " << strcmp(s0, s1) << "\t��0��ʾ��ȷ�������ʾ����" << endl;

		cout << "\nStrCat(s0, \"" << str[i] << "\") : \"" << StrCat(s0, str[i]) << "\"";
		cout << "\nstrcat(s1, \"" << str[i] << "\") : \"" << strcat(s1, str[i]) << "\"";
		cout << "\nstrcmp(s0, s1) : " << strcmp(s0, s1) << "\t��0��ʾ��ȷ�������ʾ����" << endl;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "\nStrCmp(\"" << str[i] << "\", \"" << str[j] << "\") : " << StrCmp(str[i], str[j]);
			cout << "\nstrcmp(\"" << str[i] << "\", \"" << str[j] << "\") : " << strcmp(str[i], str[j]) << endl;
		}
	}
}

// �Զ���AtoI�������ԣ������׼����atoi�Ƚ�
void TestAtoI()
{
	char str[][20] = { " +12345","+ 12345", " 12345", "		- 123", "	  -123", " 123.45", "+123abc", "", "-abc", "+ABC" };
	int n = sizeof(str) / sizeof(*str), x, y, q, err = 0;

	cout << "\n������AtoI�������׼����atoi�Ƚϡ�" << endl;
	for (int i = 0; i < n; i++)
	{
		x = AtoI(str[i]);
		y = atoi(str[i]);
		q = x - y;
		if (q < 0) q = -q;
		if (q > err) err = q;
		cout << "AtoI(\"" << str[i] << "\") : " << x << endl;
		cout << "atoi(\"" << str[i] << "\") : " << y << ",\t" << (x==y?"��ȷ":"����") << endl;
	}
	cout << "������: " << err << endl;
}

// C-�ַ�����������
void TestSwap()
{
	char array1[20] = "Tom", array2[20] = "Jerry";		// �ַ���������ΪC-�ַ���������
	const char* p1 = "Snoopy", * p2 = "Winnie";			// ָ��ָ���ַ�������������������׵�ַ��
	cout << "\n��C-�ַ����������ԡ�" << endl;
	cout << "����ǰ\tarray1: \"" << array1 << "\",\tarray2: \"" << array2 << "\"" << endl;
	swap(array1, array2);
	cout << "������\tarray1: \"" << array1 << "\",\tarray2: \"" << array2 << "\"" << endl;

	cout << "\n����ǰ\tp1: \"" << p1 << "\",\tp2: \"" << p2 << "\"" << endl;
	swap(p1, p2);
	cout << "������\tp1: \"" << p1 << "\",\tp2: \"" << p2 << "\"" << endl;
}

// �����ַ����������Զ���չ����
void TestHeapString()
{
	char* str = NULL;											// 18. �˴�ΪʲôҪ��str��ʼ��ΪNULL������ᷢ��ʲô�����
	char s[1024];
	cout << "\"" << GetHeapString(str, "Hello") << "\"" << endl;
	cout << "\"" << GetHeapString(str, " world!") << "\"" << endl;
	FreeHeapString(str);
	cout << GetHeapString(str, "������һ���ַ���: ");			// 19. ÿִ��һ��GetHeapString��FreeHeapString������str��ָ���Ƿ����仯��
	cin.getline(s, 1024);
	cout << "\"" << GetHeapString(str, s) << "\"" << endl;
	FreeHeapString(str);
}

// ���ִ洢��ʽ��C-�ַ��������������
void TestSortStrings()
{
	char strA[][NUM] =		{ "enter", "number", "C/C++�������", "size", "ָ��", "begin", "of", "����", "cat", "case", "program", "certain", "a", "cake", "side" };
	char* strB[] =			{ "enter", "number", "C/C++�������", "size", "ָ��", "begin", "of", "����", "cat", "case", "program", "certain", "an", "cake", "side" };
	const char* strB0[] =	{ "enter", "number", "C/C++�������", "size", "ָ��", "begin", "of", "����", "cat", "case", "program", "certain", "an", "cake", "side" };
	char** strC = NULL, ** strD = NULL, ** strE = NULL;
	int n1 = sizeof(strA) / sizeof(*strA), n2 = sizeof(strB) / sizeof(*strB), n0 = sizeof(strB0) / sizeof(*strB0);

	cout << "\n�����ִ洢��ʽ��C-�ַ�������������ԡ�" << endl;
																// 20. �볢���ȸ��������������������г�����֤��Ľ���
	cout << "sizeof(strA) : " << sizeof(strA) << " Bytes,\tsizeof(*strA) : " << sizeof(strA[0]) << " Bytes,\tn1 = " << n1
		 << "\nsizeof(strB) : " << sizeof(strB) << " Bytes,\tsizeof(*strB) : " << sizeof(strB[0]) << " Bytes,\tn2 = " << n2 << endl;
	cout << "\nsizeof(strC) : " << sizeof(strC) << " Bytes"
		 << "\nsizeof(strD) : " << sizeof(strD) << " Bytes"
		 << "\nsizeof(strE) : " << sizeof(strE) << " Bytes" << endl;

	GetStrings0(strC, strB0, n0);
	GetStrings1(strD, strB0, n0);
	GetStrings2(strE, strB0, n0);
	//���ˣ����ִ洢��ʽ���ַ��������Ѿ�ȫ��������ɡ�
																// 21. ��ֱ𻭳�strA��strB��strC��strD��strE�Ľṹͼ��ָ���������ڵĿռ䣨�����ء�ջ����������

	ShowStrings("\nstrA ����: ", strA, n1);
//	BubbleB(strA, n1);											// 22. �˴�Ϊʲô������BubbleB������
	BubbleA(strA, n1);							
	ShowStrings("A������: ", strA, n1);

	ShowStrings("\nstrB ����: ", strB, n2);
//	BubbleA(strB, n2);											// 23. �˴�Ϊʲô������BubbleA��������������ͨ����������ʱ��
	BubbleB(strB, n2);
	ShowStrings("B������: ", strB, n2);

	ShowStrings("\nstrC ����: ", strC, n0);
	BubbleB(strC, n0);											// 24. �˴�Ϊʲô����BubbleB������strC[0]�Ƿ񱻸ı䣿
	ShowStrings("B������: ", strC, n0);
	FreeStrings(strC, n0, true);								// 25. �ͷ�StrC����Դ��Ϊʲô�������������ܲ�����Ĭ��ֵfalse��
	GetStrings0(strC, strB0, n0);				// ���¹��������StrC
	ShowStrings("strC ����: ", strC, n0);
	BubbleA(strC, n0);											// 26. �˴�ΪʲôҪ��BubbleA������strC[0]�Ƿ񱻸ı䣿strC[0]�������Ƿ񱻸ı䣿
	ShowStrings("A������: ", strC, n0);

	ShowStrings("\nstrD ����: ", strD, n0);
	BubbleA(strD, n0);											// 27. �˴�Ϊʲô�ȿ�����BubbleA���ֿ�����BubbleB������
	ShowStrings("A������: ", strD, n0);
	FreeStrings(strD, n0);
	GetStrings1(strD, strB0, n0);
	ShowStrings("strD ����: ", strD, n0);
	BubbleB(strD, n0);
	ShowStrings("B������: ", strD, n0);

	ShowStrings("\nstrE ����: ", strE, n0);
	BubbleB(strE, n0);											// 28. �˴�Ϊʲô������BubbleA������
	ShowStrings("B������: ", strE, n0);

	FreeStrings(strE, n0);										// 29. �˴��Ƿ����д��FreeStrings(strE, n0, false);��
	FreeStrings(strD, n0);
	FreeStrings(strC, n0, true);								// 30. �˴��Ƿ����д��FreeStrings(strC, 1);��
}

// C-�ַ������������±�Խ�磩���
void Testing()
{
	unsigned long x = 1234567890;
	char str[5];
	unsigned long y = x;
	int m = int(&y) - int(str), n = int(str) - int(&x);
	cout << "&x = " << hex << int(&x) << ",\tp = " << int(str) << ",\t&y = " << int(&y)
		 << ",\t��� " << dec << n << ",\t" << m << " �ֽ�" << endl;

	n = (n < 0)? -n : m;					// ���ǵ���ͬ�ı��������������ڴ��еĴ��˳��ͬ

	cout << "x = " << x << ", y = " << y << endl;
	for (int i = 0; i < 2; i++)
	{
		cout << "\nѭ��2�Ρ�������һ���ַ������ַ����ĳ��ȷֱ�(1)С��" << n
			 << "; (2)���ڻ����" << n << "��: " << endl;
		cin.getline(str, 80);
		cout << "���볤��Ϊ " << strlen(str) << " �ֽڵ��ַ���str����۲���� x �� y �Ƿ���" << endl;
		cout << "x = " << x << ", y = " << y << ", str = \"" << str << "\"" << endl;
		cout << "�ָ����� x �� y ��ԭֵ����۲��ַ��� str �Ƿ��б仯" << endl;
		x = y = 1234567890;
		cout << "x = " << x << ", y = " << y << ", str = \"" << str << "\"" << endl;
	}
}

int main()
{
	int choice;
	while (true)
	{
		cout << "\n1. C-�ַ�����������������"
			 << "\n2. C-�ַ���ת���� AtoI ����"
			 << "\n3. C-�ַ�����������"
			 << "\n4. C-�ַ��������������"
			 << "\n5. ����C-�ַ����������Զ���չ����"
			 << "\n6. C-�ַ����±�Խ��ʾ��"
			 << "\n0. �˳�" << endl;
		choice = getche();
		cout << endl;
		if (choice <= '0') break;
		switch (choice)
		{
		case '1':	TestStr();			break;
		case '2':	TestAtoI();			break;
		case '3':	TestSwap();			break;
		case '4':	TestSortStrings();	break;
		case '5':	TestHeapString();	break;
		case '6':	Testing();			break;
		}
	}
	return 0;
}
