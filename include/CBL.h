#ifndef _CBL_H_
#define _CBL_H_

#include "config.h"
#include "CBL_Basic.h"
#include "CBL_DateTime.h"
#include "CBL_String.h"
#include "CBL_Log.h"
#include "CBL_Vector.h"
#include "CBL_Array.h"
#include "CBL_Dict.h"
#include "CBL_IntVector.h"
#include "CBL_FloatVector.h"
#include "CBL_FloatMatrix.h"
// #include "CBL_TypeArray.h"

/**
 * @brief get sizeof(type) by typecode
 * @param type typecode defined in `CBL_Basic.h` header file
 * @return bytes of type
 */
size_t CBL_typecode2size(UInt8 type);

#endif // _CBL_H_
