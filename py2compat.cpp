//
//  py2compat.cpp
//  rapidjson
//
//  Created by Ian Jenkins on 1/30/22.
//  Copyright (c) 2022 ___ORGANIZATIONNAME___. All rights reserved.
//
#include <Python.h>

#include "py2compat.hpp"

#if PY_MAJOR_VERSION < 3

PyObject* PyDict_SetDefault(PyObject *d, PyObject *key, PyObject *defaultobj){
    //PyDictObject    *mp = (PyDictObject *)d;
    PyObject        *value;
    
    if(!PyDict_Check(d)){
        PyErr_BadInternalCall();
        return NULL;
    }
    
    value = PyDict_GetItem(d, key);
    if(value == NULL){
        if(PyDict_SetItem(d, key, defaultobj) == 0)
            value = defaultobj;
        else
            PyErr_BadInternalCall();
    }
    return value;
}

/*
PyObject* PyFloat_FromString(PyObject *str){
    return PyFloat_FromString(str, NULL);
}
*/

#endif
