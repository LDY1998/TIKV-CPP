cmake_minimum_required(VERSION 3.10)

include(GoogleTest)

file(GLOB_RECURSE BUSTUB_TEST_SOURCES "${PROJECT_SOURCE_DIR}/test/*/*test.cpp")

# #####################################################################################################################
# MAKE TARGETS
# #####################################################################################################################

# #########################################
# "make check-tests"
# #########################################
add_custom_target(build-tests COMMAND ${CMAKE_CTEST_COMMAND} --show-only)
add_custom_target(check-tests COMMAND ${CMAKE_CTEST_COMMAND} --verbose)
add_custom_target(check-public-ci-tests COMMAND ${CMAKE_CTEST_COMMAND} --verbose -E "\"SQLLogicTest|Trie\"")