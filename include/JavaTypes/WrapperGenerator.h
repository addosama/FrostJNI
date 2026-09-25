//
// Created by addo6544 on 2026/9/24.
//

#ifndef FROSTJNI_WRAPPER_GENERATORS_DEFINED
#define FROSTJNI_WRAPPER_GENERATORS_DEFINED


#define FROSTJNI_JAVATYPES_WRAPPER_CTOR_EX(name, parent) \
    FROSTJNI_JAVATYPES_WRAPPER(name) (const jobject objIn) noexcept : FROSTJNI_JAVATYPES_WRAPPER(parent)(objIn) {}\
    FROSTJNI_JAVATYPES_WRAPPER(name) (const JavaRefView& refView) noexcept : FROSTJNI_JAVATYPES_WRAPPER(parent)(refView) {}
#define FROSTJNI_JAVATYPES_WRAPPER_CTOR(name) FROSTJNI_JAVATYPES_WRAPPER_CTOR_EX(name, Object)

#define FROSTJNI_JAVATYPES_WRAPPER_IMPL(Name, Super) class FROSTJNI_JAVATYPES_WRAPPER(Name) : public FROSTJNI_JAVATYPES_WRAPPER(Super)
#define FROSTJNI_JAVATYPES_WRAPPER_FWD(Name) class FROSTJNI_JAVATYPES_WRAPPER(Name);

#define FROSTJNI_JAVATYPES_MethodWrapperBody_
#define FROSTJNI_JAVATYPES_MethodWrapperBody_Decl ;
#define FROSTJNI_JAVATYPES_MethodWrapperBody_BasicCall(Class, Name, Desc, Modifier, Type)\
    {  static const jmethodID id = FROSTJNI_NAMESPACE_ Context->Get##Modifier##MethodID(\
        FROSTJNI_NAMESPACE_ Context->FindClass(Class, nullptr), Name, Desc);\
        return FrostJNI::Context->GetThreadEnv()->Call##Modifier##Type##Method(get(), id); }

#define FROSTJNI_JAVATYPES_ObjectMethodWrapper(Body, RetType, Name, ...)\
    FROSTJNI_JAVATYPES_WRAPPER(RetType) Name(__VA_ARGS__) const noexcept FROSTJNI_JAVATYPES_MethodWrapperBody_##Body
#define FROSTJNI_JAVATYPES_BasicMethodWrapper(Body, RetType, Name, ...)\
    RetType Name(__VA_ARGS__) const noexcept FROSTJNI_JAVATYPES_MethodWrapperBody_##Body

#endif // FROSTJNI_WRAPPER_GENERATORS_DEFINED

// #ifdef FROSTJNI_WRAPPER_GENERATORS_UNDEF
// #undef FROSTJNI_WRAPPER_CTOR_EX
// #undef FROSTJNI_WRAPPER_CTOR
// #undef FROSTJNI_JAVATYPES_WRAPPER_IMPL
// #undef FROSTJNI_JAVATYPES_WRAPPER_FWD
// #endif

