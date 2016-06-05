//非递减顺序排列
#include<iostream>
using namespace std;

//构建构建新节点的结构体
struct List
{
	int data;
	List * next;
};

//插入链表函数
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

//展示链表函数
void ShowList(const List * headnode)
{
	if (headnode->data != NULL)
		cout << "此单链表一共有" << headnode->data << "个元素" << endl;
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

//合并链表函数
void MergeList(List *&headnode1, List *&headnode2, List *&headnode3)
{
	List *pa, *pb, *pc;
	pa = headnode1->next; pb = headnode2->next;   //pa 和 pb 的初值分别指向两个表的第一个结点
	headnode3 = headnode1;  //将 headnode1 的头结点作为 headnode3 的头结点
	pc = headnode3;   //pc 的初值指向 headnode3 的头结点

	headnode3->data = headnode1->data + headnode3->data;

	while (pa && pb)
	{//pa 和 pb 均没有到达 headnode1, headnode2 表尾，依次摘取两表中值较小的结点插入到 headnode3 最后
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

//删除链表函数
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
	cout << "//////////////////////////////输入链表///////////////////////////" << endl;
	int k = 0, m = 0;  //k用于输入新数据 m用于计算节点数
	List * headnode1 = new List;
	headnode1->next = NULL;
	cout << "输入第一个链表" << endl;
	cout << "请输入除零以外的任何数（输入0以结束输入）" << endl;
	cin >> k;
	while (k != 0)
	{
		insert(headnode1, k);
		cin >> k;
		m++;
	}
	headnode1->data = m;
	ShowList(headnode1);  //输出链表

	//输入第二个链表
	cout << endl << endl;
	k = 0; m = 0;
	List *headnode2 = new List;
	headnode2->next = NULL;
	cout << "输入第二个链表" << endl;
	cout << "请输入除零以外的任何数（输入0以结束输入）" << endl;
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
	cout << "//////////////////////////////合并链表///////////////////////////////" << endl;
	List *headnode3 = new List;  //新建单链表headnode3用于存放合并表
	headnode3->data = NULL;
	MergeList(headnode1, headnode2, headnode3);
	ShowList(headnode3);

	cout << endl;
	cout << "//////////////////////////////删除链表///////////////////////////////" << endl;
	int num, choose;
	cout << "请输入您想删除的结点所在的位置" << endl;
	cin >> num;
	Delete(headnode3, num);
	cout << "删除完成" << endl;
	ShowList(headnode3);
	cout << endl;
	cout << "是否继续删除，是请按1，否请按0" << endl;
	cin >> choose;
	while (choose == 1)
	{
		cout << "请输入您想删除的结点所在的位置" << endl;
		cin >> num;
		Delete(headnode3, num);
		cout << "删除完成" << endl;
		ShowList(headnode3);
		cout << endl;
		cout << "是否继续删除，是请按1，否请按0" << endl;
		cin >> choose;
	}



	system("pause");
}

