add_subdirectory(common)
add_subdirectory(type)

add_library(TIKV-CPP STATIC ${ALL_OBJECT_FILES})


find_package(Threads REQUIRED)

set(THIRDPARTY_LIBS
        bustub_murmur3
        duckdb_pg_query
        fmt
        libfort::fort
        Threads::Threads
        )

target_link_libraries(
        TIKV-CPP
        ${BUSTUB_LIBS}
        ${BUSTUB_THIRDPARTY_LIBS})

target_include_directories(
        TIKV-CPP PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
