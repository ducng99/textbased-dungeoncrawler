#ifdef __EMSCRIPTEN__
#ifndef _JS_WRAPPER_HPP_
#define _JS_WRAPPER_HPP_

#include <string>

namespace js_wrapper {
    bool getline(std::string prefix, std::string & lineIn);

    void initSaveFiles(std::string saveDirName);
    void syncSaveFiles();
}

#endif // _JS_WRAPPER_HPP_
#endif
