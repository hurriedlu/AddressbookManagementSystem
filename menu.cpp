#include "demo.h"
//#include "demo1.cpp"
info* Head;//整个链表的头节点
/// <summary>
/// 主菜单
/// </summary>
void menu() {

	initInfo(Head);//初始化信息链

	int num;
	while (1) {
		consoleClear();//清屏
		cout << "========== 主菜单 ==========" << endl;
		cout << "1. 新建联系人" << endl;
		cout << "2. 查找联系人" << endl;
		cout << "3. 修改联系人" << endl;
		cout << "4. 删除联系人" << endl;
		cout << "5. 显示所有联系人" << endl;
		cout << "6. 退出系统" << endl << endl;
		cout << "7. 手动排序" << endl << endl;
		cout << "请输入序号进入对应的功能" << endl;
		cin >> num;
		switch (num) {
		case 1:

			consoleClear();//清屏

			createInfo(Head);
			consoleClear();//清屏
			cout << "新建成功，正在回到主菜单..." << endl;
			Delay(1000);
			consoleClear();//清屏
			//cout << "新建" << endl;
			break;
		case 2:
			cout << "查找" << endl;
			break;
		case 3:
			cout << "修改" << endl;
			break;
		case 4:
			cout << "删除" << endl;
			break;
		case 5:
			consoleClear();//清屏
			printInfo(Head);

			cout << "所有信息显示完毕，按任意键即可回到主菜单" << endl;
			getchar();//必须得多一个，可能前面残留了空格？
			getchar();
			consoleClear();//清屏
			
			//cout << "显示" << endl;
			break;
		case 6:
			cout << "退出" << endl;
			return;
			break;
		case 7:
			consoleClear();//清屏
			sortList(Head);
			cout << "所有信息排序完毕，按任意键退出" << endl;
			getchar();//必须得多一个，可能前面残留了空格？
			getchar();
			consoleClear();//清屏
			//cout << "显示" << endl;
			break;
		default:
			cout << "输入的信息有误，请重新输入" << endl;
		}
	}	
}

