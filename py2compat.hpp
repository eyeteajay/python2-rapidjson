//
//  py2compat.hpp
//  rapidjson
//
//  Created by Ian Jenkins on 1/30/22.
//  Copyright (c) 2022 ___ORGANIZATIONNAME___. All rights reserved.
//

#ifndef py2compat_hpp
#define py2compat_hpp

#if PY_MAJOR_VERSION < 3

#include <Python.h>

#ifdef __cplusplus
extern "C" {
#endif

#define PyFloat_FromString(str)     PyFloat_FromString(str, NULL)

#define PyUnicode_AsUTF8(pystr)                     (const char*)PyString_AsString(pystr)
#define PyUnicode_InternFromString(v)               PyString_InternFromString(v)
#define PyUnicode_AsUTF8AndSize(pystr, sizeptr)     ((*sizeptr=PyString_Size(pystr)), PyString_AsString(pystr))

PyObject* PyDict_SetDefault(PyObject *d, PyObject *key, PyObject *defaultobj);

#define _PyObject_CAST(op)          ((PyObject*)(op))
#define _PyObject_CAST_CONST(op)    ((const PyObject*)(op))

#ifndef Py_SETREF
    #define Py_SETREF(op, op2)                      \
        do {                                        \
            PyObject *_py_tmp = _PyObject_CAST(op); \
            (op) = (op2);                           \
            Py_DECREF(_py_tmp);                     \
        } while (0)
#endif


#ifdef __cplusplus
}
#endif
#endif

#endif /* py2compat_hpp */
