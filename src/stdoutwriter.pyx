#clib StdoutWriter
from libcpp.string cimport string
cdef extern from "StdoutWriter.hpp":
    cdef cppclass StdoutWriter:
        StdoutWriter()
        StdoutWriter(string message)
        void write(string message)
        void repeat()

cdef class PStdoutWriter:
    cdef StdoutWriter* ptr
    def __cinit__(self):
        self.ptr = new StdoutWriter()

    def __dealloc__(self):
        del self.ptr

    cpdef write(self, string message):
        self.ptr.write(message)

    cpdef repeat(self):
        self.ptr.repeat()