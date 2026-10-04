cmake_minimum_required(VERSION 3.11)


add_executable(test_FixedArray FixedArray.cpp)
add_executable(test_Matrix Matrix.cpp)
add_executable(test_Pair Pair.cpp)
add_executable(test_Range Range.cpp)
add_executable(test_isEqual isEqual.cpp)
add_executable(test_linearSearch linearSearch.cpp)
add_executable(test_mySwap mySwap.cpp)
add_executable(test_printElement printElement.cpp)
add_executable(test_printValue printValue.cpp)
add_executable(test_sumArray sumArray.cpp)


add_test(NAME test_FixedArray COMMAND test_FixedArray)
add_test(NAME test_Matrix COMMAND test_Matrix)
add_test(NAME test_Pair COMMAND test_Pair)
add_test(NAME test_Range COMMAND test_Range)
add_test(NAME test_isEqual COMMAND test_isEqual)
add_test(NAME test_linearSearch COMMAND test_linearSearch)
add_test(NAME test_mySwap COMMAND test_mySwap)
add_test(NAME test_printElement COMMAND test_printElement)
add_test(NAME test_printValue COMMAND test_printValue)
add_test(NAME test_sumArray COMMAND test_sumArray)
add_custom_command(
  TARGET test_FixedArray POST_BUILD
  COMMENT "test_FixedArray"
  COMMAND test_FixedArray
)
add_custom_command(
  TARGET test_Matrix POST_BUILD
  COMMENT "test_Matrix"
  COMMAND test_Matrix
)
add_custom_command(
  TARGET test_Pair POST_BUILD
  COMMENT "test_Pair"
  COMMAND test_Pair
)
add_custom_command(
  TARGET test_Range POST_BUILD
  COMMENT "test_Range"
  COMMAND test_Range
)

add_custom_command(
  TARGET test_isEqual POST_BUILD
  COMMENT "test_isEqual"
  COMMAND test_isEqual
)
add_custom_command(
  TARGET test_linearSearch POST_BUILD
  COMMENT "test_linearSearch"
  COMMAND test_linearSearch
)
add_custom_command(
  TARGET test_mySwap POST_BUILD
  COMMENT "test_mySwap"
  COMMAND test_mySwap
)
add_custom_command(
  TARGET test_printElement POST_BUILD
  COMMENT "test_printElement"
  COMMAND test_printElement
)
add_custom_command(
  TARGET test_printValue POST_BUILD
  COMMENT "test_printValue"
  COMMAND test_printValue
)
add_custom_command(
  TARGET test_sumArray POST_BUILD
  COMMENT "test_sumArray"
  COMMAND test_sumArray
)
