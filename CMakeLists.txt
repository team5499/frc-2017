cmake_minimum_required(VERSION 2.8)
include(${CMAKE_TOOLCHAIN_FILE})

project(steamworks)
set(TEAM_NUMBER 5499)

# Robot target
# For quick list of files run
# find src -iname "*.cpp"
# in project root
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(SOURCE_FILES src/controllers/AutoController.cpp
              src/controllers/OperatorController.cpp
              src/Robot.cpp
              src/subsystems/Climber.cpp
              src/subsystems/Drivetrain.cpp
              src/subsystems/Gearpusher.cpp
              src/subsystems/Shooter.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Example: adding CTRE library
# Make sure this goes before WPILib
#find_package(CTRE)
#include_directories(${CTRE_INCLUDE_DIR})
#target_link_libraries(${PROJECT_NAME} ${CTRE_LIBRARIES})

find_package(WPILib)
include_directories(${WPILIB_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${WPILIB_LIBRARIES})

# Test target
include(ExternalProject)
ExternalProject_Add(check
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/test
  SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test
  INSTALL_COMMAND ""
  TEST_AFTER_INSTALL 1
  TEST_COMMAND ${CMAKE_CURRENT_BINARY_DIR}/test/src/check-build/check)
set_target_properties(check PROPERTIES EXCLUDE_FROM_ALL TRUE)

# Deploy target
find_file(ROBOTCOMMAND ant/robotCommand PATHS "${CMAKE_SYSROOT}/usr/share/wpilib"
                                              "${CMAKE_SYSROOT}/wpilib")
add_custom_target(deploy
  COMMAND sh -c "${CMAKE_CURRENT_SOURCE_DIR}/deploy ${TEAM_NUMBER} $<TARGET_FILE:${PROJECT_NAME}> ${ROBOTCOMMAND}"
  DEPENDS ${PROJECT_NAME})
set_target_properties(deploy PROPERTIES EXCLUDE_FROM_ALL TRUE)

# Doxygen target
find_package(Doxygen)
if(DOXYGEN_FOUND)
  configure_file(Doxyfile.in
    ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
  add_custom_target(doxygen
    ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
  set_target_properties(doxygen PROPERTIES EXCLUDE_FROM_ALL TRUE)
endif()
