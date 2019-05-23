set(SOURCES
        main.cpp
        )

set(HEADERS
        Vec3.h
        PpmDrawer.cpp PpmDrawer.h
        Color.h
        Utils.h
        Ray.h shapes/Shape.h shapes/Sphere.h shapes/ShapeList.h Camera.h)

add_executable(raytracing ${SOURCES} ${HEADERS})

set_target_properties(raytracing PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
        )