include(FetchContent)

message(STATUS "Fetching nlohmann/json")

FetchContent_Declare(
  json
  GIT_REPOSITORY
    https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
  GIT_TAG v3.11.2
  GIT_SHALLOW TRUE)

FetchContent_MakeAvailable(json)
