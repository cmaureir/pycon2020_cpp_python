#include <Python.h>

// C++ libraries
#include <string>
#include <vector>
#include <iostream>
#include <filesystem>

// alias for the 'std::filesystem' namespace
namespace fs = std::filesystem;

static PyObject* fastglob_glob(PyObject* self, PyObject* args, PyObject* kwds){

    // Parsing the arguments of the function call
    const char *kwlist[] = {"directory", "recursive",0};
    const char *directory = nullptr;
    const int *recursive = nullptr;

    if (!PyArg_ParseTupleAndKeywords(args, kwds,
                                     "z|p",
                                     const_cast<char **>(kwlist),
                                     &directory,
                                     &recursive))
        return nullptr;

    // Creating empty list
    PyObject *l = PyList_New(0);

    // Filling the list depending if it's recursive or not
    if (recursive) {
        for (const auto &entry : fs::recursive_directory_iterator(directory))
            PyList_Append(l, PyUnicode_FromString(entry.path().c_str()));
    } else {
        for (const auto &entry : fs::directory_iterator(directory))
            PyList_Append(l, PyUnicode_FromString(entry.path().c_str()));
    }

    return l;
}

static char fastglob_docs[] =
    "glob(path, recursive=False): super fast glob\n";

// Functions definition
static PyMethodDef fastglob_funcs[] = {
    {"glob",
     (PyCFunction)fastglob_glob,
     METH_VARARGS|METH_KEYWORDS,
     fastglob_docs},
    {}
};

// Module definition
static struct PyModuleDef fastglobmodule = {
    PyModuleDef_HEAD_INIT,
    "fastglob",
    nullptr,
    -1,
    fastglob_funcs
};

// Module initialization
PyMODINIT_FUNC PyInit_fastglob(void){
    return PyModule_Create(&fastglobmodule);
}
