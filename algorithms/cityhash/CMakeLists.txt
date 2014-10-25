
add_library(cityhash SHARED
    ../algorithm.hh
    cityhash.cpp
    city.h
    city.cc)
include_directories(..)
include_directories(.)
