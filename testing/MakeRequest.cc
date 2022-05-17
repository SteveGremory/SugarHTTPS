#include <SugarHTTPS.h>

using namespace SugarHTTPS;

int main()
{
    auto req = Request()
                   .SetUrl("https://gnu.org/")
                   .Get()
                   .MakeRequest()
                   .Flush();

    /*
    * Not needed when SUGARHTTPS_LOG is defined.

    if (req.GetStatus() == RequestStatus::Success)
        std::cout << "Request successful.\n";
    else
        std::cout << "Request failed.\n";
    */

    return 0;
}
