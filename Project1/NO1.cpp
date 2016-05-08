#include<iostream>
using namespace std;
struct List
	//构建构建新节点的结构体
	//非递减顺序排列
{
	int data;
	List * next;
};

void insert(List * & headnode, int num)
{
		List *s, *p, *q;   //*s用于建立新节点 *p用于跟踪最新结点
		//以下三行为构建新结点
		s = new List;
		s->data = num;
		s->next = NULL;

		//以下if语句用于插入第一个结点
		if (headnode == NULL)
		{
			headnode = s;
			return;
		}

		//新节点数据最小时的操作
		if (headnode->data > s->data)
		{
			s->next = headnode;
			headnode= s;
			return;
		}

		//常规对比插入排序
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

//展示链表数据
void ShowList(const List * headnode)
{
	cout << "您所输入的数为：";
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
	cout << "请输入第一个链表" << endl;
	cout << "请输入除零以外的任何数" << endl;
	cin >> k;
	while (k != 0)
	{
		insert(headnode1, k);
		cin >> k;
	}
	ShowList(headnode1);  //输出链表

	cout << endl;

	//以下输入第二个链表，用于第二小问
	List * headnode2 = NULL;
	cout << "请输入第二个链表" << endl;
	cout << "请输入除零以外的任何数" << endl;
	cin >> k;
	while (k != 0)
	{
		insert(headnode2, k);
		cin >> k;
	}
	ShowList(headnode2);

	cout << "合并链表" << endl;
	List * headnode3 = NULL;
	CombineLists(headnode1, headnode2, headnode3);
	ShowList(headnode3);

	system("pause");
}
