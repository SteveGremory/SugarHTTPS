#include "request.hpp"


int main() {
    while (1 == 1) {
        request req = request {
            .url = "http://91.232.174.39/hit"
        };
        req.get().text().make_request();
    }
    return EXIT_SUCCESS;
}