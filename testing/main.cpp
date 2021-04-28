#include <SugarHTTPS.hpp>

int main() {
    request {.url="https://google.com"}.get().make_request();
}