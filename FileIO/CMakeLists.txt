# Source files
# GET_SOURCE_FILES(SOURCES_FILEIO)
SET( SOURCES
	Gmsh2GeoIO.cpp
	GMSInterface.cpp
	PetrelInterface.cpp
	readMeshFromFile.cpp
	readNonBlankLineFromInputStream.cpp
	Writer.cpp
)
GET_SOURCE_FILES(SOURCES_LEGACY Legacy)
GET_SOURCE_FILES(SOURCES_MESHIO MeshIO)
GET_SOURCE_FILES(SOURCES_RAPID_XML RapidXmlIO)
SET ( SOURCES ${SOURCES} ${SOURCES_LEGACY} ${SOURCES_MESHIO} ${SOURCES_RAPID_XML})

IF (QT4_FOUND)
	GET_SOURCE_FILES(SOURCES_XML XmlIO)
	SET ( SOURCES ${SOURCES} ${SOURCES_XML})
ENDIF (QT4_FOUND)

IF (Shapelib_FOUND)
	SET (SOURCES ${SOURCES} SHPInterface.h SHPInterface.cpp )
	INCLUDE_DIRECTORIES (${Shapelib_INCLUDE_DIR})
ENDIF (Shapelib_FOUND)

# Create the library
ADD_LIBRARY(FileIO STATIC ${SOURCES})

INCLUDE_DIRECTORIES(
	.
	${CMAKE_CURRENT_SOURCE_DIR}/../BaseLib
	${CMAKE_CURRENT_SOURCE_DIR}/../FemLib
	${CMAKE_CURRENT_SOURCE_DIR}/../GeoLib
	${CMAKE_CURRENT_SOURCE_DIR}/../MathLib
	${CMAKE_CURRENT_SOURCE_DIR}/../MeshLib
	${CMAKE_CURRENT_SOURCE_DIR}/../OGS
	${CMAKE_CURRENT_BINARY_DIR}/../BaseLib
)

TARGET_LINK_LIBRARIES (FileIO
	GeoLib
	MeshLib
	zlib
)

IF (Shapelib_FOUND)
	TARGET_LINK_LIBRARIES (FileIO ${Shapelib_LIBRARIES})
ENDIF (Shapelib_FOUND)

IF (OGS_PACKAGING)
	FILE(GLOB XSD_FILES . *.xsd)
	INSTALL (FILES ${XSD_FILES} DESTINATION bin)
ENDIF()