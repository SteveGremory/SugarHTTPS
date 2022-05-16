#include <SugarHTTPS.h>

using namespace SugarHTTPS;

int main()
{
    auto req = Request()
                   .SetUrl("https://gnu.org/")
                   .Get()
                   .MakeRequest().Flush();


    if (req.GetStatus() == RequestStatus::Success)
        std::cout << "Request successful.\n";
    else
        std::cout << "Request failed.\n";

    return 0;
}
