from distutils.core import setup, Extension

setup(
    name = 'pyeclib',
    version='0.0.1',
    description="Python bindings for John Cremona's eclib.",
    author='Nick Spinale',
    license='MIT',
    ext_modules = [
        Extension(
            '_eclib',
            sources = ['_eclib.cc', 'wrapper.cc'],
            libraries = ['ntl', 'ec'],
            extra_compile_args = ['-std=c++11'],
        ),
    ],
)
