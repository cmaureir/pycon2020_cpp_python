#build the modules
import os
from distutils.core import setup, Extension

setup(name='fastglob', version='1.0',
      ext_modules=[
        Extension('fastglob', ['fastglob.cpp'],
        extra_compile_args=["-std=c++17"],
            )])
