//
// Created by addo6544 on 2026/9/24.
//

#include "JavaTypes/java.lang.h"
#include <string>

#define Wrapper FROSTJNI_JAVATYPES_WRAPPER(String)
FROSTJNI_JAVATYPES_BEGIN_NAMESPACE

std::string Wrapper::_getCString() const noexcept
{
    const auto env = FROSTJNI_NAMESPACE_ Context->GetThreadEnv();
    const auto str = reinterpret_cast<jstring>(get());
    const char* chars = env->GetStringUTFChars(str, nullptr);
    std::string result = chars;
    env->ReleaseStringUTFChars(str, chars);
    return result;
}

FROSTJNI_JAVATYPES_END_NAMESPACE
