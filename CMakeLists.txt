cmake_minimum_required (VERSION 3.14)
project(alia-html-starter)

set(CMAKE_CXX_STANDARD 17)

# Apply some emscripten optimizations flags if we're in release mode.
include(cmake/release-mode.cmake)

# Add alia-html.
include(cmake/alia-html.cmake)

# Add the nlohmann/json library if you want to use it for HTML .
include(cmake/json.cmake)

# Create a subdirectory in the build dir that we'll use to accumulate all the
# files that need to be deployed to the web.
set(deploy_dir ${CMAKE_CURRENT_BINARY_DIR}/deploy)
file(MAKE_DIRECTORY ${deploy_dir})

# Deploy the index.html file.
alia_deploy(
    "${CMAKE_CURRENT_SOURCE_DIR}/src/index.html"
    "${deploy_dir}")

# Add the main app.
file(GLOB source_files "src/*.cpp")
add_executable(app ${source_files})
target_link_libraries(app alia_html)
set_target_properties(app PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${deploy_dir})

# Also deploy asm-dom.js.
alia_post_build_deploy(app
    ${CMAKE_CURRENT_BINARY_DIR}/asm-dom.js
    ${deploy_dir})