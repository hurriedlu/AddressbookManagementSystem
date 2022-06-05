#include "demo.h"

char server_name[30];

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
	pHead = sort_message_order(pHead);
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


//新的归并方法，测试中

/// <summary>
/// 链表的升序方法
/// </summary>
/// <param name="head">头指针</param>
/// <returns>排序完成后的头指针</returns>
info* sort_message_order(info* head) //升序  按照姓名升序顺序

{
	info* Back, * pointer; //p指针指向新的节点 back指针指向链表的尾节点
	info  temp; // 定义结构体student别名,typedef也可以定义的结构体别名
	Back = head->next;
	pointer = head->next; //跳过头结点 指向下一个节点 头结点中没有学生信息 
	while (Back != NULL) //如果尾节点不为空 就一直遍历下去
	{
		while (pointer->next != NULL) //如果指向新开辟的结点不为空就一直遍历下去
		{
			pointer = pointer->next; //指向下一个新开辟的结点
			if (strcmp(Back->name, pointer->name) > 0)  //如果back->ID大于pointer->ID就返回大于0的值；后面大于前面的 往后放
			{
				strcpy(temp.phoneNumber, Back->phoneNumber);
				strcpy(temp.name, Back->name);  //把尾节点值赋值给临时temp结构体变量


				strcpy(Back->phoneNumber, pointer->phoneNumber);
				strcpy(Back->name, pointer->name); //把指向的新节点 跟尾节点交换 位置


				strcpy(pointer->phoneNumber, temp.phoneNumber);
				strcpy(pointer->name, temp.name);//将临时temp结构体变量赋值给指向的结构体变量

			}
		}
		Back = Back->next; //指向下一个尾节点
		pointer = Back;  //指向尾节点
	}
	return head;  //返回头结点
}

/// <summary>
/// 按照姓名进行查找，返回找到的节点的上一个地址
/// </summary>
/// <param name="pHead">头节点</param>
/// <param name="key">姓名关键字</param>
/// <returns>该节点的上一个节点的地址</returns>
info* lookup_previous(const info* pHead,char key[]) {
	if (pHead == NULL)
		return NULL;
	//pHead = pHead->next;//跳过头节点
	info *tmp = NULL;//如果找到了节点就将地址存入
	while (pHead->next) {		
		if (strcmp(key, pHead->next->name) == 0)//如果关键字和姓名完全相等，就证明找到了
		{
			tmp = (info*)pHead;
			break;
		}
		pHead = pHead->next;
	}

	return tmp;
}

/// <summary>
/// 按照姓名作为关键字进行查找
/// </summary>
/// <param name="pHead">信息链的头节点</param>
/// <param name="key">关键字</param>
/// <returns>对应节点的地址</returns>
info* lookup(const info* pHead, char key[]) {
	if (pHead == NULL)
		return NULL;
	pHead = pHead->next;//跳过头节点
	info* tmp = NULL;//如果找到了节点就将地址存入
	while (pHead) {
		if (strcmp(key, pHead->name) == 0)//如果关键字和姓名完全相等，就证明找到了
		{
			tmp = (info*)pHead;
		}
		pHead = pHead->next;
	}
	return tmp;
}

/// <summary>
/// 对信息链中的某一个节点进行电话号码的修改
/// </summary>
/// <param name="p">要修改的节点地址</param>
void modifyPhoneNumber(info* p) {
	cout << "请输入 "<<p->name<<" 的新电话号" << endl;
	cin >> server_name;
	//scanf_s("%s", server_name, 11);
	strcpy_s(p->phoneNumber, sizeof(p->phoneNumber)/sizeof(p->phoneNumber[0]), server_name);
	cout << endl << endl << "修改成功" << endl << endl;
	cout << "修改后的信息为：" << endl;
	printInfoNode(p);
}

/// <summary>
/// 输出指定节点的信息
/// </summary>
/// <param name="p">指定节点的地址</param>
void printInfoNode(const info* p) {
	cout << "姓名=" << p->name << "  电话号码=" << p->phoneNumber << endl;
}

/// <summary>
/// 删除节点
/// </summary>
/// <param name="p">要删除的节点的前一个节点地址</param>
void deleteInfoNode(info* p) {
	info* t = p->next;
	p->next = p->next->next;//剔除某一节点
	free(t);//释放掉删除的空间
}

/// <summary>
/// 读取存在的文件
/// </summary>
/// <param name="pHead"></param>
void readFile(info *pHead) {
	bool flag = true;//默认为尾部插入，需要排序，否则为初始化时进行,不需要排序  
	if (pHead->next == NULL) {//如果头节点的下一个指针是NULL，就证明这是在初始的过程中调用的
		flag = false;
	}
	else {//否则调用获取尾节点的函数，在尾部插入然后排序
		pHead = getTailNode(pHead);
	}

	info t,*p,*q = pHead;//临时节点，临时节点指针，头指针，排序用
	ifstream fin("d:\\data.ini");   //打开文件准备读取
	if (!fin)              // 如果读取失败，打印fail
	{
		cerr << "fail" << endl;
		exit(1);
	}

	fin >> t.name >> t.phoneNumber;//读取出来的数据存储临时节点
	while (t.name[0] != '#' && t.phoneNumber[0] != '#') {//只要没读到#，就证明没读到底

		//创建节点
		p = (info*)malloc(sizeof(info));
		if (p == NULL) {
			cout << "空间不足" << endl;
			exit(1);
		}

		//拷贝数据到新的节点
		strcpy_s(p->name, sizeof(p->name) / sizeof(p->name[0]), t.name);
		strcpy_s(p->phoneNumber, sizeof(p->phoneNumber) / sizeof(p->phoneNumber[0]), t.phoneNumber);

		//将节点连接到数据链的尾端
		p->next = pHead->next;
		pHead->next = p;

		fin >> t.name >> t.phoneNumber;//读取下一组信息
	}
	
	if (flag)//如果为true则证明是追加的，进行一下排序
	{
		pHead = sort_message_order(q);//对整个信息链进行排序
	}
	
	fin.close();//读取完成关闭连接
}


/// <summary>
/// 将信息链写入到文件
/// </summary>
/// <param name="pHead"></param>
void writeFile(info* pHead) {
	/*info t;
	strcpy_s(t.name, sizeof(t.name) / sizeof(t.name[0]), "hello");
	strcpy_s(t.phoneNumber, sizeof(t.phoneNumber) / sizeof(t.phoneNumber[0]), "world");*/

	ofstream fout("D:\\data.ini");//打开文件
	pHead = pHead->next;//跳过头节点
	while (pHead) {
		fout << pHead->name << " " << pHead->phoneNumber << endl;//将链表信息依次入队
		pHead = pHead->next;
	}	

	fout << "### ###" << endl;//加上结束标识符
	fout.close();//写完后关闭连接
}

/// <summary>
/// 进行确认判断，如果输入y或Y返回true，否则false
/// </summary>
/// <returns></returns>
bool confirmOperation() {
	char c;
	cin >> c;
	if (c == 'y' || c == 'Y')
		return true;
	else
		return false;
}