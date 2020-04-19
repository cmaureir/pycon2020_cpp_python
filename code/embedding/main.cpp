#include <Python.h>

int main(int argc, char *argv[]) {

    // By default is Python
    const wchar_t *name(L"main");
    Py_SetProgramName(name);

    Py_Initialize();
    PyRun_SimpleString("print('Hello, PyCon2020!')");
    Py_Finalize();
    return 0;
}
