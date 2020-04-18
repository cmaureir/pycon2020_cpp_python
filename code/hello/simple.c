#include <Python.h>

static PyObject* simple_hello(PyObject* self, PyObject* args){
    char *msg = "Hello, PyCon2020!";
    return Py_BuildValue("s", msg);
}

static char simple_docs[] =
    "hello(): print hello message\n";

static PyMethodDef simple_funcs[] = {
    {"hello",                   // ml_name
     (PyCFunction)simple_hello, // ml_meth
     METH_NOARGS,               // ml_flags
     simple_docs},              // ml_doc
    {}                          // sentinel
};

static struct PyModuleDef simplemodule = {
    PyModuleDef_HEAD_INIT, // m_base
    "simple",              // m_name
    NULL,                  // m_doc
    -1,                    // m_size
    simple_funcs           // m_methods
};

PyMODINIT_FUNC PyInit_simple(void){
    return PyModule_Create(&simplemodule);
}
