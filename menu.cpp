#include "demo.h"
//#include "demo1.cpp"
info* Head;//���������ͷ�ڵ�
char name[30];
info* t;
/// <summary>
/// ���˵�
/// </summary>
void menu() {

	initInfo(Head);//��ʼ����Ϣ��
	readFile(Head);//���洢�ļ�¼����
	int num;
	while (1) {
		consoleClear();//����
		cout << "========== ���˵� ==========" << endl;
		cout << "1. �½���ϵ��" << endl;
		cout << "2. ������ϵ��" << endl;
		cout << "3. �޸���ϵ��" << endl;
		cout << "4. ɾ����ϵ��" << endl;
		cout << "5. ��ʾ������ϵ��" << endl;
		cout << "6. �˳�ϵͳ" << endl << endl;
		cout << "7. �ֶ�д�루���棩" << endl << endl;
		cout << "8. �ֶ���ȡ��׷�ӣ�" << endl << endl;
		cout << "��������Ž����Ӧ�Ĺ���" << endl;
		cin >> num;
		switch (num) {
		case 1:

			consoleClear();//����

			createInfo(Head);
			consoleClear();//����
			cout << "�½��ɹ������ڻص����˵�..." << endl;
			Delay(1000);
			consoleClear();//����
			//cout << "�½�" << endl;
			break;
		case 2:

			consoleClear();//����
			cout << "��������ϵ�˵�����" << endl;
			cin >> name;
			t = lookup(Head, name);
			if (t == NULL) {
				cout << "���޴���" << endl;
			}
			else {
				cout << "������" << t->name << "  �绰���룺" << t->phoneNumber << endl;
			}

			cout << "������Ϣ��ʾ��ϣ����س����ɻص����˵�" << endl;
			getchar();//����ö�һ��������ǰ������˿ո�
			getchar();
			consoleClear();//����

			//cout << "����" << endl;
			break;
		case 3:
			consoleClear();//����
			cout << "��������ϵ�˵�����" << endl;
			cin >> name;
			t = lookup(Head, name);
			if (t == NULL) {
				cout << "���޴���" << endl;
				cout << "�û��س����ɷ������˵�" << endl;
				getchar();//����ö�һ��������ǰ������˿ո�
				getchar();
				consoleClear();//����
				break;
			}
			else {
				printInfoNode(t);
			}
			cout << "ȷ��Ҫ�Ե�ǰ��ϵ�˵���Ϣ�����޸���y/n" << endl;
			if (confirmOperation()) {
				modifyPhoneNumber(t);
			}
			else{
				cout << "��ȡ���޸Ĳ������� �س� �Է������˵�" << endl;
			}
			getchar();//����ö�һ��������ǰ������˿ո�
			getchar();
			consoleClear();//����
			//cout << "�޸�" << endl;
			break;
		case 4:
			consoleClear();//����
			cout << "��������ϵ�˵�����" << endl;
			cin >> name;
			t = lookup_previous(Head, name);
			if (t == NULL) {
				cout << "���޴���" << endl;
				cout << "�û��س����ɷ������˵�" << endl;
				getchar();//����ö�һ��������ǰ������˿ո�
				getchar();
				consoleClear();//����
				break;
			}
			else {
				printInfoNode(t->next);////��Ϊɾ����ʱ��Ҫ���ҵ���һ���ڵ�ĵ�ַ�������ʾ��ʱ����Ҫ��һ��
			}
			cout << "ȷ��Ҫ�Ե�ǰ��ϵ�˵���Ϣ����ɾ����y/n";
			if (confirmOperation()) {
				deleteInfoNode(t);
				cout << "ɾ���ɹ����� �س� �Է������˵�" << endl;
			}
			else {
				cout << "��ȡ��ɾ���������� �س� �Է������˵�" << endl;
			}
			getchar();//����ö�һ��������ǰ������˿ո�
			getchar();
			consoleClear();//����
			
			//cout << "ɾ��" << endl;
			break;
		case 5:
			consoleClear();//����
			printInfo(Head);

			cout << "������Ϣ��ʾ��ϣ����س����ɻص����˵�" << endl;
			getchar();//����ö�һ��������ǰ������˿ո�
			getchar();
			consoleClear();//����

			//cout << "��ʾ" << endl;
			break;
		case 6:
			writeFile(Head);//�˳�֮ǰ���ļ�����д��
			cout << "�˳�" << endl;
			return;
			break;
		case 7:
			cout << "ȷ��Ҫд����y/n" << endl;
			if (confirmOperation()) {
				writeFile(Head);
				cout << "�ѳɹ�д�룬�� �س� ���ɷ������˵�" << endl;
			}
			else{
				cout << "��ȡ��д�룬�� �س� ���ɷ������˵�" << endl;
			}
			break;
		case 8:
			cout << "ȷ��Ҫ������׷����y/n" << endl;
			if (confirmOperation()) {
				
				writeFile(Head);
				cout << "�ѳɹ�д�룬�� �س� ���ɷ������˵�" << endl;
			}
			else {
				cout << "��ȡ��д�룬�� �س� ���ɷ������˵�" << endl;
			}
			break;

			readFile(Head);
		default:
			cout << "�������Ϣ��������������" << endl;
		}
	}
}

