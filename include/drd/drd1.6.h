/*
 * rules.h
 *
 *  Created on: 3. 11. 2019
 *      Author: Jakub Korbel
 */

#if !defined(RULES_DRD_001_006_H)
#define RULES_DRD_001_006_H

typedef enum
{
    SIZE_CLASS_A0 = 0,
    SIZE_CLASS_A = 1,
    SIZE_CLASS_B = 2,
    SIZE_CLASS_C = 3,
    SIZE_CLASS_D = 4,
    SIZE_CLASS_E = 5
} size_class_t;


typedef enum
{
    CHECK_FAILURE = 0x00,
    CHECK_SUCCESS = 0x01,
    CHECK_CRIT_FAILURE = 0x02,
    CHECK_CRIT_SUCCESS = 0x03
} CheckResult_t;

#endif //  !defined(RULES_DRD_001_006_H)
