/*
 * class.h
 *
 *  Created on: 3. 11. 2019
 *      Author: Jakub Korbel
 */

#ifndef CLASS_H_
#define CLASS_H_


#include "utils.h"

#include "drd1.6.h"

struct
{
    const char* p_name;

    range_t weight_limit_coin;

    range_t height_limit_in;

    size_class_t size;

} race_t;


#endif /* CLASS_H_ */
