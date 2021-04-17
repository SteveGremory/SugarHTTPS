#include "main.hpp"

int main() {
    auto r = request {
        .url = "https://reqbin.com/echo/post/json",
        .data = R"(
            {
                "Id": "78912",
                "Customer": "Jason Sweet",
                "Quantity": "1",
                "Price": 18.00
            }
        )"
    };
    auto n = r.post().text().make_request();
}
