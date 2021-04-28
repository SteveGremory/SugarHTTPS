project('Stuff', ['cpp', 'c'])
incdir = include_directories(
    'include/'
)
libs  = [dependency('libcurl'), dependency('threads')]
executable('Stuff', ['src/main.cpp', 'include/request.cpp'], include_directories: incdir, dependencies: libs, override_options : ['cpp_std=c++2a'])
    