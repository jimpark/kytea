project(liblinear LANGUAGES CXX C)

set(SOURCE
    linear.cpp
    tron.cpp
    blas/daxpy.c
    blas/ddot.c
    blas/dnrm2.c
    blas/dscal.c)

add_library(liblinear OBJECT ${SOURCE})
