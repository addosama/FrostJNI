//
// Created by addo6544 on 2026/9/24.
//

#include "JavaTypes/java.lang.h"
#include "JavaTypes/java.util.h"

#define Wrapper FROSTJNI_JAVATYPES_WRAPPER(Iterable)
FROSTJNI_JAVATYPES_BEGIN_NAMESPACE

FROSTJNI_NODISCARD FROSTJNI_JAVATYPES_WRAPPER(Iterator) Wrapper::iterator() const noexcept
{
    static const jmethodID id = FROSTJNI_NAMESPACE_ Context->GetMethodID(
            FROSTJNI_NAMESPACE_ Context->FindClass("java/lang/Iterable", nullptr),
            "iterator",
            "()Ljava/util/Iterator;"
            );
    return FrostJNI::Context->GetThreadEnv()->CallObjectMethod(get(), id);
}

FROSTJNI_JAVATYPES_END_NAMESPACE
