#include <iostream>
#include <memory>
using namespace std;

class D : public std::enable_shared_from_this<D>
{
public:
    D()
    {
        cout<<"D::D()"<<endl;
    }

    void func()
    {
        cout<<"D::func()"<<endl;
        std::shared_ptr<D> p = shared_from_this();
        // p->?
    }
};

int main()
{
    std::shared_ptr<D> p(new D);
    p->func();;
    return 0;
}