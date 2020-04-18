#include <Python.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <execution>
#include <chrono>

static PyObject* fastmath_sqrt2(PyObject* self, PyObject* args, PyObject* kwds){

    PyObject *item = nullptr;
    PyObject *l = PyTuple_GET_ITEM(args, 0);

    int size = PySequence_Size(l);
    PyObject *out_list = PyList_New(size);

    // Copy Python List to std::vector
    std::vector<double> vec(size);
    std::vector<double> out(size);
    for (int i = 0; i < size; i++) {
        item = PySequence_GetItem(l, i);
        vec[i] = PyFloat_AsDouble(item);
        Py_DECREF(item);
    }

    auto t1 = std::chrono::high_resolution_clock::now();
    Py_BEGIN_ALLOW_THREADS
    std::transform(std::execution::par, vec.begin(), vec.end(), out.begin(),
        [](double i) { return sqrt(i);});
    Py_END_ALLOW_THREADS
    auto t2 = std::chrono::high_resolution_clock::now();
    auto t = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    std::cout << "> microsec: " << t << std::endl;

    for (int i = 0; i < size; ++i) {
        PyList_SetItem(out_list, i, Py_BuildValue("d", out[i]));
    }

    return out_list;
}

static PyObject* fastmath_sqrt1(PyObject* self, PyObject* args, PyObject* kwds){

    PyObject *item = nullptr;
    PyObject *l = PyTuple_GET_ITEM(args, 0);

    int size = PySequence_Size(l);
    PyObject *out_list = PyList_New(size);

    auto t1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < size; ++i) {
        item = PySequence_GetItem(l, i);
        double value = PyFloat_AsDouble(item);
        PyList_SetItem(out_list, i, Py_BuildValue("d", sqrt(value)));
        Py_DECREF(item);
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    auto t = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    std::cout << "> microsec: " << t << std::endl;

    return out_list;
}

static PyMethodDef fastmath_funcs[] = {
    {"sqrt1", (PyCFunction)fastmath_sqrt1, METH_VARARGS|METH_KEYWORDS, 0},
    {"sqrt2", (PyCFunction)fastmath_sqrt2, METH_VARARGS|METH_KEYWORDS, 0},
    {nullptr, nullptr, 0, nullptr}
};

static struct PyModuleDef fastmathmodule = {
    PyModuleDef_HEAD_INIT,
    "fastmath",
    nullptr,
    -1,
    fastmath_funcs
};

PyMODINIT_FUNC PyInit_fastmath(void){
    return PyModule_Create(&fastmathmodule);
}
