#include "demo.h"

char server_name[30];

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
	pHead = sort_message_order(pHead);
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


//�µĹ鲢������������

/// <summary>
/// ��������򷽷�
/// </summary>
/// <param name="head">ͷָ��</param>
/// <returns>������ɺ��ͷָ��</returns>
info* sort_message_order(info* head) //����  ������������˳��

{
	info* Back, * pointer; //pָ��ָ���µĽڵ� backָ��ָ�������β�ڵ�
	info  temp; // ����ṹ��student����,typedefҲ���Զ���Ľṹ�����
	Back = head->next;
	pointer = head->next; //����ͷ��� ָ����һ���ڵ� ͷ�����û��ѧ����Ϣ 
	while (Back != NULL) //���β�ڵ㲻Ϊ�� ��һֱ������ȥ
	{
		while (pointer->next != NULL) //���ָ���¿��ٵĽ�㲻Ϊ�վ�һֱ������ȥ
		{
			pointer = pointer->next; //ָ����һ���¿��ٵĽ��
			if (strcmp(Back->name, pointer->name) > 0)  //���back->ID����pointer->ID�ͷ��ش���0��ֵ���������ǰ��� �����
			{
				strcpy(temp.phoneNumber, Back->phoneNumber);
				strcpy(temp.name, Back->name);  //��β�ڵ�ֵ��ֵ����ʱtemp�ṹ�����


				strcpy(Back->phoneNumber, pointer->phoneNumber);
				strcpy(Back->name, pointer->name); //��ָ����½ڵ� ��β�ڵ㽻�� λ��


				strcpy(pointer->phoneNumber, temp.phoneNumber);
				strcpy(pointer->name, temp.name);//����ʱtemp�ṹ�������ֵ��ָ��Ľṹ�����

			}
		}
		Back = Back->next; //ָ����һ��β�ڵ�
		pointer = Back;  //ָ��β�ڵ�
	}
	return head;  //����ͷ���
}

/// <summary>
/// �����������в��ң������ҵ��Ľڵ����һ����ַ
/// </summary>
/// <param name="pHead">ͷ�ڵ�</param>
/// <param name="key">�����ؼ���</param>
/// <returns>�ýڵ����һ���ڵ�ĵ�ַ</returns>
info* lookup_previous(const info* pHead,char key[]) {
	if (pHead == NULL)
		return NULL;
	//pHead = pHead->next;//����ͷ�ڵ�
	info *tmp = NULL;//����ҵ��˽ڵ�ͽ���ַ����
	while (pHead->next) {		
		if (strcmp(key, pHead->next->name) == 0)//����ؼ��ֺ�������ȫ��ȣ���֤���ҵ���
		{
			tmp = (info*)pHead;
			break;
		}
		pHead = pHead->next;
	}

	return tmp;
}

/// <summary>
/// ����������Ϊ�ؼ��ֽ��в���
/// </summary>
/// <param name="pHead">��Ϣ����ͷ�ڵ�</param>
/// <param name="key">�ؼ���</param>
/// <returns>��Ӧ�ڵ�ĵ�ַ</returns>
info* lookup(const info* pHead, char key[]) {
	if (pHead == NULL)
		return NULL;
	pHead = pHead->next;//����ͷ�ڵ�
	info* tmp = NULL;//����ҵ��˽ڵ�ͽ���ַ����
	while (pHead) {
		if (strcmp(key, pHead->name) == 0)//����ؼ��ֺ�������ȫ��ȣ���֤���ҵ���
		{
			tmp = (info*)pHead;
		}
		pHead = pHead->next;
	}
	return tmp;
}

/// <summary>
/// ����Ϣ���е�ĳһ���ڵ���е绰������޸�
/// </summary>
/// <param name="p">Ҫ�޸ĵĽڵ��ַ</param>
void modifyPhoneNumber(info* p) {
	cout << "������ "<<p->name<<" ���µ绰��" << endl;
	cin >> server_name;
	//scanf_s("%s", server_name, 11);
	strcpy_s(p->phoneNumber, sizeof(p->phoneNumber)/sizeof(p->phoneNumber[0]), server_name);
	cout << endl << endl << "�޸ĳɹ�" << endl << endl;
	cout << "�޸ĺ����ϢΪ��" << endl;
	printInfoNode(p);
}

