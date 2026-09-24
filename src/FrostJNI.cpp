//
// Created by addo6544 on 2026/9/24.
//

#include "FrostJNI.h"
#include "JavaTypes.h"

using namespace FrostJNI;

int main()
{
    LocalRefWrapper<jobject> objWrapper(nullptr);
    LocalRefWrapper<jclass>  classWrapper(nullptr);

    jClass jCls = classWrapper.get();
    jObject jobj = classWrapper.get();
}
