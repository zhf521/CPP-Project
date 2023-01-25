#include "workerManager.h"
WorkerManager::WorkerManager() // ���캯��
{
    ifstream ifs;
    ifs.open(FILENAME, ios ::in); // ���ļ�
    // 1.�ļ�������
    if (!ifs.is_open())
    {
        cout << "�ļ�������" << endl;
        // ��ʼ������
        // ��ʼ����¼����
        this->m_EmpNum = 0;
        // ��ʼ������ָ��
        this->m_EmpArray = NULL;
        // ��ʼ���ļ��Ƿ�Ϊ��
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }
    // 2.�ļ����ڣ���������Ϊ��
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        // �ļ�Ϊ��
        cout << "�ļ�Ϊ�գ�" << endl;
        //  ��ʼ����¼����
        this->m_EmpNum = 0;
        // ��ʼ������ָ��
        this->m_EmpArray = NULL;
        // ��ʼ���ļ��Ƿ�Ϊ��
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }
    // 3.�ļ����ڣ����Ҽ�¼����
    int num = this->get_EmpNum();
    // cout << "ְ������Ϊ��" << num << endl;
    this->m_EmpNum = num;
    this->m_FileIsEmpty = false;

    // ���ٿռ�
    this->m_EmpArray = new Worker *[this->m_EmpNum];
    // ���ļ��е����ݣ�����������
    this->init_Emp();

    ////���Դ���
    // for (int i = 0; i < this->m_EmpNum; i++)
    // {
    //     cout << "ְ����ţ�" << this->m_EmpArray[i]->m_Id << "������" << this->m_EmpArray[i]->m_Name << "���ű�ţ�" << this->m_EmpArray[i]->m_DeptId << endl;
    // }
}
// ����չʾ�˵�
void WorkerManager::Show_Menu()
{
    cout << "********************************************" << endl;
    cout << "*********  ��ӭʹ��ְ������ϵͳ��  *********" << endl;
    cout << "*************  0.�˳��������  *************" << endl;
    cout << "*************  1.����ְ����Ϣ  *************" << endl;
    cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
    cout << "*************  3.ɾ����ְְ��  *************" << endl;
    cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
    cout << "*************  5.����ְ����Ϣ  *************" << endl;
    cout << "*************  6.���ձ������  *************" << endl;
    cout << "*************  7.��������ĵ�  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}
// �˳�ϵͳ
void WorkerManager::ExitSystem()
{
    cout << "��ӭ�´�ʹ��" << endl;
    system("pause");
    exit(0); // �˳�����
}
// ���ְ��
void WorkerManager::Add_Emp()
{
    cout << "���������ְ��������" << endl;
    int addNum = 0; // �����û�����������
    cin >> addNum;
    if (addNum > 0)
    {
        // ���
        // ��������¿ռ��С
        int newSize = this->m_EmpNum + addNum; // �¿ռ�����=ԭ����¼����+��������
        // �����¿ռ�
        Worker **newSpace = new Worker *[newSize];
        // ��ԭ���ռ������ݣ��������¿ռ���
        if (this->m_EmpArray != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                newSpace[i] = this->m_EmpArray[i];
            }
        }
        // �������������
        for (int i = 0; i < addNum; i++)
        {
            int id;      // ְ�����
            string name; // ְ������
            int dSelect; // ����ѡ��
            cout << "�������" << i + 1 << "����ְ���ı��:" << endl;
            cin >> id;
            cout << "�������" << i + 1 << "����ְ��������:" << endl;
            cin >> name;
            cout << "�������ְ����λ:" << endl;
            cout << "1����ְͨ��" << endl;
            cout << "2������" << endl;
            cout << "3���ϰ�" << endl;
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
            // ������ְ��ְ�𣬱��浽������
            newSpace[this->m_EmpNum + i] = worker;
        }
        // �ͷ�ԭ�еĿռ�
        delete[] this->m_EmpArray;
        // �����¿ռ��ָ��
        this->m_EmpArray = newSpace;
        // �����µ�ְ������
        this->m_EmpNum = newSize;
        // ����ְ����Ϊ�յı�־
        this->m_FileIsEmpty = false;
        // ��ʾ��ӳɹ�
        cout << "�ɹ����" << addNum << "����ְ��!" << endl;
        // �������ݵ��ļ���
        this->save();
    }
    else
    {
        cout << "������������!" << endl;
    }
    // ��������������ص��ϼ�Ŀ¼
    system("pause");
    system("cls");
}
// �����ļ�
void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out); // ������ķ�ʽ���ļ�--д�ļ�
    // ��ÿ��������д�뵽�ļ���
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        ofs << this->m_EmpArray[i]->m_Id << " " << this->m_EmpArray[i]->m_Name << " " << this->m_EmpArray[i]->m_DeptId << endl;
    }
    // �ر��ļ�
    ofs.close();
}
// ͳ���ļ�������
int WorkerManager::get_EmpNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in); // ���ļ� ��
    int id;
    string name;
    int dId;
    int num = 0;
    while (ifs >> id && ifs >> name && ifs >> dId)
    {

        // ͳ����������
        num++;
    }
    return num;
}
// ��ʼ��Ա��
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
        if (dID == 1) // ��ְͨ��
        {
            worker = new Employee(id, name, dID);
        }
        else if (dID == 2) // ����
        {
            worker = new Manager(id, name, dID);
        }
        else // �ϰ�
        {
            worker = new Boss(id, name, dID);
        }
        this->m_EmpArray[index] = worker;
        index++;
    }
    // �ر��ļ�
    ifs.close();
}
// ��ʾԱ��
void WorkerManager::show_Emp()
{
    // �ж��ļ��Ƿ�Ϊ��
    if (this->m_FileIsEmpty)
    {
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
    }
    else
    {
        for (int i = 0; i < m_EmpNum; i++)
        {
            // ���ö�̬���ó���ӿ�
            this->m_EmpArray[i]->showInfo();
        }
    }
    // �������������
    system("pause");
    system("cls");
}
// ɾ��Ա��
void WorkerManager::del_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
    }
    else
    {
        // ����ְ�����ɾ��
        cout << "��������Ҫɾ��ְ����ţ�" << endl;
        int id = 0;
        cin >> id;
        int index = this->isExist(id);
        if (index != -1) // ˵��ְ�����ڣ�����Ҫɾ����indexλ���ϵ�ְ��
        {
            // ����ǰ��
            for (int i = index; i < this->m_EmpNum - 1; i++)
            {
                this->m_EmpArray[i] = this->m_EmpArray[i + 1];
            }
            this->m_EmpNum--; // ���������м�¼��Ա����
            // ����ͬ�����µ��ļ���
            this->save();
            cout << "ɾ���ɹ���" << endl;
        }
        else
        {
            cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ����" << endl;
        }
    }
    // �����������
    system("pause");
    system("cls");
}
// �ж�Ա���Ƿ���ڣ�������ڷ���ְ������������λ�ã������ڷ���-1
int WorkerManager::isExist(int id)
{
    int index = -1;
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        if (this->m_EmpArray[i]->m_Id == id)
        {
            // �ҵ�ְ��
            index = i;
            break;
        }
    }
    return index;
}
// �޸�ְ��
void WorkerManager::mod_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
    }
    else
    {
        cout << "�������޸�ְ���ı�ţ�" << endl;
        int id;
        cin >> id;
        int ret = this->isExist(id);
        if (ret != -1)
        {
            // ���ҵ���ŵ�ְ��
            delete this->m_EmpArray[ret];
            int newId = 0;
            string newName = " ";
            int dSelect = 0;
            cout << "�鵽��" << id << "��ְ������������ְ���ţ�" << endl;
            cin >> newId;
            cout << "�������λ��" << endl;
            cout << "1����ְͨ��" << endl;
            cout << "2������" << endl;
            cout << "3���ϰ�" << endl;
            cin >> dSelect;
            Worker *worker = NULL;
            switch (dSelect)
            {
            case 1:
                worker = new Employee(newId, newName, dSelect);
                break;
            case 2:
                worker = new Manager(newId, newName, dSelect);
                break;
            case 3:
                worker = new Boss(newId, newName, dSelect);
                break;
            default:
                break;
            }
            // �������ݵ�������
            this->m_EmpArray[ret] = worker;
            cout << "�޸ĳɹ���" << endl;
            // ���浽�ļ���
            this->save();
        }
        else
        {
            cout << "�޸�ʧ�ܣ����޴��ˣ�" << endl;
        }
    }
    // �������������
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