/// <summary>
/// ���ָ���ڵ����Ϣ
/// </summary>
/// <param name="p">ָ���ڵ�ĵ�ַ</param>
void printInfoNode(const info* p) {
	cout << "����=" << p->name << "  �绰����=" << p->phoneNumber << endl;
}

/// <summary>
/// ɾ���ڵ�
/// </summary>
/// <param name="p">Ҫɾ���Ľڵ��ǰһ���ڵ��ַ</param>
void deleteInfoNode(info* p) {
	info* t = p->next;
	p->next = p->next->next;//�޳�ĳһ�ڵ�
	free(t);//�ͷŵ�ɾ���Ŀռ�
}

/// <summary>
/// ��ȡ���ڵ��ļ�
/// </summary>
/// <param name="pHead"></param>
void readFile(info *pHead) {
	bool flag = true;//Ĭ��Ϊβ�����룬��Ҫ���򣬷���Ϊ��ʼ��ʱ����,����Ҫ����  
	if (pHead->next == NULL) {//���ͷ�ڵ����һ��ָ����NULL����֤�������ڳ�ʼ�Ĺ����е��õ�
		flag = false;
	}
	else {//������û�ȡβ�ڵ�ĺ�������β������Ȼ������
		pHead = getTailNode(pHead);
	}

	info t,*p,*q = pHead;//��ʱ�ڵ㣬��ʱ�ڵ�ָ�룬ͷָ�룬������
	ifstream fin("d:\\data.ini");   //���ļ�׼����ȡ
	if (!fin)              // �����ȡʧ�ܣ���ӡfail
	{
		cerr << "fail" << endl;
		exit(1);
	}

	fin >> t.name >> t.phoneNumber;//��ȡ���������ݴ洢��ʱ�ڵ�
	while (t.name[0] != '#' && t.phoneNumber[0] != '#') {//ֻҪû����#����֤��û������

		//�����ڵ�
		p = (info*)malloc(sizeof(info));
		if (p == NULL) {
			cout << "�ռ䲻��" << endl;
			exit(1);
		}

		//�������ݵ��µĽڵ�
		strcpy_s(p->name, sizeof(p->name) / sizeof(p->name[0]), t.name);
		strcpy_s(p->phoneNumber, sizeof(p->phoneNumber) / sizeof(p->phoneNumber[0]), t.phoneNumber);

		//���ڵ����ӵ���������β��
		p->next = pHead->next;
		pHead->next = p;

		fin >> t.name >> t.phoneNumber;//��ȡ��һ����Ϣ
	}
	
	if (flag)//���Ϊtrue��֤����׷�ӵģ�����һ������
	{
		pHead = sort_message_order(q);//��������Ϣ����������
	}
	
	fin.close();//��ȡ��ɹر�����
}


/// <summary>
/// ����Ϣ��д�뵽�ļ�
/// </summary>
/// <param name="pHead"></param>
void writeFile(info* pHead) {
	/*info t;
	strcpy_s(t.name, sizeof(t.name) / sizeof(t.name[0]), "hello");
	strcpy_s(t.phoneNumber, sizeof(t.phoneNumber) / sizeof(t.phoneNumber[0]), "world");*/

	ofstream fout("D:\\data.ini");//���ļ�
	pHead = pHead->next;//����ͷ�ڵ�
	while (pHead) {
		fout << pHead->name << " " << pHead->phoneNumber << endl;//��������Ϣ�������
		pHead = pHead->next;
	}	

	fout << "### ###" << endl;//���Ͻ�����ʶ��
	fout.close();//д���ر�����
}

/// <summary>
/// ����ȷ���жϣ��������y��Y����true������false
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