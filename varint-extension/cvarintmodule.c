#define PY_SSIZE_T_CLEAN
#include <Python.h>

/*
Task: write Protobuf encode and decode in C

Questions:
- How to run the code?
- What is a PyObject?
*/

static PyObject* cvarint_encode(PyObject *self, PyObject *args) {
}

static PyObject* cvarint_decode(PyObject *self, PyObject *args) {
}

static PyMethodDef CVarintMethods[] = {
    {"encode", cvarint_encode, METH_VARARGS, "Encode an integer as varint."},
    {"decode", cvarint_decode, METH_VARARGS,
     "Decode varint bytes to an integer."},
    {NULL, NULL, 0, NULL}};

static struct PyModuleDef cvarintmodule = {
    PyModuleDef_HEAD_INIT, "cvarint",
    "A C implementation of protobuf varint encoding", -1, CVarintMethods};

PyMODINIT_FUNC PyInit_cvarint(void) { return PyModule_Create(&cvarintmodule); }
