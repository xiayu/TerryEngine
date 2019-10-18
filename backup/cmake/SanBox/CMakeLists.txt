project(SanBox)

message("${PROJECT_NAME} ^ ${PROJECT_SOURCE_DIR} ^ ${PROJECT_BINARY_DIR} ^ ${CMAKE_CURRENT_SOURCE_DIR} ^ ${CMAKE_SOURCE_DIR}")

file(GLOB_RECURSE SOURCES 
	"${PROJECT_SOURCE_DIR}/src/*.cpp"
	"${PROJECT_SOURCE_DIR}/src/*.h"
)

add_executable(${PROJECT_NAME}
	${SOURCES}
)

target_include_directories(${PROJECT_NAME}
	PRIVATE
		"${CMAKE_SOURCE_DIR}/Terry/vendor/spdlog/include"
		"${CMAKE_SOURCE_DIR}/Terry/src"
		"${CMAKE_SOURCE_DIR}/Terry/vendor"
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE 
        Terry
)
