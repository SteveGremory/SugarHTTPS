rm -rf ./build
meson build && ninja -C build && cd ./build && ninja install
