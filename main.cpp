#include <SugarHTTPS.hpp>

int main() {
    auto x = sugar::get("www.google.com");
    std::cout << x.body;
}