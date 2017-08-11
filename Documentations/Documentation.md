# Documentation

# Installation

Arke package manager is write with c++ 17, so you need a modern C++ compiler and CMake build system.
Internally it used some libraries

- Boost (~filesystem)
- Botan 2 (cryptography)

```
mkdir build
cd build
cmake .. 
make
make install
```

# Tests

You can launch all tests with this command

```
make test
```

> There is a script to run tests coverage in Tests directory
> See master [coverage](coverage/index.html)