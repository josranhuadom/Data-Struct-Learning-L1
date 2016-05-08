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
			headnode = s;
			return;
		}

		//�½ڵ�������Сʱ�Ĳ���
		if (headnode->data > s->data)
		{
			s->next = headnode;
			headnode= s;
			return;
		}

		//����ԱȲ�������
		for (q = headnode, p = headnode->next; p; q = p, p = p->next)
			if (p->data >= s->data)
			{
				s->next = p;
				q->next = s;
				return;
			}
		q->next = s;
		return;

	}

//չʾ��������
void ShowList(const List * headnode)
{
	cout << "�����������Ϊ��";
	while (headnode)
	{
		cout << headnode->data;
		headnode = headnode->next;
		cout << '<';
	}
	cout << endl;
}

void CombineLists(List * & headnode1, List * & headnode2, List * & headnode3)
{
	headnode3->next = NULL;
	List  *H1, *H2, *H3;
	H1 = headnode1;
	H2 = headnode2;
	H3 = headnode3->next;

	while (H1 && H2)
	{
		/*if (headnode3 == NULL)
		{
			if (H1->data >= H2->data)
			{
				H3 = H2;
				headnode3 = H3;
				H2 = H2->next;
			}
			else
			{
				H3 = H1;
				headnode3 = H3;
				H1 = H1->next;
			}

			continue;
		}*/

		if (H1->data >= H2->data)
		{
			H3->next = H2;
			H3 = H2;
			H2 = H2->next;
		}
		else
		{
			H3->next = H1;
			H3 = H1;
			H1 = H1->next;
		}
	}

	H3->next = H1 ? H1 : H2;
	H3 = H3->next;
	delete headnode2;
}


int main()
{
	int k;
	List * headnode1 = NULL;
	cout << "�������һ������" << endl;
	cout << "���������������κ���" << endl;
	cin >> k;
	while (k != 0)
	{
		insert(headnode1, k);
		cin >> k;
	}
	ShowList(headnode1);  //�������

	cout << endl;

	//��������ڶ����������ڵڶ�С��
	List * headnode2 = NULL;
	cout << "������ڶ�������" << endl;
	cout << "���������������κ���" << endl;
	cin >> k;
	while (k != 0)
	{
		insert(headnode2, k);
		cin >> k;
	}
	ShowList(headnode2);

	cout << "�ϲ�����" << endl;
	List * headnode3 = NULL;
	CombineLists(headnode1, headnode2, headnode3);
	ShowList(headnode3);

	system("pause");
}
