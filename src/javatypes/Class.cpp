//
// Created by addo6544 on 2026/9/24.
//

#include "JavaTypes/java.lang.h"

#define Wrapper FROSTJNI_JAVATYPES_WRAPPER(Class)
FROSTJNI_JAVATYPES_BEGIN_NAMESPACE

FROSTJNI_NODISCARD FROSTJNI_JAVATYPES_WRAPPER(String) Wrapper::getName() const noexcept
{
    static const jmethodID id = FROSTJNI_NAMESPACE_ Context->GetMethodID(
        FROSTJNI_NAMESPACE_ Context->FindClass("java/lang/Class", nullptr),
        "getName",
        "()Ljava/lang/String;"
        );
    return FrostJNI::Context->GetThreadEnv()->CallObjectMethod(get(), id);
}

FROSTJNI_JAVATYPES_END_NAMESPACE
