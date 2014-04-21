from distutils.core import setup, Extension
import os
setup (name = 'stdoutwriter',
       version = '0.1',
       description = 'Python wrapper for libmtester',
       packages=[''],
       package_dir={'':'module'},
       package_data={'':['stdoutwriter.so']}
       )

setup (name = 'adder',
       version = '0.1',
       description = 'Python wrapper for libmtester',
       packages=[''],
       package_dir={'':'module'},
       package_data={'':['adder.so']}
       )
