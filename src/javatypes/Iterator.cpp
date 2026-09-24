//
// Created by addo6544 on 2026/9/24.
//

#include "JavaTypes/java.util.h"

#define Wrapper FROSTJNI_JAVATYPES_WRAPPER(Iterator)
FROSTJNI_JAVATYPES_BEGIN_NAMESPACE

FROSTJNI_NODISCARD jboolean Wrapper::hasNext() const noexcept
{
    static const jmethodID id = FROSTJNI_NAMESPACE_ Context->GetMethodID(
        FROSTJNI_NAMESPACE_ Context->FindClass("java/util/Iterator", nullptr),
        "hasNext",
        "()Z"
        );
    return FrostJNI::Context->GetThreadEnv()->CallBooleanMethod(get(), id);
}

FROSTJNI_NODISCARD FROSTJNI_JAVATYPES_WRAPPER(Object) Wrapper::next() const noexcept
{
    static const jmethodID id = FROSTJNI_NAMESPACE_ Context->GetMethodID(
        FROSTJNI_NAMESPACE_ Context->FindClass("java/util/Iterator", nullptr),
        "next",
        "()Ljava/lang/Object;"
        );
    return FrostJNI::Context->GetThreadEnv()->CallObjectMethod(get(), id);
}

FROSTJNI_JAVATYPES_END_NAMESPACE