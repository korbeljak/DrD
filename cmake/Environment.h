/*
 * Environment.h
 *
 *  Created on: 24. 11. 2019
 *      Author: Jakub Korbel
 */

#ifndef CMAKE_ENVIRONMENT_H_
#define CMAKE_ENVIRONMENT_H_

#define DRD_PROJECT_VER_MAJOR ${PROJECT_VERSION_MAJOR}
#define DRD_PROJECT_VER_MINOR ${PROJECT_VERSION_MINOR}
#define DRD_PROJECT_VER_PATCH ${PROJECT_VERSION_PATCH}


/// Maximum operator tokens in one dicecmd.
#define DRD_ROLL_MAX_OP_TOKENS ${DRD_ROLL_MAX_OP_TOKENS}

/// Maximum number tokens in one dicecmd.
#define DRD_ROLL_MAX_NUM_TOKENS ${DRD_ROLL_MAX_NUM_TOKENS}

/// Application Name
#define DRD_APP_NAME u8"${DRD_APP_NAME}"


#endif /* CMAKE_ENVIRONMENT_H_ */
