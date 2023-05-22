#include "encoding_method.hpp"

/**
 * Method table
*/
static PyMethodDef EncoderMethods[] = {
    {
        "encode_preamble",
        clp_loglib_native::encoder::encode_preamble,
        METH_VARARGS,
        "encode the preamble with a reference timestamp, a timestamp format, and a time zone."
    },

    {
        "encode_message_and_timestamp",
        clp_loglib_native::encoder::encode_message_and_timestamp,
        METH_VARARGS,
        "encode the log message with the message content and the timestamp delta."
    },

    {
        "encode_message",
        clp_loglib_native::encoder::encode_message,
        METH_VARARGS,
        "encode the log message content"
    },

    {
        "encode_timestamp",
        clp_loglib_native::encoder::encode_timestamp,
        METH_VARARGS,
        "encode the timestamp delta."
    },

    {
        NULL,
        NULL,
        0,
        NULL
    }
};

/**
 * Module definition
*/
static struct PyModuleDef clp_native_encoder = {
    PyModuleDef_HEAD_INIT,
    "CLPNativeEncoder",
    NULL,
    -1,
    EncoderMethods
};

/**
 * Module initialization
*/
PyMODINIT_FUNC PyInit_CLPNativeEncoder (void) {
    return PyModule_Create(&clp_native_encoder);
}
