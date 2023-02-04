#include <iostream>
using namespace std;
#include "MyArray.hpp"
void printIntArray(MyArray<int> &arr)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        cout << arr[i] << endl;
    }
}
void test01()
{
    MyArray<int> arr1(5);
    for (int i = 0; i < 5; i++)
    {
        arr1.Push_Back(i);
    }
    cout << "arr1的打印输出为:" << endl;
    printIntArray(arr1);
    cout << "arr1的容量为:" << arr1.getSize() << endl;
    MyArray<int> arr2(arr1);
    arr2.Pop_Back();
    cout << "arr2的打印输出为:" << endl;
    printIntArray(arr2);
    cout << "arr2的容量为:" << arr2.getSize() << endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}