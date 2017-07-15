# CMake generated Testfile for 
# Source directory: C:/Users/Atul/Desktop/Transmax/15_July/app/test
# Build directory: C:/Users/Atul/Desktop/Transmax/15_July/Build/app/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(ModernCppCIAppTest "C:/Users/Atul/Desktop/Transmax/15_July/Build/app/Debug/ModernCppCIApp.exe")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(ModernCppCIAppTest "C:/Users/Atul/Desktop/Transmax/15_July/Build/app/Release/ModernCppCIApp.exe")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(ModernCppCIAppTest "C:/Users/Atul/Desktop/Transmax/15_July/Build/app/MinSizeRel/ModernCppCIApp.exe")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(ModernCppCIAppTest "C:/Users/Atul/Desktop/Transmax/15_July/Build/app/RelWithDebInfo/ModernCppCIApp.exe")
else()
  add_test(ModernCppCIAppTest NOT_AVAILABLE)
endif()
