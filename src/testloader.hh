#pragma once

#include <vector>
#include <functional>

class Test
{
public:
    Test(void *handle) : m_handle(handle) {}
    std::function<std::string(std::string)> func() {
        return m_test_func;
    }
    ~Test();

    std::function<std::string(std::string)> m_test_func;
private:
    void *m_handle;
};

class TestLoader
{
public:
    TestLoader() {}
    static Test* load(std::string name);

};
