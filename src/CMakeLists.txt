set(SOURCES
        main.cpp
        )

set(HEADERS
        Vec3.h Vec3.cpp
        PpmDrawer.h PpmDrawer.cpp
        Color.cpp Color.h)

add_executable(raytracing ${SOURCES} ${HEADERS})

set_target_properties(raytracing PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
        )