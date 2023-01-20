// 经理文件
#pragma once
#include <iostream>
#include "worker.h"
using namespace std;

// 经理类
class Manager : public Worker
{
public:
    // 构造函数
    Manager(int id, string name, int dId);
    // 显示个人信息
    virtual void showInfo(); // 这里virtual可以删除也可以不删
    // 获取岗位名称
    virtual string getDeptName(); // 这里virtual可以删除也可以不删
};