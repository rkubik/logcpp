# logcpp

Simple Thread-Safe C++11 logging library.

## Dependencies

- C++11 compiler
- GNU/Linux platform
- cmake
- debuild (optional)

## Build

You can build and install the shared library and header with cmake or use
debuild to create Debian packages.

1. cmake

In the root of the project.

    mkdir build
    cd build
    cmake ..
    make
    make install

2. debuild

In the root of the project.

    debuild -us -uc -b -j4
    debuild clean

Which will produce both the runtime and development Debian packages.

## Multithreading and Limitations

- Multithreading support only supported when logging messages. Modifying logger
  attributes at run-time in a multi-threaded environment is currently not
  supported.

## TODO

- Unit tests
- Documentation (doxygen)
- FileRotateLogger compression

## License

MIT
