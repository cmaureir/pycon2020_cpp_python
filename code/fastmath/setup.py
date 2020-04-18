#build the modules
import os
from distutils.core import setup, Extension

os.environ["CC"] = "g++"

setup(name='fastmath', version='1.0',
      ext_modules=[
        Extension('fastmath', ['fastmath.cpp'],
            extra_compile_args=["-std=c++17", "-ltbb", "-lm"],
            extra_link_args=["-std=c++17", "-ltbb", "-lm"]
            )])
