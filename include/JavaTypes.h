//
// Created by addo6544 on 2026/9/24.
//

#ifndef FROSTJNI_JAVATYPES_H
#define FROSTJNI_JAVATYPES_H

#include "FrostJNI.h"

#define FROSTJNI_WRAPPER_CTOR_EX(name, parent) \
    FROSTJNI_JAVATYPES_WRAPPER(name) (const jobject objIn) noexcept : FROSTJNI_JAVATYPES_WRAPPER(parent)(objIn) {}\
    FROSTJNI_JAVATYPES_WRAPPER(name) (const JavaRefView& refView) noexcept : FROSTJNI_JAVATYPES_WRAPPER(parent)(refView) {}
#define FROSTJNI_WRAPPER_CTOR(name) FROSTJNI_WRAPPER_CTOR_EX(name, Object)

FROSTJNI_JAVATYPES_BEGIN_NAMESPACE

class FROSTJNI_JAVATYPES_WRAPPER(Class);
class FROSTJNI_JAVATYPES_WRAPPER(String);

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

template <typename T>
concept JavaTypeWrapper = std::derived_from<T, FROSTJNI_JAVATYPES_WRAPPER(Object)>;

class FROSTJNI_JAVATYPES_WRAPPER(String) : public FROSTJNI_JAVATYPES_WRAPPER(Object)
{
    public:
    FROSTJNI_WRAPPER_CTOR(String)

    FROSTJNI_NODISCARD std::string _getCString() const noexcept;
};

class FROSTJNI_JAVATYPES_WRAPPER(Class) : public FROSTJNI_JAVATYPES_WRAPPER(Object)
{
    public:
    FROSTJNI_WRAPPER_CTOR(Class)

    FROSTJNI_NODISCARD FROSTJNI_JAVATYPES_WRAPPER(String) getName() const noexcept;
};

class FROSTJNI_JAVATYPES_WRAPPER(Iterator) : public FROSTJNI_JAVATYPES_WRAPPER(Object)
{
    public:
    FROSTJNI_WRAPPER_CTOR(Iterator)

    FROSTJNI_NODISCARD jboolean hasNext() const noexcept;
    FROSTJNI_NODISCARD FROSTJNI_JAVATYPES_WRAPPER(Object) next() const noexcept;

    template <JavaTypeWrapper T>
    FROSTJNI_NODISCARD T next() const noexcept
    {
        return T(next().get());
    }
};

class FROSTJNI_JAVATYPES_WRAPPER(Iterable) : public FROSTJNI_JAVATYPES_WRAPPER(Object)
{
    public:
    FROSTJNI_WRAPPER_CTOR(Iterable)

    FROSTJNI_NODISCARD FROSTJNI_JAVATYPES_WRAPPER(Iterator) iterator() const noexcept;
};

FROSTJNI_JAVATYPES_END_NAMESPACE

#undef FROSTJNI_WRAPPER_CTOR
#undef FROSTJNI_WRAPPER_CTOR_EX
#endif //FROSTJNI_JAVATYPES_H
