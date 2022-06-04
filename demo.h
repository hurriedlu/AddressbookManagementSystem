#ifndef DEMOHEADER
#define DEMOHEADER

#include <iostream>
#include <ctime>//�����ӳ�����
using namespace std;

typedef struct information {
	char name[30];
	char phoneNumber[12];
	struct information * next;
}info;


//
void menu();//���˵�
void initInfo(info*& pHead);//��ʼ����Ϣ
info* getTailNode(info* pHead);//��ȡβ�ڵ�
void createInfo(info*& pHead);//β�巨�����½ڵ�
void printInfo(const info* pHead);//���������Ϣ
void consoleClear();//������ڿ���̨��ʾ����Ϣ
void Delay(int time);//�ȴ�����
info* sortList(info* infoHead);//�鲢��������������Ҫ��������ô˳���
info* mergeSort(info* left, info* right);//�鲢����������
#endif // !DEMOHEADER

