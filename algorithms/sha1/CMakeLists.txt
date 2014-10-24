
add_library(sha1 SHARED
    ../algorithm.hh
    sha1.cpp)
include_directories(..)
target_link_libraries(sha1
    ssl
    )
