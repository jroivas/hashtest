
add_library(sha256 SHARED
    ../algorithm.hh
    sha256.cpp)
include_directories(..)
target_link_libraries(sha256
    ssl
    )
