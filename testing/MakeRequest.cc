#include <SugarHTTPS.hh>

int main()
{
    auto req = request {
        .url = "https://google.com",
    }
                   .get()
                   .make_request();

    if (req.success == 0) {
        std::cout << "Request successful.\n";
    }
    return 0;
}