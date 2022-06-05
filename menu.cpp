#include "demo.h"
//#include "demo1.cpp"
info* Head;//整个链表的头节点
char name[30];
info* t;
/// <summary>
/// 主菜单
/// </summary>
void menu() {

	initInfo(Head);//初始化信息链
	readFile(Head);//将存储的记录读回
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
		cout << "7. 手动写入（保存）" << endl << endl;
		cout << "8. 手动读取（追加）" << endl << endl;
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

			consoleClear();//清屏
			cout << "请输入联系人的姓名" << endl;
			cin >> name;
			t = lookup(Head, name);
			if (t == NULL) {
				cout << "查无此人" << endl;
			}
			else {
				cout << "姓名：" << t->name << "  电话号码：" << t->phoneNumber << endl;
			}

			cout << "所有信息显示完毕，按回车即可回到主菜单" << endl;
			getchar();//必须得多一个，可能前面残留了空格？
			getchar();
			consoleClear();//清屏

			//cout << "查找" << endl;
			break;
		case 3:
			consoleClear();//清屏
			cout << "请输入联系人的姓名" << endl;
			cin >> name;
			t = lookup(Head, name);
			if (t == NULL) {
				cout << "查无此人" << endl;
				cout << "敲击回车即可返回主菜单" << endl;
				getchar();//必须得多一个，可能前面残留了空格？
				getchar();
				consoleClear();//清屏
				break;
			}
			else {
				printInfoNode(t);
			}
			cout << "确定要对当前联系人的信息进行修改吗？y/n" << endl;
			if (confirmOperation()) {
				modifyPhoneNumber(t);
			}
			else{
				cout << "已取消修改操作，按 回车 以返回主菜单" << endl;
			}
			getchar();//必须得多一个，可能前面残留了空格？
			getchar();
			consoleClear();//清屏
			//cout << "修改" << endl;
			break;
		case 4:
			consoleClear();//清屏
			cout << "请输入联系人的姓名" << endl;
			cin >> name;
			t = lookup_previous(Head, name);
			if (t == NULL) {
				cout << "查无此人" << endl;
				cout << "敲击回车即可返回主菜单" << endl;
				getchar();//必须得多一个，可能前面残留了空格？
				getchar();
				consoleClear();//清屏
				break;
			}
			else {
				printInfoNode(t->next);////因为删除的时候要查找到上一个节点的地址，因此显示的时候需要跳一下
			}
			cout << "确定要对当前联系人的信息进行删除吗？y/n";
			if (confirmOperation()) {
				deleteInfoNode(t);
				cout << "删除成功，按 回车 以返回主菜单" << endl;
			}
			else {
				cout << "已取消删除操作，按 回车 以返回主菜单" << endl;
			}
			getchar();//必须得多一个，可能前面残留了空格？
			getchar();
			consoleClear();//清屏
			
			//cout << "删除" << endl;
			break;
		case 5:
			consoleClear();//清屏
			printInfo(Head);

			cout << "所有信息显示完毕，按回车即可回到主菜单" << endl;
			getchar();//必须得多一个，可能前面残留了空格？
			getchar();
			consoleClear();//清屏

			//cout << "显示" << endl;
			break;
		case 6:
			writeFile(Head);//退出之前对文件进行写入
			cout << "退出" << endl;
			return;
			break;
		case 7:
			cout << "确认要写入吗？y/n" << endl;
			if (confirmOperation()) {
				writeFile(Head);
				cout << "已成功写入，按 回车 即可返回主菜单" << endl;
			}
			else{
				cout << "已取消写入，按 回车 即可返回主菜单" << endl;
			}
			break;
		case 8:
			cout << "确认要将数据追加吗？y/n" << endl;
			if (confirmOperation()) {
				
				writeFile(Head);
				cout << "已成功写入，按 回车 即可返回主菜单" << endl;
			}
			else {
				cout << "已取消写入，按 回车 即可返回主菜单" << endl;
			}
			break;

			readFile(Head);
		default:
			cout << "输入的信息有误，请重新输入" << endl;
		}
	}
}

