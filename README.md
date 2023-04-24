# CppND-System-Monitor

This is my implementation of the systrem monitor proejct using C++!

![System Monitor](images/monitor.png)


## ncurses
[ncurses](https://www.gnu.org/software/ncurses/) is a library that facilitates text-based graphical output in the terminal. This project relies on ncurses for display output.


## Make
This project uses [Make](https://www.gnu.org/software/make/). The Makefile has four targets:
* `build` compiles the source code and generates an executable
* `format` applies [ClangFormat](https://clang.llvm.org/docs/ClangFormat.html) to style the source code
* `debug` compiles the source code and generates an executable, including debugging symbols
* `clean` deletes the `build/` directory, including all of the build artifacts

if yout want to build the project, you can run the following commands:
```
make build
./build/monitor
```

<!-- add picture of the solution -->
![System Monitor](images/images/system_monitor_proejct.png)