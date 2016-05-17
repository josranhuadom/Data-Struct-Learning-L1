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
	List *s, *p = headnode, *q;   //*s用于建立新节点 *p用于跟踪最新结点
								  //以下三行为构建新结点
	s = new List;
	s->data = num;
	s->next = NULL;

	//以下if语句用于插入第一个结点
	if (p->next == NULL)
	{
		headnode->next = s;
		//p = s;
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
	}
	q->next = s;
	return;
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
	int k = 0, m = 0;  //k用于输入新数据 m用于计算节点数
	List * headnode = new List;
	headnode->next = NULL;
	cout << "请输入除零以外的任何数" << endl;
	cin >> k;
	while (k != 0)
	{
		insert(headnode, k);
		cin >> k;
		m++;
		headnode->data = m;
	}
	ShowList(headnode);  //输出链表


	system("pause");
}





/*#include<iostream>
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
	List  *H1, *H2, *H3;
	H1 = headnode1;
	H2 = headnode2;
	H3 = headnode3;

	while (H1 && H2)
	{
		if (headnode3 == NULL)
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
		}

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
}

void Cancel(List * & headnode, int num)
{
	List * save, * H3;
	H3 = headnode;
	int j = 1;
	while ((H3->next) && (j < num))
	{
		H3 = H3->next;
		++j;
	}
	if (!(H3->next) && (j > num))
	{
		cout << "数据错误" << endl;
		return;
	}
	save = H3;
	H3 = save->next;
	delete save;
	return;
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
	cout << "您输入的数为：";
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
	cout << "您输入的数为";
	ShowList(headnode2);

	cout << endl;

	//以下是合并链表部分
	cout << "合并链表" << endl;
	List * headnode3 = NULL;
	CombineLists(headnode1, headnode2, headnode3);
	cout << "合并后";
	ShowList(headnode3);

	cout << endl;

	//以下是删除节点部分
	char judgement;
	do
	{
		char judgement;
		cout << "接下来是删除节点，请问想删除哪一个节点？" << endl;
		cin >> k;
		Cancel(headnode3, k);
		cout << "删除后";
		ShowList(headnode3);
		cout << "想继续删除节点请按Y，想退出可按其余按键" << endl;
		cin >> judgement;
	} while (judgement = 'Y');

	system("pause");
}
*/
