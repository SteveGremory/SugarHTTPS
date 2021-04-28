if [ "$(uname)" == "Darwin" ]; then
    # Delete the macOS dylib(s) and header(s)
    rm -rf /usr/local/lib/libSugarHTTPS.0.5.0.dylib
    rm -rf /usr/local/lib/libSugarHTTPS.dylib
    rm -rf /usr/local/include/SugarHTTPS.hpp
elif [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
    # Delete the macOS dylib(s) and header(s)
    rm -rf /usr/lib/libSugarHTTPS.0.5.0.so
    rm -rf /usr/lib/libSugarHTTPS.so
    rm -rf /usr/include/SugarHTTPS.hpp
fi