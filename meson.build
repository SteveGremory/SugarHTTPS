project('SugarHTTPS', ['cpp', 'c'])
version = '0.5.0'
incdir = include_directories('include/')
libs  = [dependency('libcurl')]
sugar = shared_library('sugarhttps', ['include/SugarHTTPS.cpp'], include_directories: incdir, dependencies: libs, override_options : ['cpp_std=c++2a'], version: version, soversion: version, install: true, install_dir : '/usr/lib')
install_headers('include/SugarHTTPS.hpp', install_dir : '/usr/include')
executable('main', 'testing/main.cpp', override_options : ['cpp_std=c++2a'], link_with: sugar, dependencies: libs)
pkg_mod = import('pkgconfig')
pkg_mod.generate(libraries : sugar,
                version : '0.5.0',
                name : 'libsugarhttps',
                filebase : 'sugarhttps',
                install_dir : '/usr/lib/pkgconfig',
                requires: 'libcurl',
                description : 'A HTTPS Library to make Networking in C++ as easy as Python while being very fast.')