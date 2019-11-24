
set(DRD_ROLL_MAX_OP_TOKENS "2048" CACHE STRING "Maximum operator tokens in one dicecmd.")
set(DRD_ROLL_MAX_NUM_TOKENS "2048" CACHE STRING "Maximum number tokens in one dicecmd.")
set(DRD_ENV_DIR "${CMAKE_CURRENT_LIST_DIR}" CACHE INTERNAL "")

macro(GenerateEnvironment)
configure_file(${DRD_ENV_DIR}/Environment.h ${CMAKE_BINARY_DIR}/include/drd/Environment.h)
endmacro()