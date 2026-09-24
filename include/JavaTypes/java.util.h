//
// Created by addo6544 on 2026/9/25.
//

#ifndef FROSTJNI_JAVA_UTIL_H
#define FROSTJNI_JAVA_UTIL_H

#include "java.lang.h"
#include "Generic.h"

FROSTJNI_JAVATYPES_BEGIN_NAMESPACE

FROSTJNI_JAVATYPES_WRAPPER_IMPL(Iterator, Object)
{
    public:
    FROSTJNI_JAVATYPES_WRAPPER_CTOR(Iterator)

    FROSTJNI_NODISCARD jboolean hasNext() const noexcept;
    FROSTJNI_NODISCARD FROSTJNI_JAVATYPES_WRAPPER(Object) next() const noexcept;

    template <JavaTypeWrapper T>
    FROSTJNI_NODISCARD T next() const noexcept
    {
        return T(next().get());
    }
};

FROSTJNI_JAVATYPES_WRAPPER_IMPL(List, Object)
{

};

FROSTJNI_JAVATYPES_END_NAMESPACE

#endif //FROSTJNI_JAVA_UTIL_H
