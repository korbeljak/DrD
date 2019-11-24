#include <stddef.h>


#include "utils.h"

#include "drd1.6.h"

struct
{
    const char* pName;

    range_t weight_limit_coin;

    range_t height_limit_in;

    size_class_t size;

} race;
