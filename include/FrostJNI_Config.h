//
// Created by addo6544 on 2026/9/24.
//

#ifndef FROSTJNI_FROSTJNI_CONFIG_H
#define FROSTJNI_FROSTJNI_CONFIG_H

/*
 * 编译器警告
 */

#define FROSTJNI_NODISCARD [[nodiscard]]
#define FROSTJNI_NODISCARD_EX(reason) [[nodiscard(reason)]]


/*
 * FrostJNI命名空间
 */

#define FROSTJNI_NAMESPACE FrostJNI
#define FROSTJNI_NAMESPACE_ FrostJNI::

#define FROSTJNI_BEGIN_NAMESPACE namespace FROSTJNI_NAMESPACE {
#define FROSTJNI_END_NAMESPACE }

/*
 * Java类型包装命名空间
 */

#define FROSTJNI_JAVATYPES_NAMESPACE
#define FROSTJNI_JAVATYPES_NAMESPACE_

#define FROSTJNI_JAVATYPES_BEGIN_NAMESPACE
#define FROSTJNI_JAVATYPES_END_NAMESPACE

/*
 * Java类型包装器命名
 */

#define FROSTJNI_JAVATYPES_WRAPPER(name) j##name

#endif //FROSTJNI_FROSTJNI_CONFIG_H
