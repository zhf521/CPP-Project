#pragma once        // 防止头文件重复包含
#include <iostream> //包含输入输出流头文件
#include "worker.h"
#include "manager.h"
#include "employee.h"
#include "boss.h"
#include <fstream>

#define FILENAME "empFile.txt"
using namespace std; // 使用标准命名空间

class WorkerManager
{
public:
    // 构造函数
    WorkerManager();
    // 展示菜单
    void Show_Menu();
    // 退出系统
    void ExitSystem();
    // 记录职工人数
    int m_EmpNum;
    // 职工数组指针
    Worker **m_EmpArray;
    // 添加职工
    void Add_Emp();
    // 保存文件
    void save();
    // 判断文件是否为空 标志
    bool m_FileIsEmpty;
    // 统计文件中人数
    int get_EmpNum();
    // 初始化员工
    void init_Emp();
    // 显示员工
    void show_Emp();
    //删除员工
    void del_Emp();
    //判断员工是否存在，如果存在返回职工所在数组中位置，不存在返回-1
    int isExist(int id);
    //修改职工
    void mod_Emp();
    // 析构函数
    ~WorkerManager();
};