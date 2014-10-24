#include <dlfcn.h>
#include <iostream>
#include "testloader.hh"

Test *TestLoader::load(std::string name)
{
    char *error = nullptr;
    void *handle = dlopen(("lib" + name + ".so").c_str(), RTLD_LAZY);
    if (!handle) {
        error = dlerror();
        std::cerr << "ERROR: " << error << "\n";
        return nullptr;
    }
    dlerror();

    typedef std::string (*fn_type)(std::string);
    fn_type fn = reinterpret_cast<fn_type>(dlsym(handle, "hashtest"));
    if ((error = dlerror()) != nullptr) {
        std::cerr << "ERROR: " << error << "\n";
        dlclose(handle);
        return nullptr;
    }

    Test *res = new Test(handle);
    res->m_test_func = fn;

    return res;
}

Test::~Test()
{
    if (m_handle != nullptr)
        dlclose(m_handle);
}
