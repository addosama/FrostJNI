//
// Created by addo6544 on 2026/9/24.
//

#ifndef FROSTJNI_FROSTJNI_H
#define FROSTJNI_FROSTJNI_H

#include <concepts>
#include <string_view>

#include "FrostJNI_Config.h"
#include "jni.h"

FROSTJNI_BEGIN_NAMESPACE

template <typename T>
concept JavaRef = std::is_pointer_v<T> && std::derived_from<std::remove_pointer_t<T>, _jobject>;

struct FrostJNIContext
{
    using ThreadEnvGetterFn = JNIEnv*   (*)();
    using ClassFinderFn     = jclass    (*)(std::string_view name, jobject loader);
    using MethodFinderFn    = jmethodID (*)(jclass owner, std::string_view name, std::string_view desc);
    using FieldFinderFn     = jfieldID  (*)(jclass owner, std::string_view name, std::string_view desc);

    ThreadEnvGetterFn GetThreadEnv;
    ClassFinderFn     FindClass;
    MethodFinderFn    GetMethodID;
    FieldFinderFn     GetFieldID;
};

inline FrostJNIContext* Context = nullptr;

class JavaRefWrapper
{
protected:
    void* Raw;
    explicit JavaRefWrapper(void* raw) noexcept
    : Raw(raw)
    {}
};

template <JavaRef T>
class JavaRefView : protected JavaRefWrapper
{
public:
    JavaRefView(T ref) noexcept
    : JavaRefWrapper(ref)
    {}

    T get() const noexcept
    {
        return static_cast<T>(Raw);
    }

    operator T() const noexcept
    {
        return get();
    }
};

template <JavaRef T>
class LocalRefWrapper : public JavaRefView<T>
{
public:
    explicit LocalRefWrapper(T ref) noexcept
    : JavaRefView<T>(ref)
    {}

    LocalRefWrapper operator=(const LocalRefWrapper&) = delete;
    LocalRefWrapper(const LocalRefWrapper&) = delete;

    LocalRefWrapper& operator=(LocalRefWrapper&& other) = delete;
    LocalRefWrapper(const LocalRefWrapper&& other) noexcept
    : LocalRefWrapper(other.get())
    {
        other.Raw = nullptr;
    }

    ~LocalRefWrapper() noexcept
    {
        if (!JavaRefWrapper::Raw) return;
        Context->GetThreadEnv()->DeleteLocalRef(static_cast<jobject>(JavaRefWrapper::Raw));
    }
};

template <JavaRef T>
class GlobalRefWrapper : public JavaRefView<T>
{
public:
    explicit GlobalRefWrapper(T ref) noexcept
    : JavaRefView<T>(ref)
    {}

    GlobalRefWrapper operator=(const GlobalRefWrapper&) = delete;
    GlobalRefWrapper(const GlobalRefWrapper&) = delete;

    GlobalRefWrapper& operator=(GlobalRefWrapper&& other) = delete;
    GlobalRefWrapper(const GlobalRefWrapper&& other) noexcept
    : GlobalRefWrapper(other.get())
    {
        other.Raw = nullptr;
    }

    ~GlobalRefWrapper() noexcept
    {
        if (!JavaRefWrapper::Raw) return;
        Context->GetThreadEnv()->DeleteGlobalRef(static_cast<jobject>(JavaRefWrapper::Raw));
    }
};

FROSTJNI_END_NAMESPACE

#endif //FROSTJNI_FROSTJNI_H
