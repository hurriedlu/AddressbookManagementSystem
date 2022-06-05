#ifndef DEMOHEADER
#define DEMOHEADER

#include <iostream>
#include <fstream>//用于读写文件
#include <ctime>//用于延迟清屏
using namespace std;

typedef struct information {
	char name[30];
	char phoneNumber[12];
	struct information* next;
}info;




void menu();//主菜单
void initInfo(info*& pHead);//初始化信息
info* getTailNode(info* pHead);//获取尾节点
void createInfo(info*& pHead);//尾插法创建新节点
void printInfo(const info* pHead);//输出所有信息
void consoleClear();//清除已在控制台显示的信息
void Delay(int time);//等待函数
info* sortList(info* infoHead);//归并排序主程序。如需要排序则调用此程序
info* mergeSort(info* left, info* right);//归并排序辅助程序

info* sort_message_order(info* head); //升序  按照ID顺序

info* lookup(const info* pHead, char key[]);//以姓名作为关键字进行查找
void modifyPhoneNumber(info* p);//修改指定节点的电话号码，依赖于info* lookup(const info* pHead, char key[])方法
void printInfoNode(const info* p);//打印指定节点的信息
info* lookup_previous(const info* pHead, char key[]);/// 按照姓名进行查找，返回找到的节点的上一个地址
void deleteInfoNode(info* p);//删除指定的节点，依赖于info* lookup_previous(const info* pHead,char key[])方法

void readFile(info* pHead);//读取文件
void writeFile(info* pHead);//保存数据到文件

bool confirmOperation();//确认操作


#endif // !DEMOHEADER

