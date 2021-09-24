# SugarHTTPS

## _Not_ just wrapper around libcURL.

SugarHTTPS is a part of the Sugar/Riemann Products suite, designed specifically to make the lives of both developers and users extremely easy, whilst maintaning speed and reliability.

## Features

- POST Request
- GET Request
- Downloading Files

## Dependencies

SugarHTTPS uses a the following open source projects to work properly:

- [libcURL](https://curl.se/libcurl/)
- [CMake](https://cmake.org/)
- [pkgConfig](https://en.wikipedia.org/wiki/Pkg-config)
- [Python](https://www.python.org/)

## Installation

To install the library, follow the given steps:

1. Clone the repo
2. make sure you have the following installed:
   - libcURL
   - The Meson Build System
   - CMake
   - pkgConfig
   - Python
3. in the SugarHTTPS directory, run the following command: `sudo sh ./install.sh`

## Usage

To use SugarHTTPS in your projects:

1.  Clone the repo, and install the library.
2.  Include the header `SugarHTTPS.hpp` in the file you're using it in.
3.  If you're using a build system that supports Pkg-Config, just Add SugarHTTPS as a dependency, if you're using terminal commands, link _both_ SugarHTTPS & libcURL.

## License

GNU General Public License
