//
// Created by addo6544 on 2026/9/25.
//

#ifndef FROSTJNI_GENERIC_H
#define FROSTJNI_GENERIC_H

#include <concepts>
#include "FrostJNI_Config.h"
#include "WrapperGenerator.h"

FROSTJNI_JAVATYPES_BEGIN_NAMESPACE

FROSTJNI_JAVATYPES_WRAPPER_FWD(Object)

template <typename T>
concept JavaTypeWrapper = std::derived_from<T, FROSTJNI_JAVATYPES_WRAPPER(Object)>;

FROSTJNI_JAVATYPES_END_NAMESPACE

#endif //FROSTJNI_GENERIC_H
