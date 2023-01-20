#include <iostream>
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;
int main()
{
    WorkerManager wm; // 实例化管理者对象
    int choice = 0;   // 用来存储用户的选项
    while (true)
    {
        wm.Show_Menu(); // 调用显示菜单成员函数
        cout << "请输入您的选择：" << endl;
        cin >> choice; // 接受用户的选项
        switch (choice)
        {
        case 0: // 退出系统
            wm.ExitSystem();
            break;
        case 1: // 增加职工
            wm.Add_Emp();
            break;
        case 2: // 显示职工
            break;
        case 3: // 删除职工
            break;
        case 4: // 修改职工
            break;
        case 5: // 查找职工
            break;
        case 6: // 排序职工
            break;
        case 7: // 清空文档
            break;
        default:
            system("cls");
            break;
        }
    }
    system("pause");
    return 0;
}