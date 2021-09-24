import os
os.system("cp ../build/libSugarHTTPS.so ./")
os.system("cp ../build/deps/curl/lib/libcurl.so ./")
os.system("g++ -I../include -I../deps/curl/include -L../build -L../build/deps/curl/lib -lSugarHTTPS -lcurl ./MakeRequest.cc -o ./runme")