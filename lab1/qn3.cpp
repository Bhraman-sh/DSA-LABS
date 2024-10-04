#include<iostream>

template <typename T>
T swap(T *a, T *b)
{
    T c;
    c = *b;
    *b = *a;
    *a = c;
}

int main()
{
    int a=2;
    int b = 3;
    double c = 325;
    double d = 5030923;

    std::cout<<"Before swap"<<std::endl;
    std::cout<<"a = "<<a<<std::endl;
    std::cout<<"b = "<<b<<std::endl;
    std::cout<<"c = "<<c<<std::endl;
    std::cout<<"d = "<<d<<std::endl;

    swap(&a,&b);
    swap(&c,&d);

    std::cout<<"After swap"<<std::endl;
    std::cout<<"a = "<<a<<std::endl;
    std::cout<<"b = "<<b<<std::endl;
    std::cout<<"c = "<<c<<std::endl;
    std::cout<<"d = "<<d<<std::endl;

    return 0;

}