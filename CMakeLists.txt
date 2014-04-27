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
CMAKE_MINIMUM_REQUIRED (VERSION 2.8)

#Project name
PROJECT(STDOUT_WRITER)

# Make sure files under cmake/ are made available
set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_LIST_DIR}/cmake )

#Make sure we use C++11
#SET(CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS}")
# Compile Position Independent Code. This is a requirement of in order to allow
# Python to load our cython modules.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC") 

#Make sure dependencies are available
FIND_PACKAGE(Boost COMPONENTS unit_test_framework REQUIRED)
MESSAGE(STATUS "Boost Libraries ${Boost_INCLUDE_DIRS}")
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
INCLUDE( UseCython )
#FIND_PACKAGE(Cython REQUIRED)

#Include subdirectories
ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(test)
ADD_SUBDIRECTORY(apps)
