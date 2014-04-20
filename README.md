Template Python -Cpp - Cython - CMake
    
    This project demonstrate the integration of Cpp and Cython using CMake.
    In its current state it generates a functional Python module that can
    be imported and used together with any other Python module.
    
    The idea is to use this setup to provide some Cpp code as the backend
    code for a Python webserver, for example web.py or tornado. Let's let
    Python handle the front-end part (a problem already solved a million times)
    and let's focus our effort in performant code in the backend.
    
    This commit is still a bit rough around the edges.
    
    TODO:
    
    * Comment all the code so that it can be used as a tutorial
    * Add tests for the Cpp code
    * Add tests for the Python wrappers (nosetest probably)
    * Integrate a Python web framewokr (web.py would be my choice)

Open Source License.

Author: Julio Delgado Mangas (julio.delgadomangas@gmail.com)
