project('Something', ['cpp', 'c'])
incdir = include_directories(
    'include'
)
libs  = [dependency('curl')]
executable('Something', ['src/main.cpp'], include_directories: incdir, dependencies: libs)
