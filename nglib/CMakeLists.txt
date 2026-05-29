target_sources(nglib PRIVATE nglib.cpp)

if(USE_OCC)
    target_sources(nglib PRIVATE nglib_occ.cpp)
    install(FILES nglib_occ.h DESTINATION ${NG_INSTALL_DIR_INCLUDE} COMPONENT netgen_devel)
endif(USE_OCC)

target_link_libraries(nglib PRIVATE ${ZLIB_LIBRARIES})
target_link_libraries( nglib PUBLIC ngcore PRIVATE ${CMAKE_THREAD_LIBS_INIT} ${JPEG_LIBRARIES} ${MKL_LIBRARIES} occ_libs netgen_cgns )

# Suppress warnings from netgen internal code
if(MSVC)
  target_compile_options(nglib PRIVATE
    /wd4828 # illegal character in source file (opti.hpp)
    /wd4834 # discarding [[nodiscard]] return value
    /wd4297 # noexcept mismatch
    /wd4068 # unknown pragma (e.g. '#pragma clang')
  )
endif()

install(TARGETS nglib netgen_cgns ${NG_INSTALL_DIR})
install(FILES nglib.h DESTINATION ${NG_INSTALL_DIR_INCLUDE} COMPONENT netgen_devel)
