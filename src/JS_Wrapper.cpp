#ifdef __EMSCRIPTEN__
#include "JS_Wrapper.hpp"
#include <emscripten/val.h>

#include <string>

using namespace emscripten;

val JS_shell = val::global("shell");

bool js_wrapper::getline(std::string prefix, std::string & lineIn) {
    val JS_prompt = JS_shell.call<val>("prompt", prefix).await();
    lineIn = JS_prompt.as<std::string>();
    return true;
}
#endif
