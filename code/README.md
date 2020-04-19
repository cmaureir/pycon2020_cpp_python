# Code examples

Inside some directories, there is a `Makefile` file that build each project,
which is nothing else than a `python setup.py install`.

Please use a virtual environment to avoid installing this test modules in your
system, or user space:
```
cd code/
python -m venv env
source env/bin/activate   # for Linux/macOS
env\Scripts\activate.bat  # for Windows
```

## Description

* [hello/](hello/), simple Python module written in C that contains only
  a function to print a message.

* [fastglob/](hello/), C++ implementation of the `glob.glob()` function using
  `std::filesystem`.

* [fastmath/](fastmath/), C++ implementation of the `math.sqrt()` function using
  two approaches: `std::transform` and pure `C`.

* [embedding/](embedding/), embedding a Python interpreter into a simple C++
  application.

* [scriptableapplication/](scriptableapplication/), embedding a Python interpreter into a C++
  desktop application written with Qt, adding a 'plugins' functionallity.
