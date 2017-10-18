#include <Python.h>
#include "wrapper.h"

static PyObject *_eclib_mwrank(PyObject *self, PyObject *args);

static PyMethodDef _eclib_methods[] = {
    {"mwrank", _eclib_mwrank, METH_VARARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef _eclib_module = {
    PyModuleDef_HEAD_INIT,
    "_eclib",
    NULL,
    -1,
    _eclib_methods,
};

PyMODINIT_FUNC
PyInit__eclib(void)
{
    return PyModule_Create(&_eclib_module);
}

static PyObject *_eclib_mwrank(PyObject *self, PyObject *args)
{
    char *a1_num, *a1_den, *a2_num, *a2_den, *a3_num, *a3_den, *a4_num, *a4_den, *a6_num, *a6_den;

    if (!PyArg_ParseTuple(args, "ssssssssss",
            &a1_num, &a1_den, &a2_num, &a2_den, &a3_num, &a3_den, &a4_num, &a4_den, &a6_num, &a6_den)) {
        return NULL;
    }

    vector<bigrational> ai = {};
    ai.push_back(to_bigrational(a1_num, a1_den));
    ai.push_back(to_bigrational(a2_num, a2_den));
    ai.push_back(to_bigrational(a3_num, a3_den));
    ai.push_back(to_bigrational(a4_num, a4_den));
    ai.push_back(to_bigrational(a6_num, a6_den));

    vector<pair<bigrational, bigrational>> v = mwrank(ai, 1000, 0, 1, 10, 10, 15);

    PyObject *basis = PyTuple_New(v.size());

    for(std::vector<int>::size_type i = 0; i < v.size(); i++) {

        PyObject *x_val = PyTuple_New(2);
        pair<const char *, const char *> x_strs = from_bigrational(v[i].first);
        PyTuple_SetItem(x_val, 0, Py_BuildValue("s", x_strs.first));
        PyTuple_SetItem(x_val, 1, Py_BuildValue("s", x_strs.second));

        PyObject *y_val = PyTuple_New(2);
        pair<const char *, const char *> y_strs = from_bigrational(v[i].second);
        PyTuple_SetItem(y_val, 0, Py_BuildValue("s", y_strs.first));
        PyTuple_SetItem(y_val, 1, Py_BuildValue("s", y_strs.second));

        PyObject *point = PyTuple_New(2);
        PyTuple_SetItem(point, 0, x_val);
        PyTuple_SetItem(point, 1, y_val);
        PyTuple_SetItem(basis, i, point);
    }

    return basis;
}
