#include "demo.h"


/// <summary>
/// 初始化整个信息链表
/// </summary>
/// <param name="pHead">信息链表的头节点</param>
void initInfo(info*& pHead) {
	if (pHead != NULL)//如果已被初始化过
		return;

	pHead = (info*)malloc(sizeof(pHead));
	if (pHead == NULL)//如果分配失败
	{
		cout << "空间不足分配失败" << endl;
		exit(1);
	}


	pHead->next = NULL;
}

/// <summary>
/// 获取当前链的最后一个节点的地址
/// </summary>
/// <param name="pHead">链</param>
/// <returns>尾节点的地址</returns>
info* getTailNode(info* pHead) {
	while (pHead->next != NULL)//只要下一个节点不是空，就继续往后跳
		pHead = pHead->next;
	return pHead;
}

/// <summary>
/// 创建新节点
/// </summary>
/// <param name="pHead">整个链的头节点</param>
void createInfo(info*& pHead)
{
	
	info* temp = getTailNode(pHead);
	info* newInfoNode = (info*)malloc(sizeof(info));

	if (newInfoNode == NULL)//如果分配失败
	{
		cout << "空间不足分配失败" << endl;
		exit(1);
	}
	string t;
	cout << "请输入联系人的姓名" << endl;
	scanf_s("%s", &newInfoNode->name, 25);

	cout << "请输入联系人的电话号" << endl;
	scanf_s("%s", &newInfoNode->phoneNumber, 11);


	
	//将新节点入链
	newInfoNode->next = NULL;
	temp->next = newInfoNode;

	//对所有节点进行一个排序，使其符合姓名字典序的由小到大
}

/// <summary>
/// 输出所有的联系人信息
/// </summary>
/// <param name="pHead">信息链</param>
void printInfo(const info* pHead) {
	info* p = pHead->next;
	while (p)
	{
		cout << "姓名=" << p->name << "  电话号码=" << p->phoneNumber << endl;
		p = p->next;
	}
}


/// <summary>
/// 清屏函数，清空整个控制台已显示的信息
/// </summary>
void consoleClear() {
	system("cls");
}

/// <summary>
/// 等待函数
/// </summary>
/// <param name="time">要等待的毫秒数</param>
void Delay(int time)//毫秒
{
	clock_t now = clock();
	while (clock() - now < time);
}

/// <summary>
/// 归并排序的辅助程序
/// </summary>
/// <param name="left">左指针</param>
/// <param name="right">右指针</param>
/// <returns>整个数据链的头指针</returns>
info* mergeSort(info* left, info* right) {
	info* res = (info*)malloc(sizeof(info));
	if (res == NULL) {
		exit(1);
	}
	//strcpy(res->name, "\0");
	//strcpy(res->phoneNumber, "\0");
	res->next = NULL;
	info* head = res;
	//归并中的 "合"

	bool flag = false;//用于存储两个字符串比较之后的结果
	//改顺序就错？？？？？？
	while (left && right) {
		if (strcmp(left->name, right->name) > 0)//切换顺序，s1小于s2
		{
			flag = true;
		}
		else
		{
			flag = false;
		}

		if (flag) {//根据关键字进行反转
			//左边小
			head->next = left;
			head = head->next;
			left = left->next;
		}
		else {
			//右边小
			head->next = right;
			head = head->next;
			right = right->next;
		}
	}
	//剩下的左边
	while (left) {
		head->next = left;
		head = head->next;
		left = left->next;
	}
	//剩下的右边
	while (right) {
		head->next = right;
		head = head->next;
		right = right->next;
	}
	return res->next;
}
/// <summary>
/// 归并排序的主程序用于找出中间的
/// </summary>
/// <param name="infoHead">整个信息链的头指针</param>
/// <returns></returns>
info * sortList(info *infoHead) {
	
	if (infoHead == NULL)//为空直接退出
		return NULL;

	if (!infoHead->next)
		return infoHead;//如果只有一个头指针或者头节点但没有后续的数据节点，就直接返回

	info* res = (info*)malloc(sizeof(info));

	if (res == NULL)//如果分配失败
	{
		cout << "空间不足分配失败" << endl;
		exit(1);
	}

	info* slow = infoHead;
	info* fast = infoHead;
	info* sign = NULL;
	//快慢指针找到单链表的中间节点
	while (fast && fast->next) {
		sign = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	sign->next = NULL;

	//进行递归
	info* left = sortList(infoHead);
	info* right = sortList(slow);
	return mergeSort(left, right);	
}