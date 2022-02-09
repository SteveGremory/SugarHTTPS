#include <SugarHTTPS.hh>

int main()
{
    auto req = request {
        .url = "https://cdn.vox-cdn.com/thumbor/Pz0vdQ0aL4DlJcarWhwZLk2RmBw=/0x0:1323x638/1200x800/filters:focal(539x248:749x458)/cdn.vox-cdn.com/uploads/chorus_image/image/69851120/Screenshot_2021_09_10_7.38.39_AM.0.png",
    }
                   .get()
                   .download("main.png")
                   .make_request();

    if (req.success == 0) {
        std::cout << "Request successful.\n";
    }
    return 0;
}