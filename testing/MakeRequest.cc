#include <SugarHTTPS.h>

using namespace SugarHTTPS;

int main()
{
    auto req = Request()
                   .Get()
                   .MakeRequest();

    if (!req.GetStatus())
        std::cout << "Request successful.\n";

    return 0;
}
