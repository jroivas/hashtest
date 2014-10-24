
add_library(xxhash64 SHARED
    ../algorithm.hh
    xxhash.cpp
    ../xxhash/xxhash.h
    ../xxhash/xxhash.c)
include_directories(..)
