#include "demo.h"


/// <summary>
/// ��ʼ��������Ϣ����
/// </summary>
/// <param name="pHead">��Ϣ�����ͷ�ڵ�</param>
void initInfo(info*& pHead) {
	if (pHead != NULL)//����ѱ���ʼ����
		return;

	pHead = (info*)malloc(sizeof(pHead));
	if (pHead == NULL)//�������ʧ��
	{
		cout << "�ռ䲻�����ʧ��" << endl;
		exit(1);
	}


	pHead->next = NULL;
}

/// <summary>
/// ��ȡ��ǰ�������һ���ڵ�ĵ�ַ
/// </summary>
/// <param name="pHead">��</param>
/// <returns>β�ڵ�ĵ�ַ</returns>
info* getTailNode(info* pHead) {
	while (pHead->next != NULL)//ֻҪ��һ���ڵ㲻�ǿգ��ͼ���������
		pHead = pHead->next;
	return pHead;
}

/// <summary>
/// �����½ڵ�
/// </summary>
/// <param name="pHead">��������ͷ�ڵ�</param>
void createInfo(info*& pHead)
{
	
	info* temp = getTailNode(pHead);
	info* newInfoNode = (info*)malloc(sizeof(info));

	if (newInfoNode == NULL)//�������ʧ��
	{
		cout << "�ռ䲻�����ʧ��" << endl;
		exit(1);
	}
	string t;
	cout << "��������ϵ�˵�����" << endl;
	scanf_s("%s", &newInfoNode->name, 25);

	cout << "��������ϵ�˵ĵ绰��" << endl;
	scanf_s("%s", &newInfoNode->phoneNumber, 11);


	
	//���½ڵ�����
	newInfoNode->next = NULL;
	temp->next = newInfoNode;

	//�����нڵ����һ������ʹ����������ֵ������С����
}

/// <summary>
/// ������е���ϵ����Ϣ
/// </summary>
/// <param name="pHead">��Ϣ��</param>
void printInfo(const info* pHead) {
	info* p = pHead->next;
	while (p)
	{
		cout << "����=" << p->name << "  �绰����=" << p->phoneNumber << endl;
		p = p->next;
	}
}


/// <summary>
/// ���������������������̨����ʾ����Ϣ
/// </summary>
void consoleClear() {
	system("cls");
}

/// <summary>
/// �ȴ�����
/// </summary>
/// <param name="time">Ҫ�ȴ��ĺ�����</param>
void Delay(int time)//����
{
	clock_t now = clock();
	while (clock() - now < time);
}

/// <summary>
/// �鲢����ĸ�������
/// </summary>
/// <param name="left">��ָ��</param>
/// <param name="right">��ָ��</param>
/// <returns>������������ͷָ��</returns>
info* mergeSort(info* left, info* right) {
	info* res = (info*)malloc(sizeof(info));
	if (res == NULL) {
		exit(1);
	}
	//strcpy(res->name, "\0");
	//strcpy(res->phoneNumber, "\0");
	res->next = NULL;
	info* head = res;
	//�鲢�е� "��"

	bool flag = false;//���ڴ洢�����ַ����Ƚ�֮��Ľ��
	//��˳��ʹ�����������
	while (left && right) {
		if (strcmp(left->name, right->name) > 0)//�л�˳��s1С��s2
		{
			flag = true;
		}
		else
		{
			flag = false;
		}

		if (flag) {//���ݹؼ��ֽ��з�ת
			//���С
			head->next = left;
			head = head->next;
			left = left->next;
		}
		else {
			//�ұ�С
			head->next = right;
			head = head->next;
			right = right->next;
		}
	}
	//ʣ�µ����
	while (left) {
		head->next = left;
		head = head->next;
		left = left->next;
	}
	//ʣ�µ��ұ�
	while (right) {
		head->next = right;
		head = head->next;
		right = right->next;
	}
	return res->next;
}
/// <summary>
/// �鲢����������������ҳ��м��
/// </summary>
/// <param name="infoHead">������Ϣ����ͷָ��</param>
/// <returns></returns>
info * sortList(info *infoHead) {
	
	if (infoHead == NULL)//Ϊ��ֱ���˳�
		return NULL;

	if (!infoHead->next)
		return infoHead;//���ֻ��һ��ͷָ�����ͷ�ڵ㵫û�к��������ݽڵ㣬��ֱ�ӷ���

	info* res = (info*)malloc(sizeof(info));

	if (res == NULL)//�������ʧ��
	{
		cout << "�ռ䲻�����ʧ��" << endl;
		exit(1);
	}

	info* slow = infoHead;
	info* fast = infoHead;
	info* sign = NULL;
	//����ָ���ҵ���������м�ڵ�
	while (fast && fast->next) {
		sign = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	sign->next = NULL;

	//���еݹ�
	info* left = sortList(infoHead);
	info* right = sortList(slow);
	return mergeSort(left, right);	
}