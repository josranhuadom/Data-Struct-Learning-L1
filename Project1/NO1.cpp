#include<iostream>
using namespace std;
struct List
	//���������½ڵ�Ľṹ��
	//�ǵݼ�˳������
{
	int data;
	List * next;
};

void insert(List * & headnode, int num)
{
		List *s, *p, *q;   //*s���ڽ����½ڵ� *p���ڸ������½��
		//��������Ϊ�����½��
		s = new List;
		s->data = num;
		s->next = NULL;

		//����if������ڲ����һ�����
		if (headnode == NULL)
		{
			headnode->next = s;
			p = headnode->next;
			return;
		}

		//�½ڵ�������Сʱ�Ĳ���
		if (headnode->next->data > s->data)
		{
			s->next = headnode->next;
			headnode->next = s;
			return;
		}

		//����ԱȲ�������
		for (q = headnode->next, p = headnode->next->next; p; q = p, p = p->next)
		{
			if (p->data >= s->data)
			{
				s->next = p;
				q->next = s;
				return;
			}
			q->next = s;
			return;
		}
	}

void ShowList(const List * headnode)
{
	cout << "�����������Ϊ��";
	while (headnode)
	{
		cout << headnode->data << '\t';
		headnode = headnode->next;
	}
	cout << endl;
}
int main()
{
	int k;
	List * headnode = NULL;
	headnode->next = NULL;
	cout << "���������������κ���" << endl;
	cin >> k;
	while (k != 0)
	{
		insert(headnode, k);
		cin >> k;
	}
	ShowList(headnode);  //�������
}
