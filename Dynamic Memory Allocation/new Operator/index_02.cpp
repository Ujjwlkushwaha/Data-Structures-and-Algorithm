// C++ program to illustrate how to initialize a dynamic
// variable with allocation
#include <iostream>
using namespace std;

// dabbaom data type with constructor to take initial value
class dabba
{
    public:
        int p;

        dabba(int q)
            : p(q){}

        dabba() = default;
};

int main()
{
    // creating inbuit data types with initial value
    int* p = new int(25);
    float* q = new float(75.25);

    dabba* var = new dabba(25);

    cout << *p << " " << *q << " " << var->p;
    return 0;
}
