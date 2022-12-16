#include <QCoreApplication>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout << "Hello, world!33" << endl;

    int num = 18; // 宣告數字變數 num

    int* ptr; // 宣告指針 ptr
    ptr = &num; // 將 ptr 指向 num 的地址

    int* ptr2 = &num; // 宣告指針 ptr2 的同時即賦值

    //int& ref2; // 不接受宣告空的引用
    int& ref = num; // 宣告一個引用 指向 num

    cout << "ptr point on: " << ptr << endl;    //# ptr point on: 0000004AF98FF770
    cout << "ptr value is : " << ptr << endl;  //# ptr value is : 18
    cout << "ptr2 point on: " << ptr2 << endl;  //# ptr2 point on: 0000004AF98FF770
    cout << "ptr2 value is: " << *ptr2 << endl; //# ptr2 value is: 18
    cout << "ref address is: " << &ref << endl; //# ref address is:0000004AF98FF770
    cout << "ref refer to: " << ref << endl;    //# ref refer to: 18
    cout << "value on pointer to refer to ptr is: " << **&ptr << endl; //# value on pointer to refer to ptr is: 18

    return a.exec();
}
