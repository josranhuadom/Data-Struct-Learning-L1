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
			headnode->next = s;
			p = headnode->next;
			return;
		}

		//新节点数据最小时的操作
		if (headnode->next->data > s->data)
		{
			s->next = headnode->next;
			headnode->next = s;
			return;
		}

		//常规对比插入排序
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
	cout << "您所输入的数为：";
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
	cout << "请输入除零以外的任何数" << endl;
	cin >> k;
	while (k != 0)
	{
		insert(headnode, k);
		cin >> k;
	}
	ShowList(headnode);  //输出链表
}
