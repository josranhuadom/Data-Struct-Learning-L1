#include<iostream>
using namespace std;

//链栈的储存结构
struct StackNode
{
	char bracket;
	struct StackNode *next;
};

//入栈
void Push(StackNode *&S, char bracket)
{
	StackNode *p = new StackNode;
	p->bracket = bracket;
	p->next = S;
	S = p;
}

//取栈顶元素
char GetTop(StackNode *& S)
{
	if (S != NULL)
		return S->bracket;
}

//出栈
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

//括号匹配函数
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
			cout << "栈已空" << endl;
			return;
		}
		else if (flag == 0)
		{
			cout << "匹配失败" << endl;
			return;
		}
		else
		{
			cout << "请继续输入" << endl;
			cin >> bracket;
		}
	}
	return;
}

int main()
{
	StackNode *S = NULL;
	char bracket;
	cout << "可以输入'(', ')', '[', ']', '{', '}'，输入'#'来结束输入（注意请使用英文字符）" << endl;
	cin >> bracket;
	Checking(S, bracket);
	system("pause");
}