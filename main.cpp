#include <iostream>

namespace sugar {
    class Networking {
    public:
        void then() {
            //Do After the get/post req ends
        }
    };
    Networking get() {}
}
int main() {
  get(12).then();
}
