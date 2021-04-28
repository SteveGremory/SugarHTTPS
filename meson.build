project('SugarHTTPS', ['cpp', 'c'])
version = '0.5.0'
incdir = include_directories('include/')
libs  = [dependency('libcurl')]
sugar = shared_library('SugarHTTPS', ['include/SugarHTTPS.cpp'], include_directories: incdir, dependencies: libs, override_options : ['cpp_std=c++2a'], version: version, soversion: version, install: true, install_dir : '/usr/lib')
install_headers('include/SugarHTTPS.hpp', install_dir : '/usr/include')
executable('main', 'src/main.cpp', link_with : sugar, dependencies: libs)