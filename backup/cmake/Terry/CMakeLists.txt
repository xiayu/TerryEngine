project(Terry)

message("${PROJECT_NAME} ^ ${PROJECT_SOURCE_DIR} ^ ${PROJECT_BINARY_DIR} ^ ${CMAKE_CURRENT_SOURCE_DIR}")

add_definitions(-DTR_BUILD_DLL)

file(GLOB_RECURSE SOURCES 
	"${PROJECT_SOURCE_DIR}/src/*.cpp"
	"${PROJECT_SOURCE_DIR}/src/*.h"
)

add_library(${PROJECT_NAME}
	SHARED
	${SOURCES}
)

target_include_directories(${PROJECT_NAME}
	PRIVATE
        ${PROJECT_SOURCE_DIR}/src
        ${PROJECT_SOURCE_DIR}/vendor/spdlod/include
)
