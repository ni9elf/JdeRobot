CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
 
PROJECT(libgeometry)
 
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR} /usr/include/libxml2/)

set(SRC_FILES math/matriz3x3.cpp  math/matriz4x4.cpp  math/plano.cpp  math/utils.cpp math/Line2D.cpp math/Segment2D.cpp math/Point2D.cpp math/Point3D.cpp math/Line3D.cpp math/Plane3D.cpp math/Segment3D.cpp collada/colladaparser.cpp collada/color.cpp collada/malla.cpp collada/material.cpp collada/submalla.cpp progeo/Progeo.cpp math/segmento.cpp math/recta.cpp) 
 
ADD_LIBRARY(geometry SHARED ${SRC_FILES})

include(FindPkgConfig)
find_package(Boost COMPONENTS system filesystem REQUIRED)

target_link_libraries(geometry tinyxml GLU ${OpenCV_LIBRARIES} ${OpenCVGUI_LIBRARIES} ${Boost_LIBRARIES})

#SET_PROPERTY(TARGET geometry PROPERTY SOVERSION 1.0)
 
#ADD_LIBRARY(geometry_static STATIC ${SRC_FILES})

#target_link_libraries(geometry_shared tinyxml GLU ) 
#SET_TARGET_PROPERTIES(geometry_shared geometry_static PROPERTIES OUTPUT_NAME geometry)

### Install
install(TARGETS geometry
    DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
    COMPONENT core
)



FILE(GLOB_RECURSE GEOMETRY_HEADERS_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} */*.h)

FOREACH(currentSourceFile ${GEOMETRY_HEADERS_FILES})
string(REGEX REPLACE "(.*/).*.h" "\\1" new_source1 ${currentSourceFile})
	install( FILES ${currentSourceFile}
    	DESTINATION ${CMAKE_INSTALL_PREFIX}/include/jderobot/geometry/${new_source1}
    	COMPONENT core
	)
ENDFOREACH(currentSourceFile)

install( FILES Dense.h
    DESTINATION ${CMAKE_INSTALL_PREFIX}/include/jderobot/geometry/
    COMPONENT core
)

