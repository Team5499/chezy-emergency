cmake_minimum_required(VERSION 2.8)
include(frc.cmake)

project(chezy-emergency)

# Team number
set(TEAM_NUMBER 5499)

# Robot target
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

# For quick list run
# find src -iname "*.cpp"
# in project root
set(SOURCE_FILES src/SlothBase.cpp
                 src/SlothRobot.cpp
                 src/subsystems/Drivetrain.cpp
                 src/subsystems/Intake.cpp
		 src/controllers/OperatorController.cpp
		 src/controllers/AutoController.cpp
         src/controllers/AutoPIDController.cpp
         
)
add_frc_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Deploy target
add_frc_deploy(deploy ${TEAM_NUMBER} $<TARGET_FILE:${PROJECT_NAME}>)

# Doxygen target
find_package(Doxygen)
if(DOXYGEN_FOUND)
    configure_file(Doxyfile.in
            ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
    add_custom_target(doxygen
            ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
    set_target_properties(doxygen PROPERTIES EXCLUDE_FROM_ALL TRUE)
endif()
