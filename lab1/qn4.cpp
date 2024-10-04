//Revision of class template

#include<iostream>

template <class T>
class swapClass
{
public: 
    swapClass(T x = 0, T y = 0)
    {
        a = x;
        b = y;
    }

    void swap()
    {
        int c;
        c = b;
        b = a;
        a = c;
    }

    void printValue()
    {
        std::cout<<"a = "<<a<<std::endl;
        std::cout<<"b = "<<b<<std::endl;
    }
private:
    T a,b;
};

int main()
{
    swapClass<int> sc1(2,7);
    swapClass<double> sc2(4,5);

    std::cout<<"Before swap"<<std::endl<<"Integer: "<<std::endl;
    sc1.printValue();
    std::cout<<"Double: "<<std::endl;
    sc2.printValue();

    sc1.swap();
    sc2.swap();

    std::cout<<"After swap"<<std::endl<<"Integer: "<<std::endl;
    sc1.printValue();
    std::cout<<"Double: "<<std::endl;
    sc2.printValue();

    return 0;
}