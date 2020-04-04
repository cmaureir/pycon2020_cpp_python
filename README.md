#  C++ ♥ Python: from modules to hybrid applications

## Description

Extending Python with C is a technique that many popular modules use for
OS-level operations, serialization, performance, and more, but dealing with C
code is not simple: you need to take care of memory, understand pointers, and
write many lines of code for simple tasks. Luckily for you, there is C++.

Wait! Don't be scared!

I know maybe you heard bad stories and saw complicated pieces of C++ code, but:
are you aware of how C++ has been evolving? The latest C++ standards include
many goodies that smell a bit of Python, and I will show them to you.

During this talk, you will learn how to include C++ features into CPython
modules, how to create hybrid applications, and even to extend existent C++
applications with Python, making them scriptable.

This talk is intended for developers who are familiar with Python and know
basic C, but you don't need to know any C++ to take the most out of it.

## Audience

This talk is for Intermediate Python developers that are keen to know more
details about C++. I expect the audience to be familiar with Python and a bit
of C, but not necessarily know how to code in C++ since I will include small
C++ snippets that will be explained in detail. Complementary to that, if the
audience know a bit of C++, they will follow more easily the code and will
take home the possibility to create hybrid applications. I expect the audience
to learn how to write their first CPython module with C++, but also to
understand how to extend C++ applications with Python

## Outline

* Motivation **(5 minutes)**
  * How to deal with performance issues in Python,
  * Modules that use other languages (NumPy, Pandas, PyTorch, etc),
* Introduction to C++ **(5 minutes)**
  * Basic concepts,
  * Evolution of the language,
  * Highlighted C++11, 14, 17, and 20 features
* Creating a CPython module with C++ **(5 minutes)**,
  * `fastglob` a C++ implementation of the `glob` module with `std::filesystem`
* Extending a C++ application with Python **(10 minutes)**
  * Creating Python bindings from a C++ library,
  * Embedding a Python interpreter into a C++ application,
  * Run-time interaction of a Qt/C++ desktop application with Python,
* Final remarks **(5 minutes)**
  * Additional `std::` modern features to include in Python modules,
  * Brief comments on extending Python with other languages
