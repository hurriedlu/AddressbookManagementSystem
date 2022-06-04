#ifndef DEMOHEADER
#define DEMOHEADER

#include <iostream>
#include <ctime>//用于延迟清屏
using namespace std;

typedef struct information {
	char name[30];
	char phoneNumber[12];
	struct information * next;
}info;


//
void menu();//主菜单
void initInfo(info*& pHead);//初始化信息
info* getTailNode(info* pHead);//获取尾节点
void createInfo(info*& pHead);//尾插法创建新节点
void printInfo(const info* pHead);//输出所有信息
void consoleClear();//清除已在控制台显示的信息
void Delay(int time);//等待函数
info* sortList(info* infoHead);//归并排序主程序。如需要排序则调用此程序
info* mergeSort(info* left, info* right);//归并排序辅助程序
#endif // !DEMOHEADER

