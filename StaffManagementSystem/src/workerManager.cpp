#include "workerManager.h"
WorkerManager::WorkerManager() // 构造函数
{
    ifstream ifs;
    ifs.open(FILENAME, ios ::in); // 读文件
    // 1.文件不存在
    if (!ifs.is_open())
    {
        cout << "文件不存在" << endl;
        // 初始化属性
        // 初始化记录人数
        this->m_EmpNum = 0;
        // 初始化数组指针
        this->m_EmpArray = NULL;
        // 初始化文件是否为空
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }
    // 2.文件存在，但是数据为空
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        // 文件为空
        cout << "文件为空！" << endl;
        //  初始化记录人数
        this->m_EmpNum = 0;
        // 初始化数组指针
        this->m_EmpArray = NULL;
        // 初始化文件是否为空
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }
    // 3.文件存在，并且记录数据
    int num = this->get_EmpNum();
    // cout << "职工人数为：" << num << endl;
    this->m_EmpNum = num;
    this->m_FileIsEmpty = false;

    // 开辟空间
    this->m_EmpArray = new Worker *[this->m_EmpNum];
    // 将文件中的数据，存在数组中
    this->init_Emp();

    ////测试代码
    // for (int i = 0; i < this->m_EmpNum; i++)
    // {
    //     cout << "职工编号：" << this->m_EmpArray[i]->m_Id << "姓名：" << this->m_EmpArray[i]->m_Name << "部门编号：" << this->m_EmpArray[i]->m_DeptId << endl;
    // }
}
// 调用展示菜单
void WorkerManager::Show_Menu()
{
    cout << "********************************************" << endl;
    cout << "*********  欢迎使用职工管理系统！  *********" << endl;
    cout << "*************  0.退出管理程序  *************" << endl;
    cout << "*************  1.增加职工信息  *************" << endl;
    cout << "*************  2.显示职工信息  *************" << endl;
    cout << "*************  3.删除离职职工  *************" << endl;
    cout << "*************  4.修改离职职工  *************" << endl;
    cout << "*************  5.查找职工信息  *************" << endl;
    cout << "*************  6.按照编号排序  *************" << endl;
    cout << "*************  7.清空所有文档  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}
// 退出系统
void WorkerManager::ExitSystem()
{
    cout << "欢迎下次使用" << endl;
    system("pause");
    exit(0); // 退出程序
}
// 添加职工
void WorkerManager::Add_Emp()
{
    cout << "请输入添加职工数量：" << endl;
    int addNum = 0; // 保存用户的输入数量
    cin >> addNum;
    if (addNum > 0)
    {
        // 添加
        // 计算添加新空间大小
        int newSize = this->m_EmpNum + addNum; // 新空间人数=原来记录人数+新增人数
        // 开辟新空间
        Worker **newSpace = new Worker *[newSize];
        // 将原来空间下数据，拷贝到新空间下
        if (this->m_EmpArray != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                newSpace[i] = this->m_EmpArray[i];
            }
        }
        // 批量添加新数据
        for (int i = 0; i < addNum; i++)
        {
            int id;      // 职工编号
            string name; // 职工姓名
            int dSelect; // 部门选择
            cout << "请输入第" << i + 1 << "个新职工的编号:" << endl;
            cin >> id;
            cout << "请输入第" << i + 1 << "个新职工的姓名:" << endl;
            cin >> name;
            cout << "请输入该职工岗位:" << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cin >> dSelect;
            Worker *worker = NULL;
            switch (dSelect)
            {
            case 1:
                worker = new Employee(id, name, 1);
                break;
            case 2:
                worker = new Manager(id, name, 2);
                break;
            case 3:
                worker = new Boss(id, name, 3);
                break;
            default:
                break;
            }
            // 将创建职工职责，保存到数组中
            newSpace[this->m_EmpNum + i] = worker;
        }
        // 释放原有的空间
        delete[] this->m_EmpArray;
        // 更改新空间的指向
        this->m_EmpArray = newSpace;
        // 更新新的职工人数
        this->m_EmpNum = newSize;
        // 更新职工不为空的标志
        this->m_FileIsEmpty = false;
        // 提示添加成功
        cout << "成功添加" << addNum << "名新职工!" << endl;
        // 保存数据到文件中
        this->save();
    }
    else
    {
        cout << "输入数据有误!" << endl;
    }
    // 按任意键后，清屏回到上级目录
    system("pause");
    system("cls");
}
// 保存文件
void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out); // 用输出的方式打开文件--写文件
    // 将每个人数据写入到文件中
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        ofs << this->m_EmpArray[i]->m_Id << " " << this->m_EmpArray[i]->m_Name << " " << this->m_EmpArray[i]->m_DeptId << endl;
    }
    // 关闭文件
    ofs.close();
}
// 统计文件中人数
int WorkerManager::get_EmpNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in); // 打开文件 读
    int id;
    string name;
    int dId;
    int num = 0;
    while (ifs >> id && ifs >> name && ifs >> dId)
    {

        // 统计人数变量
        num++;
    }
    return num;
}
// 初始化员工
void WorkerManager::init_Emp()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int dID;
    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> dID)
    {
        Worker *worker = NULL;
        if (dID == 1) // 普通职工
        {
            worker = new Employee(id, name, dID);
        }
        else if (dID == 2) // 经理
        {
            worker = new Manager(id, name, dID);
        }
        else // 老板
        {
            worker = new Boss(id, name, dID);
        }
        this->m_EmpArray[index] = worker;
        index++;
    }
    // 关闭文件
    ifs.close();
}
// 显示员工
void WorkerManager::show_Emp()
{
    // 判断文件是否为空
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
    }
    else
    {
        for (int i = 0; i < m_EmpNum; i++)
        {
            // 利用多态调用程序接口
            this->m_EmpArray[i]->showInfo();
        }
    }
    // 按任意键后清屏
    system("pause");
    system("cls");
}
WorkerManager::~WorkerManager()
{
    if (this->m_EmpArray != NULL)
    {
        delete[] this->m_EmpArray;
        this->m_EmpArray = NULL;
    }
}