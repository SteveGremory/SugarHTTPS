project('SugarHTTPS', ['cpp', 'c'])
version = '0.5.0'

# Include Directories.
incdir = include_directories('include/')

# Dependencies
libs  = [dependency('libcurl')]

# Make the library, then install the headers
sugar = shared_library('sugarhttps', ['include/SugarHTTPS.cpp'], include_directories: incdir, dependencies: libs, override_options : ['cpp_std=c++2a'], version: version, soversion: version, install: true, 
                        # Disable on macOS
                        # install_dir : '/usr/lib'
                    )
install_headers('include/SugarHTTPS.hpp', 
                # Disable on macOS
                # install_dir : '/usr/include'
                )

# Make an executable for testing, don't install it though. Disable on macOS when installing.
# executable('main', 'testing/main.cpp', override_options : ['cpp_std=c++2a'], link_with: sugar, dependencies: libs)

# Package config magic
pkg_mod = import('pkgconfig')
pkg_mod.generate(libraries : sugar,
                version : '0.5.0',
                name : 'libsugarhttps',
                filebase : 'sugarhttps',
                # Disable on macOS
                # install_dir : '/usr/lib/pkgconfig',
                requires: 'libcurl',
                description : 'A HTTPS Library to make Networking in C++ as easy as Python while being very fast.')
