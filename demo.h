#ifndef DEMOHEADER
#define DEMOHEADER

#include <iostream>
#include <fstream>//���ڶ�д�ļ�
#include <ctime>//�����ӳ�����
using namespace std;

typedef struct information {
	char name[30];
	char phoneNumber[12];
	struct information* next;
}info;




void menu();//���˵�
void initInfo(info*& pHead);//��ʼ����Ϣ
info* getTailNode(info* pHead);//��ȡβ�ڵ�
void createInfo(info*& pHead);//β�巨�����½ڵ�
void printInfo(const info* pHead);//���������Ϣ
void consoleClear();//������ڿ���̨��ʾ����Ϣ
void Delay(int time);//�ȴ�����
info* sortList(info* infoHead);//�鲢��������������Ҫ��������ô˳���
info* mergeSort(info* left, info* right);//�鲢����������

info* sort_message_order(info* head); //����  ����ID˳��

info* lookup(const info* pHead, char key[]);//��������Ϊ�ؼ��ֽ��в���
void modifyPhoneNumber(info* p);//�޸�ָ���ڵ�ĵ绰���룬������info* lookup(const info* pHead, char key[])����
void printInfoNode(const info* p);//��ӡָ���ڵ����Ϣ
info* lookup_previous(const info* pHead, char key[]);/// �����������в��ң������ҵ��Ľڵ����һ����ַ
void deleteInfoNode(info* p);//ɾ��ָ���Ľڵ㣬������info* lookup_previous(const info* pHead,char key[])����

void readFile(info* pHead);//��ȡ�ļ�
void writeFile(info* pHead);//�������ݵ��ļ�

bool confirmOperation();//ȷ�ϲ���


#endif // !DEMOHEADER

