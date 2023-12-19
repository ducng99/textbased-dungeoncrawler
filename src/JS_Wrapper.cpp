#ifdef __EMSCRIPTEN__
#include "JS_Wrapper.hpp"
#include <emscripten/val.h>
#include <emscripten.h>

#include <string>
#include <filesystem>

using namespace emscripten;

EM_ASYNC_JS(void, initFileStorage, (const char* saveDir), {
    await new Promise((resolve, reject) => {
        const dir = UTF8ToString(saveDir);
        FS.mkdir(dir);
        FS.mount(IDBFS, {}, dir);

        FS.syncfs(true, function(err) {
            if (err) {
                reject(err);
            } else {
                resolve();
            }
        });
    });
});

EM_ASYNC_JS(void, asyncSaveFiles, (), {
    await new Promise((resolve, reject) => {
        FS.syncfs(function(err) {
            if (err) {
                reject(err);
            } else {
                resolve();
            }
        });
    });
});

val JS_shell = val::global("shell");

bool js_wrapper::getline(std::string prefix, std::string & lineIn) {
    val JS_prompt = JS_shell.call<val>("prompt", prefix).await();
    lineIn = JS_prompt.as<std::string>();
    return true;
}

void js_wrapper::initSaveFiles(std::string saveDirName) {
    auto absolutePath = std::filesystem::current_path() / saveDirName;
    initFileStorage(absolutePath.c_str());
}

void js_wrapper::syncSaveFiles() {
    asyncSaveFiles();
}
#endif
