#include <iostream>
#include <sstream>
using namespace std;

class MyClass
{
private:
    MyClass(int value = 0) { m_value = value; } //constructor
    int m_value;
    static MyClass* m_instance; //singleton instance

public:
    int get_value() { return m_value; }
    void set_value(int value) { m_value = value; }
    static MyClass* GetInstance() //get singleton instance function
    {
        if (!m_instance)
            m_instance = new MyClass();
        return m_instance;
    }
};
MyClass* MyClass::m_instance = nullptr; //default initialisation of singleton instance

string func1(void)
{
    MyClass* MyObject = MyClass::GetInstance(); //call getinstance function
    MyObject->set_value(1);
    cout << "func1: Address of MyObject is " << MyObject << " and value is " << MyObject->get_value() << '\n';

    ostringstream ptr;
    ptr << MyObject;
    return ptr.str();
}

string func2(void)
{
    MyClass* MyObject = MyClass::GetInstance(); //call getinstance function
    MyObject->set_value(2);
    cout << "func2: Address of MyObject is " << MyObject << " and value is " << MyObject->get_value() << '\n';

    ostringstream ptr;
    ptr << MyObject;
    return ptr.str();
}

//int main(void)
//{
//    func1();
//    func2();
//    return 0;
//}