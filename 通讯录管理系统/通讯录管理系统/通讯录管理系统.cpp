#include<iostream>
#include<string>

using namespace std;

#define MAX 1000


void printmenu() {
	cout << " ******* 通讯录管理系统 *******" << endl;
    cout << " ******   1.添加联系人  ******* " << endl;
	cout << " ******   2.显示联系人  ******* " << endl;
	cout << " ******   3.删除联系人  ******* " << endl;
	cout << " ******   4.查找联系人  ******* " << endl;
	cout << " ******   5.修改联系人  ******* " << endl;
	cout << " ******   6.清空联系人  ******* " << endl;
	cout << " ******   0.退出通讯录  ******* " << endl;
	cout << " ****************************** " << endl;
}

// 通讯录中联系人结构体
struct Person {
	string Name; //姓名
	string sex; //性别
	int age; //年龄
	string phone_number; //电话号码
	string address; //地址
};

// 通讯录结构体
struct PersonPhone {
	// 通讯录中保存的联系人数组
	struct Person personArray[MAX];
	// 通讯录中联系人个数
	int size;
};

//查询联系人的下标
int isExist(PersonPhone* p, string name)
{
	for (int i = 0; i < p->size; i++)
    {
        if (p->personArray[i].Name == name)
        {
            return i;
        }
    }
    return -1;
}

// 添加联系人操作
void AddPerson(PersonPhone* p)
{
	//判断是否有空间
	if (p->size == MAX)
	{
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else
	{
		string name;
		// 添加联系人姓名
		cout << "请输入姓名：" << endl;
		cin >> name;
		p->personArray[p->size].Name = name;
		
		while (true)
		{
			// 添加联系人性别
			int sex;
			cout << "请选择性别：" << endl;
			cout << "1.男" << endl;
			cout << "2.女" << endl;
			cin >> sex;
			if (sex == 1)
			{
				p->personArray[p->size].sex = "男";
				break;
			}
			else if (sex == 2)
			{
				p->personArray[p->size].sex = "女";
				break;
			}
			else
			{
				cout << "输入错误，请重新输入" << endl;
			}
		}

		// 添加联系人年龄
		int age = 0;
		cout << "请输入年龄：" << endl;
		cin >> age;
		p->personArray[p->size].age = age;

		// 添加联系人电话号码
		string phone_number;
		while (true)
		{
			cout << "请输入电话号码：" << endl;
			cin >> phone_number;
			if (phone_number.length() == 11)
			{
				p->personArray[p->size].phone_number = phone_number;
				break;
			}
			else
			{
				cout << "电话号码错误，请重新输入" << endl;
			}
		}

		// 添加联系人地址
		string address;
		cout << "请输入地址：" << endl;
		cin >> address;
		p->personArray[p->size].address = address;
        cout << endl;

		// 通讯录中联系人个数加一
		p->size++;

		cout << "添加成功" << endl;

		system("pause");		//请按任意键继续

		// 清屏
		system("cls");
	}
}

// 显示联系人操作
void PrintPerson(PersonPhone* p) {
	cout << "通讯录中联系人个数为： " << p->size << endl;
	//判断是否有联系人
	if (p->size == 0)
	{
		cout << "通讯录为空" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < p->size; i++)
		{
			cout << "姓名：" << p->personArray[i].Name << "\t";
			cout << "性别：" << p->personArray[i].sex << "\t";
			cout << "年龄：" << p->personArray[i].age << "\t";
			cout << "电话号码：" << p->personArray[i].phone_number << "\t";
			cout << "地址：" << p->personArray[i].address << endl;
		}
	}

	system("pause");

	system("cls");
}

// 删除联系人操作
void DeletePerson(PersonPhone* p) {
	cout << "请输入要删除的联系人姓名：" << endl;
	string name;
	cin >> name;

	int ret = isExist(p, name);
		//找到用户输入的名字
		if (ret!=-1)
		{
			cout << "找到该联系人" << endl;
			for (int j = ret; j < p->size - 1; j++)
			{
				p->personArray[j] = p->personArray[j + 1];
			}
			p->size--;
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "没有该联系人" << endl;
		}
	system("pause");
	system("cls");
}

// 查找联系人操作
void FindPerson(PersonPhone* p) {
	cout << "请输入要查找的联系人姓名：" << endl;
	string name;
	cin >> name;

	int ret = isExist(p, name);
		//判断是否有该联系人
		if (ret != -1)
		{
			cout<<"找到该联系人"<<endl;
			cout << "姓名：" << p->personArray[ret].Name << "\t";
            cout << "性别：" << p->personArray[ret].sex << "\t";
            cout << "年龄：" << p->personArray[ret].age << "\t";
            cout << "电话号码：" << p->personArray[ret].phone_number << "\t";
            cout << "地址：" << p->personArray[ret].address << endl;
		}

		else
		{
            cout << "没有该联系人" << endl;
		}


		system("pause");
        system("cls");
}

