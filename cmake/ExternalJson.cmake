

ExternalProject_Add(json
  PREFIX ${EXTERNAL_BUILD_DIR}/json
  BINARY_DIR ${EXTERNAL_BUILD_DIR}
  INSTALL_DIR ${EXTERNAL_INSTALL_DIR}
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG 9ff0cc0f0212cb1e85b83ce5d2907ba9531b6cae
  UPDATE_COMMAND ${GIT_EXECUTABLE} fetch --all
         COMMAND ${GIT_EXECUTABLE} reset --hard origin/master
  CONFIGURE_COMMAND echo "nothing to configure"
  BUILD_COMMAND echo "nothing to build"
  CMAKE_CACHE_ARGS
            -DCMAKE_INSTALL_PREFIX:STRING=${EXTERNAL_INSTALL_DIR}
  INSTALL_COMMAND ""
  
  )

# Specify include dir
ExternalProject_Get_Property(json source_dir)

set(JSON_INCLUDE_DIR ${source_dir}/src)
include_directories(${JSON_INCLUDE_DIR})