project('SugarHTTPS', 'cpp')
incdir = include_directories(
    'include'
)
libs  = [dependency('libcurl')]
executable('SugarHTTPS', ['src/main.cpp'], include_directories: incdir, dependencies: libs, override_options : ['cpp_std=c++2a'])
    