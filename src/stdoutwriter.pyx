##
# The MIT License (MIT)
#
# Copyright (c) 2014, 2018 Julio Delgado

# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the right
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
##
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