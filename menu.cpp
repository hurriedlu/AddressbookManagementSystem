#include "demo.h"
//#include "demo1.cpp"
info* Head;//���������ͷ�ڵ�
/// <summary>
/// ���˵�
/// </summary>
void menu() {

	initInfo(Head);//��ʼ����Ϣ��

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
		cout << "7. �ֶ�����" << endl << endl;
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
			cout << "����" << endl;
			break;
		case 3:
			cout << "�޸�" << endl;
			break;
		case 4:
			cout << "ɾ��" << endl;
			break;
		case 5:
			consoleClear();//����
			printInfo(Head);

			cout << "������Ϣ��ʾ��ϣ�����������ɻص����˵�" << endl;
			getchar();//����ö�һ��������ǰ������˿ո�
			getchar();
			consoleClear();//����
			
			//cout << "��ʾ" << endl;
			break;
		case 6:
			cout << "�˳�" << endl;
			return;
			break;
		case 7:
			consoleClear();//����
			sortList(Head);
			cout << "������Ϣ������ϣ���������˳�" << endl;
			getchar();//����ö�һ��������ǰ������˿ո�
			getchar();
			consoleClear();//����
			//cout << "��ʾ" << endl;
			break;
		default:
			cout << "�������Ϣ��������������" << endl;
		}
	}	
}

