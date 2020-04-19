#include <Python.h>

// C++ libraries
#include <iostream>
#include <cmath>
#include <algorithm>
#include <execution>
#include <chrono>

// alias for namespace
namespace tt = std::chrono;

// First implementation, using 'sqrt()' from math.h
// Warning: It only works with numbers
static PyObject* fastmath_sqrt1(PyObject* self, PyObject* args, PyObject* kwds){

    // Getting first argument, in this case a 'list'
    PyObject *l = PyTuple_GET_ITEM(args, 0);

    // Getting the size of the list
    int size = PySequence_Size(l);

    // Creating an output list that we will build
    PyObject *out_list = PyList_New(size);

    PyObject *item = nullptr;

    // measuring time
    auto t1 = tt::high_resolution_clock::now();

    // Main loop to:
    // - get the item,
    // - transform it to double
    // - append to the output list
    for (int i = 0; i < size; ++i) {
        item = PySequence_GetItem(l, i);
        double value = PyFloat_AsDouble(item);
        PyList_SetItem(out_list, i, Py_BuildValue("d", sqrt(value)));
        Py_DECREF(item); // using PySequence_GetItem() increases the
                         // refcount of item, so we decrease it after
                         // using it
    }

    auto t2 = tt::high_resolution_clock::now();
    auto t = tt::duration_cast<tt::microseconds>( t2 - t1 ).count();
    std::cout << "> microsecs: " << t << std::endl;

    return out_list;
}

// Second implementation, using 'sqrt()' from math.h with std::transform
// Warning: It only works with numbers
static PyObject* fastmath_sqrt2(PyObject* self, PyObject* args, PyObject* kwds){

    // Getting first argument, in this case a 'list'
    PyObject *l = PyTuple_GET_ITEM(args, 0);

    // Getting the size of the list
    int size = PySequence_Size(l);

    // Creating an output list that we will build
    PyObject *out_list = PyList_New(size);

    PyObject *item = nullptr;

    // Copy Python List to std::vector
    std::vector<double> vec(size), out(size);
    for (int i = 0; i < size; i++) {
        item = PySequence_GetItem(l, i);
        vec[i] = PyFloat_AsDouble(item);
        Py_DECREF(item);
    }

    auto t1 = tt::high_resolution_clock::now();

    // Releasing the GIL
    Py_BEGIN_ALLOW_THREADS

    std::transform(std::execution::par,              // execution policy
                   vec.begin(),                      // first element to transform
                   vec.end(),                        // last element to transform
                   out.begin(),                      // first element to save values
                   [](double i) { return sqrt(i);}); // lambda function to get sqrt

    Py_END_ALLOW_THREADS
    auto t2 = tt::high_resolution_clock::now();
    auto t = tt::duration_cast<tt::microseconds>( t2 - t1 ).count();
    std::cout << "> microsec: " << t << std::endl;

    // Adding the std::vector values to the output Python list
    for (int i = 0; i < size; ++i) {
        PyList_SetItem(out_list, i, Py_BuildValue("d", out[i]));
    }

    return out_list;
}

// Functions definition
static PyMethodDef fastmath_funcs[] = {
    {"sqrt1", (PyCFunction)fastmath_sqrt1, METH_VARARGS|METH_KEYWORDS, 0},
    {"sqrt2", (PyCFunction)fastmath_sqrt2, METH_VARARGS|METH_KEYWORDS, 0},
    {}
};

// Module definition
static struct PyModuleDef fastmathmodule = {
    PyModuleDef_HEAD_INIT,
    "fastmath",
    nullptr,
    -1,
    fastmath_funcs
};

// Module initialization
PyMODINIT_FUNC PyInit_fastmath(void){
    return PyModule_Create(&fastmathmodule);
}
