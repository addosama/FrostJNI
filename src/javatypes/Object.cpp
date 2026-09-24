//
// Created by addo6544 on 2026/9/24.
//

#include "JavaTypes.h"

#define Wrapper FROSTJNI_JAVATYPES_WRAPPER(Object)
FROSTJNI_JAVATYPES_BEGIN_NAMESPACE

FROSTJNI_JAVATYPES_WRAPPER(String) Wrapper::toString() const noexcept
{
    static const jmethodID id = FROSTJNI_NAMESPACE_ Context->GetMethodID(
        FROSTJNI_NAMESPACE_ Context->FindClass("java/lang/Object", nullptr),
        "toString",
        "()Ljava/lang/String;"
        );
    return FrostJNI::Context->GetThreadEnv()->CallObjectMethod(get(), id);
}

FROSTJNI_JAVATYPES_WRAPPER(Class) Wrapper::getClass() const noexcept
{
    static const jmethodID id = FROSTJNI_NAMESPACE_ Context->GetMethodID(
            FROSTJNI_NAMESPACE_ Context->FindClass("java/lang/Object", nullptr),
            "getClass",
            "()Ljava/lang/Class;"
            );
    return FrostJNI::Context->GetThreadEnv()->CallObjectMethod(get(), id);
}

jint Wrapper::hashCode() const noexcept
{
    static const jmethodID id = FROSTJNI_NAMESPACE_ Context->GetMethodID(
            FROSTJNI_NAMESPACE_ Context->FindClass("java/lang/Object", nullptr),
            "hashCode",
            "()I"
            );
    return FrostJNI::Context->GetThreadEnv()->CallIntMethod(get(), id);
}

jboolean Wrapper::equals(FROSTJNI_JAVATYPES_WRAPPER(Object) other) const noexcept
{
    static const jmethodID id = FROSTJNI_NAMESPACE_ Context->GetMethodID(
            FROSTJNI_NAMESPACE_ Context->FindClass("java/lang/Object", nullptr),
            "equals",
            "(Ljava/lang/Object;)Z"
            );
    return FrostJNI::Context->GetThreadEnv()->CallBooleanMethod(get(), id);
}

FROSTJNI_JAVATYPES_END_NAMESPACE
