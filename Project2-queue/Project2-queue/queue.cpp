#include<iostream>
using namespace std;

//��ջ�Ĵ���ṹ
struct StackNode
{
	char bracket;
	struct StackNode *next;
};

//��ջ
void Push(StackNode *&S, char bracket)
{
	StackNode *p = new StackNode;
	p->bracket = bracket;
	p->next = S;
	S = p;
}

//ȡջ��Ԫ��
char GetTop(StackNode *& S)
{
	if (S != NULL)
		return S->bracket;
}

//��ջ
void Pop(StackNode *&S)
{
	StackNode *p;
	if (S == NULL)
		return;
	//e->bracket = S->bracket;
	p = S;
	S = S->next;
	delete p;
	return;
}

//����ƥ�亯��
void Checking(StackNode *&S, char bracket)
{
	int flag = 1;
	while (bracket != '#' && flag)
	{
		switch (bracket)
		{
		case '(': case '[': case'{':
			Push(S, bracket);
			break;
		case ')':
			if (S != NULL && GetTop(S) == '(')
				Pop(S);
			else flag = 0;
			break;
		case ']':
			if (S != NULL && GetTop(S) == '[')
				Pop(S);
			else flag = 0;
			break;
		case '}':
			if (S != NULL && GetTop(S) == '{')
				Pop(S);
			else flag = 0;
			break;
		}
		if (S == NULL && flag)
		{
			cout << "ջ�ѿ�" << endl;
			return;
		}
		else if (flag == 0)
		{
			cout << "ƥ��ʧ��" << endl;
			return;
		}
		else
		{
			cout << "���������" << endl;
			cin >> bracket;
		}
	}
	return;
}

int main()
{
	StackNode *S = NULL;
	char bracket;
	cout << "��������'(', ')', '[', ']', '{', '}'������'#'���������루ע����ʹ��Ӣ���ַ���" << endl;
	cin >> bracket;
	Checking(S, bracket);
	system("pause");
}