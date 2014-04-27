 ##                                                                                                                                        
 # The MIT License (MIT)                                                                                                                   
 #                                                                                                                                         
 # Copyright (c) 2014 Julio Delgado                                                                                                        
                                                                                                                                           
 # Permission is hereby granted, free of charge, to any person obtaining a copy                                                            
 # of this software and associated documentation files (the "Software"), to deal                                                           
 # in the Software without restriction, including without limitation the rights                                                            
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
 # SOFTWARE.                                                                                                                               
 ##
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})
SET(src StdoutWriter.cpp)
SET(src_adder Adder.cpp)

# Generate Static Libraries for the C++ code
ADD_LIBRARY(Adder ${src_adder})
ADD_LIBRARY(StdoutWriter ${src})

#Wire the Cython magic here
# If the pyx file is a C++ file, we should specify that here.
SET_SOURCE_FILES_PROPERTIES(
  ${STDOUT_WRITER_SOURCE_DIR}/src/stdoutwriter.pyx
  ${STDOUT_WRITER_SOURCE_DIR}/src/adder.pyx
  PROPERTIES CYTHON_IS_CXX TRUE )

# Multi-file cython modules do not appear to be working at the moment.
CYTHON_ADD_MODULE( stdoutwriter stdoutwriter.pyx)
target_link_libraries(stdoutwriter StdoutWriter)

CYTHON_ADD_MODULE( adder adder.pyx)
target_link_libraries( adder  Adder)

# Finally install the Cython modules and the server launching module
INSTALL(FILES setup.py DESTINATION ${CMAKE_BINARY_DIR}/python/)
INSTALL(TARGETS adder stdoutwriter LIBRARY DESTINATION ${CMAKE_BINARY_DIR}/python)
INSTALL(CODE "execute_process(COMMAND python ${CMAKE_BINARY_DIR}/python/setup.py install -f WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/python/)")