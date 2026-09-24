//
// Created by addo6544 on 2026/9/25.
//

#ifndef FROSTJNI_JAVA_LANG_H
#define FROSTJNI_JAVA_LANG_H

#include "FrostJNI.h"
#include "WrapperGenerator.h"

FROSTJNI_JAVATYPES_BEGIN_NAMESPACE

FROSTJNI_JAVATYPES_WRAPPER_FWD(Class)
FROSTJNI_JAVATYPES_WRAPPER_FWD(String)

class FROSTJNI_JAVATYPES_WRAPPER(Object) : public FROSTJNI_NAMESPACE_ JavaRefView<jobject>
{
    public:
    FROSTJNI_JAVATYPES_WRAPPER(Object) (const jobject objIn) noexcept : JavaRefView(objIn) {}\
    FROSTJNI_JAVATYPES_WRAPPER(Object) (const JavaRefView& refView) noexcept : JavaRefView(refView) {}

    FROSTJNI_NODISCARD FROSTJNI_JAVATYPES_WRAPPER(String) toString() const noexcept;
    FROSTJNI_NODISCARD FROSTJNI_JAVATYPES_WRAPPER(Class) getClass() const noexcept;
    FROSTJNI_NODISCARD jint hashCode() const noexcept;
    FROSTJNI_NODISCARD jboolean equals(FROSTJNI_JAVATYPES_WRAPPER(Object) other) const noexcept;

    bool operator==(const FROSTJNI_JAVATYPES_WRAPPER(Object) & other) const
    {
        return FROSTJNI_NAMESPACE_ Context->GetThreadEnv()->IsSameObject(get(), other.get());
    }
};

FROSTJNI_JAVATYPES_WRAPPER_IMPL(String, Object)
{
    public:
    FROSTJNI_JAVATYPES_WRAPPER_CTOR(String)

    FROSTJNI_NODISCARD std::string _getCString() const noexcept;
};

FROSTJNI_JAVATYPES_WRAPPER_IMPL(Class, Object)
{
    public:
    FROSTJNI_JAVATYPES_WRAPPER_CTOR(Class)

    FROSTJNI_NODISCARD FROSTJNI_JAVATYPES_WRAPPER(String) getName() const noexcept;
};

FROSTJNI_JAVATYPES_WRAPPER_FWD(Iterator)

FROSTJNI_JAVATYPES_WRAPPER_IMPL(Iterable, Object)
{
    public:
    FROSTJNI_JAVATYPES_WRAPPER_CTOR(Iterable)

    FROSTJNI_NODISCARD FROSTJNI_JAVATYPES_WRAPPER(Iterator) iterator() const noexcept;
};

FROSTJNI_JAVATYPES_END_NAMESPACE

#endif //FROSTJNI_JAVA_LANG_H
