#include <iostream>
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;
int main()
{
    WorkerManager wm; // ʵ���������߶���
    int choice = 0;   // �����洢�û���ѡ��
    while (true)
    {
        wm.Show_Menu(); // ������ʾ�˵���Ա����
        cout << "����������ѡ��" << endl;
        cin >> choice; // �����û���ѡ��
        switch (choice)
        {
        case 0: // �˳�ϵͳ
            wm.ExitSystem();
            break;
        case 1: // ����ְ��
            wm.Add_Emp();
            break;
        case 2: // ��ʾְ��
            wm.show_Emp();
            break;
        case 3: // ɾ��ְ��
            wm.del_Emp();
            break;
        case 4: // �޸�ְ��
            wm.mod_Emp();
            break;
        case 5: // ����ְ��
            wm.find_Emp();
            break;
        case 6: // ����ְ��
            wm.sort_Emp();
            break;
        case 7: // ����ĵ�
            wm.clean_File();
            break;
        default:
            system("cls");
            break;
        }
    }
    system("pause");
    return 0;
}