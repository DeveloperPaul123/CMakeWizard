
ExternalProject_Add(easyloggingpp
  PREFIX ${EXTERNAL_BUILD_DIR}/easyloggingpp
  BINARY_DIR ${EXTERNAL_BUILD_DIR}
  INSTALL_DIR ${EXTERNAL_INSTALL_DIR}
  GIT_REPOSITORY https://github.com/dreal-deps/easyloggingpp.git
  GIT_TAG master
  UPDATE_COMMAND ${GIT_EXECUTABLE} fetch --all
         COMMAND ${GIT_EXECUTABLE} reset --hard origin/master
  CONFIGURE_COMMAND echo "nothing to configure"
  BUILD_COMMAND echo "nothing to build"
  CMAKE_CACHE_ARGS
            -DCMAKE_INSTALL_PREFIX:STRING=${EXTERNAL_INSTALL_DIR}
  INSTALL_COMMAND ""
  
  )

# Specify include dir
ExternalProject_Get_Property(easyloggingpp source_dir)

set(EASYLOGGING_INCLUDE_DIR ${source_dir}/src)
include_directories(${EASYLOGGING_INCLUDE_DIR})
add_definitions(-DELPP_QT_LOGGING)
add_definitions(-DELPP_STL_LOGGING)
add_definitions(-DELPP_DEBUG_ERRORS)