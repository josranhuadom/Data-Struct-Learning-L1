//�ǵݼ�˳������
#include<iostream>
using namespace std;

//���������½ڵ�Ľṹ��
struct List
{
	int data;
	List * next;
};

//����������
void insert(List * & headnode, int num)
{
	List *s, *p = headnode, *q;   //*s���ڽ����½ڵ� *p���ڸ������½��
	//��������Ϊ�����½��
	s = new List;
	s->data = num;
	s->next = NULL;

	//����if������ڲ����һ�����
	if (p->next == NULL)
	{
		headnode->next = s;
		//p = s;
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
	}
	q->next = s;
	return;
}

//չʾ������
void ShowList(const List * headnode)
{
	if (headnode->data != NULL)
		cout << "�˵�����һ����" << headnode->data << "��Ԫ��" << endl;
	headnode = headnode->next;
	while (headnode)
	{
		cout << headnode->data;
		headnode = headnode->next;
		if(headnode)
			cout << '<';
	}
	cout << endl;

}

//�ϲ�������
void MergeList(List *&headnode1, List *&headnode2, List *&headnode3)
{
	List *pa, *pb, *pc;
	pa = headnode1->next; pb = headnode2->next;   //pa �� pb �ĳ�ֵ�ֱ�ָ��������ĵ�һ�����
	headnode3 = headnode1;  //�� headnode1 ��ͷ�����Ϊ headnode3 ��ͷ���
	pc = headnode3;   //pc �ĳ�ֵָ�� headnode3 ��ͷ���

	headnode3->data = headnode1->data + headnode3->data;

	while (pa && pb)
	{//pa �� pb ��û�е��� headnode1, headnode2 ��β������ժȡ������ֵ��С�Ľ����뵽 headnode3 ���
		if (pa->data <= pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}

	pc->next = pa ? pa : pb;
	delete headnode2;
}

//ɾ��������
void Delete(List *&headnode, int num)
{
	List *p = headnode;
	List *q;
	int j = 0;
	--headnode->data;
	while ((p->next) && (j < num - 1))
	{p = p->next; ++j;}
	if (!(p->next) || (j > num - 1))
		return;
	q = p->next;
	p->next = q->next;
	delete q;
	return;
}

int main()
{
	cout << "//////////////////////////////��������///////////////////////////" << endl;
	int k = 0, m = 0;  //k�������������� m���ڼ���ڵ���
	List * headnode1 = new List;
	headnode1->next = NULL;
	cout << "�����һ������" << endl;
	cout << "���������������κ���������0�Խ������룩" << endl;
	cin >> k;
	while (k != 0)
	{
		insert(headnode1, k);
		cin >> k;
		m++;
	}
	headnode1->data = m;
	ShowList(headnode1);  //�������

	//����ڶ�������
	cout << endl << endl;
	k = 0; m = 0;
	List *headnode2 = new List;
	headnode2->next = NULL;
	cout << "����ڶ�������" << endl;
	cout << "���������������κ���������0�Խ������룩" << endl;
	cin >> k;
	while (k != 0)
	{
		insert(headnode2, k);
		cin >> k;
		m++;
	}
	headnode2->data = m;
	ShowList(headnode2);

	cout << endl;
	cout << "//////////////////////////////�ϲ�����///////////////////////////////" << endl;
	List *headnode3 = new List;  //�½�������headnode3���ڴ�źϲ���
	headnode3->data = NULL;
	MergeList(headnode1, headnode2, headnode3);
	ShowList(headnode3);

	cout << endl;
	cout << "//////////////////////////////ɾ������///////////////////////////////" << endl;
	int num, choose;
	cout << "����������ɾ���Ľ�����ڵ�λ��" << endl;
	cin >> num;
	Delete(headnode3, num);
	cout << "ɾ�����" << endl;
	ShowList(headnode3);
	cout << endl;
	cout << "�Ƿ����ɾ�������밴1�����밴0" << endl;
	cin >> choose;
	while (choose == 1)
	{
		cout << "����������ɾ���Ľ�����ڵ�λ��" << endl;
		cin >> num;
		Delete(headnode3, num);
		cout << "ɾ�����" << endl;
		ShowList(headnode3);
		cout << endl;
		cout << "�Ƿ����ɾ�������밴1�����밴0" << endl;
		cin >> choose;
	}



	system("pause");
}

