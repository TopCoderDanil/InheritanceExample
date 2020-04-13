
#include <iostream>
using namespace std;

class B1 {
    int a;
public:
    B1() { cout << "object of" << typeid(*this).name() << " was created\n"; }
    B1(int x) :B1() { a = x; }
    ~B1() { cout << "object of" << typeid(*this).name() << " was destroyed\n"; }
};
class B2 {
    int a;
public:
    B2() { cout << "object of" << typeid(*this).name() << " was created\n"; }
    B2(int x) :B2() { a = x; }
    ~B2() { cout << "object of" << typeid(*this).name() << " was destroyed\n"; }
};

class D1 : public B1, private B2
{
    int c;
public:
    D1(int x, int y, int z) : B1(y), B2(z)
    {
        c = x;
        cout << "object of" << typeid(*this).name() << " was created\n";
    };
    ~D1() { cout << "object of" << typeid(*this).name() << " was destroyed\n"; }
};
class D2 : private D1
{
    int d;
public:

    D2(int x, int y, int z, int i) : D1(y, z, i)
    {
        d = x;
        cout << "object of" << typeid(*this).name() << " was created\n";
    }
    ~D2() { cout << "object of" << typeid(*this).name() << " was destroyed\n"; }
};
class B3
{
    int e;
public:
    B3(int x)
    {
        e = x;
        cout << "object of" << typeid(*this).name() << " was created\n";
    }
    ~B3() { cout << "object of" << typeid(*this).name() << " was destroyed\n"; }
};
class D3 : public D2, private B3
{
    int d;
public:

    D3(int x, int y, int z, int i, int j, int k) : D2(y, z, i, j), B3(k)
    {
        d = x;
        cout << "object of" << typeid(*this).name() << " was created\n";
    }
    ~D3() { cout << "object of" << typeid(*this).name() << " was destroyed\n"; }
};


int main()
{
    D3 top(1, 2, 3, 4, 5, 6);
}