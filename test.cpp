#include <SugarHTTPS.hpp>

int main() {
    request {
        .url = "https://stackoverflow.com/questions/1636333/download-file-using-libcurl-in-c-c",
    }.get().make_request();
    return 0;
}