
add_executable(hashtest
    hashtest.cpp
    testloader.hh
    testloader.cpp
    suite.hh
    suite.cpp)

target_link_libraries(hashtest
    dl)