// 修改联系人操作
void ModifyPerson(PersonPhone* p) {
    cout << "请输入要修改的联系人的姓名：" << endl;
    string name;
    cin >> name;
	int ret = isExist(p, name);
    if (ret != -1)
    {
        cout << "请确定联系人的信息" << endl;
        cout << "姓名：" << p->personArray[ret].Name << "\t";
        cout << "性别：" << p->personArray[ret].sex << "\t";
        cout << "年龄：" << p->personArray[ret].age << "\t";
        cout << "电话号码：" << p->personArray[ret].phone_number << "\t";
        cout << "地址：" << p->personArray[ret].address << endl;
		system("pause");
		cout << "请选择要修改的内容" << endl;
            cout << "1.姓名" << "\t";
            cout << "2.性别" << "\t";
            cout << "3.年龄" << "\t";
            cout << "4.电话号码" << "\t";
            cout << "5.地址" << endl;
			int chose;
            cin >> chose;
			switch (chose)
			{
			case 1:
                cout << "请输入要修改的姓名：" << endl;
				cin>>p->personArray[ret].Name;
                cout << "修改成功" << endl;
				break;

			case 2:
				while (true)
				{
					// 添加联系人性别
					int sex;
					cout << "请选择性别：" << endl;
					cout << "1.男" << endl;
					cout << "2.女" << endl;
					cin >> sex;
					if (sex == 1)
					{
						p->personArray[ret].sex = "男";
                        cout << "修改成功" << endl;
						break;
					}
					else if (sex == 2)
					{
						p->personArray[ret].sex = "女";
                        cout << "修改成功" << endl;
						break;
					}
					else
					{
						cout << "输入错误，请重新输入" << endl;
					}
				}
                break;

            case 3:
                 cout << "请输入要修改的年龄：" << endl;
                 cin >> p->personArray[ret].age;
                 cout << "修改成功" << endl;
                 break;
			case 4:
                cout << "请输入要修改的电话号码：" << endl;
				while (true)
				{
					cin >> p->personArray[ret].phone_number;
					if (p->personArray[ret].phone_number.length() == 11)
					{
						cout << "修改成功" << endl;
						break;
					}
					else
					{
						cout << "电话号码错误，请重新输入" << endl;
					}
				}
                break;

            case 5:
                 cout << "请输入要修改的地址：" << endl;
                 cin >> p->personArray[ret].address;
                 cout << "修改成功" << endl;
                 break;

            default:
                 cout << "输入错误，请重新输入" << endl;
			}
    }
	else
	{
        cout << "没有该联系人" << endl;
	}
	system("pause");
    system("cls");

}

// 清空联系人操作
void ClearPerson(PersonPhone* p) {
	cout << "是否清空通讯录？" << endl;
	cout << "1.是" << endl;
	cout << "2.否" << endl;
	int chose;
	cin >> chose;
	cout<<"是否确定"<<endl;
    cout << "1.是" << endl;
    cout << "2.否" << endl;
    cin >> chose;
	if (chose == 1)
	{
		p->size = 0;
		cout << "通讯录已清空" << endl;
	}
	else
	{
		cout << "通讯录未清空" << endl;
	}
	system("pause");
	system("cls");
}

int main() {
	int chose = 0;
	// 通讯录结构体变量
    struct PersonPhone abs;
	//初始化通讯录中当前的人员个数
	abs.size = 0;

	while (true)
	{
		// 打印菜单
		printmenu();
		cin >> chose;
		switch (chose)
		{
		case 0: //退出通讯录
			cout << "退出通讯录" << endl;
			system("pause");
            return 0;
			break;

		case 1: // 添加联系人
			AddPerson(&abs);//根据传递通讯录变量地址改变值
				break;

		case 2: // 显示联系人
			PrintPerson(&abs);
			break;

		case 3: // 删除联系人
			DeletePerson(&abs);
			break;

		case 4: // 查找联系人
			FindPerson(&abs);
			break;

		case 5: //修改联系人
			ModifyPerson(&abs);
			break;

		case 6: // 清空联系人
			ClearPerson(&abs);
			break;

		default:
            cout << "输入错误，请重新输入" << endl;
			break;
		}
	}
	return 0;
}