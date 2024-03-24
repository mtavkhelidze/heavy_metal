#include "macos.h"
#include <iostream>

// https://stackoverflow.com/a/77635101/1263999
#define safeObjcMsgSend(target, selector, ...) ((id(*)(id, SEL, ...)) objc_msgSend)(target, selector, ##__VA_ARGS__)

extern "C" int NSRunAlertPanel(CFStringRef strTitle, CFStringRef strMsg,
                               CFStringRef strButton1, CFStringRef strButton2,
                               CFStringRef strButton3, ...);

int main() {
    // auto window = CFAutorelease(objc_getClass("NSWindow"));
    // std::cout << window << std::endl;
    id pool = (id) objc_getClass("NSAutoreleasePool");
    if (!pool) {
        std::cerr << "Unable to get NSAutoreleasePool!\nAborting\n";
        return -1;
    }

    pool = safeObjcMsgSend(pool, sel_registerName("alloc"));
    if (!pool) {
        std::cerr << "Unable to create NSAutoreleasePool...\nAborting...\n";
        return -1;
    }
    safeObjcMsgSend(pool, sel_registerName("init"));
    safeObjcMsgSend((id) objc_getClass("NSApplication"), sel_registerName("sharedApplication"));

    NSRunAlertPanel(CFSTR("Testing"),
                    CFSTR("This is a simple test to display NSAlertPanel."),
                    CFSTR("OK"), nullptr, nullptr);

    safeObjcMsgSend(pool, sel_registerName("release"));
    return 0;
}
