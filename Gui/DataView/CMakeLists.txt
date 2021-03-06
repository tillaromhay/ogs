# Source files
set( SOURCES
	ColorTableModel.cpp
	ColorTableView.cpp
	CondFromRasterDialog.cpp
	ConditionWriterDialog.cpp
	DirectConditionGenerator.cpp
	ElementTreeModel.cpp
	ElementTreeView.cpp
	FEMConditionSetupDialog.cpp
	GeoMapper.cpp
	GEOModels.cpp
	GeoTabWidget.cpp
	GeoTreeModel.cpp
	GeoTreeView.cpp
	GMSHPrefsDialog.cpp
	LicenseDialog.cpp
	LinearEditDialog.cpp
	LineEditDialog.cpp
	ListPropertiesDialog.cpp
	MeshValueEditDialog.cpp
	ModellingTabWidget.cpp
	ModelTreeItem.cpp
	MshEditDialog.cpp
	MshItem.cpp
	MshLayerMapper.cpp
	MshModel.cpp
	MshQualitySelectionDialog.cpp
	MshTabWidget.cpp
	MshView.cpp
	NetCdfConfigureDialog.cpp
	NewProcessDialog.cpp
	ProcessModel.cpp
	ProcessView.cpp
	SelectMeshDialog.cpp
	SetNameDialog.cpp
	StationTabWidget.cpp
	StationTreeModel.cpp
	StationTreeView.cpp
)

# Moc Header files
set( MOC_HEADERS
	ColorTableModel.h
	ColorTableView.h
	CondFromRasterDialog.h
	ConditionWriterDialog.h
	ElementTreeModel.h
	ElementTreeView.h
	FEMConditionSetupDialog.h
	GEOModels.h
	GeoTabWidget.h
	GeoTreeModel.h
	GeoTreeView.h
	GMSHPrefsDialog.h
	LicenseDialog.h
	LinearEditDialog.h
	LineEditDialog.h
	ListPropertiesDialog.h
	MeshValueEditDialog.h
	ModellingTabWidget.h
	MshEditDialog.h
	MshModel.h
	MshQualitySelectionDialog.h
	MshTabWidget.h
	MshView.h
	NetCdfConfigureDialog.h
	NewProcessDialog.h
	ProcessModel.h
	ProcessView.h
	SelectMeshDialog.h
	SetNameDialog.h
	StationTabWidget.h
	StationTreeModel.h
	StationTreeView.h
)

# Header files
set( HEADERS
	BaseItem.h
	CondItem.h
	DirectConditionGenerator.h
	CondObjectListItem.h
	GeoMapper.h
	GeoObjectListItem.h
	GeoTreeItem.h
	ModelTreeItem.h
	MshItem.h
	MshLayerMapper.h
	ProcessItem.h
)

# UI files
set( UIS
	CondFromRaster.ui
	ConditionWriter.ui
	FEMConditionSetup.ui
	GeoTabWidgetBase.ui
	GMSHPrefs.ui
	License.ui
	LinearEdit.ui
	LineEdit.ui
	MeshValueEdit.ui
	ModellingTabWidgetBase.ui
	MshEdit.ui
	MshQualitySelection.ui
	MshTabWidgetBase.ui
	NetCdfConfigure.ui
	NewProcess.ui
	StationTabWidgetBase.ui
)

IF (Shapelib_FOUND)
	SET( SOURCES ${SOURCES} SHPImportDialog.cpp)
	SET( MOC_HEADERS ${MOC_HEADERS} SHPImportDialog.h)
	INCLUDE_DIRECTORIES( ${Shapelib_INCLUDE_DIR} )
ENDIF () # Shapelib_FOUND

# Put filter in a folder
SOURCE_GROUP("Dialog Header Files" REGULAR_EXPRESSION "[.]*Dialog.h")
SOURCE_GROUP("Dialog Source Files" REGULAR_EXPRESSION "[.]*Dialog.cpp")
SOURCE_GROUP("Data Model Header Files" REGULAR_EXPRESSION "[.]*Item.h|[.]*Model.h|[.]*View.h")
SOURCE_GROUP("Data Model Source Files" REGULAR_EXPRESSION "[.]*Item.cpp|[.]*Model.cpp|[.]*View.cpp")

# Run Qts user interface compiler uic on .ui files
qt4_wrap_ui( UI_HEADERS ${UIS} )

# Run Qts meta object compiler moc on header files
qt4_wrap_cpp( MOC_SOURCES ${MOC_HEADERS} )


# Include the headers which are generated by uic and moc
# and include additional header
include_directories(
	${CMAKE_CURRENT_BINARY_DIR}/../Base
	${CMAKE_CURRENT_BINARY_DIR}
	${CMAKE_CURRENT_BINARY_DIR}/DiagramView
	${CMAKE_CURRENT_BINARY_DIR}/StratView

	${CMAKE_CURRENT_SOURCE_DIR}/../../BaseLib
	${CMAKE_CURRENT_SOURCE_DIR}/../../MathLib
	${CMAKE_CURRENT_SOURCE_DIR}/../../GeoLib
	${CMAKE_CURRENT_SOURCE_DIR}/../../OGS
	${CMAKE_CURRENT_SOURCE_DIR}/../../MeshLib
	${CMAKE_CURRENT_SOURCE_DIR}/../../FemLib
	${CMAKE_CURRENT_SOURCE_DIR}/../../FileIO
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/DiagramView
	${CMAKE_CURRENT_SOURCE_DIR}/StratView
	${CMAKE_CURRENT_SOURCE_DIR}/../Base
	${CMAKE_CURRENT_SOURCE_DIR}/../VtkVis
)

IF(VRPN_FOUND)
	INCLUDE_DIRECTORIES( ../Vrpn ${VRPN_INCLUDE_DIRS} )
ENDIF()

IF (VTKOSGCONVERTER_FOUND)
	INCLUDE_DIRECTORIES( ${VTKOSGCONVERTER_INCLUDE_DIRS} )
ENDIF (VTKOSGCONVERTER_FOUND)

IF (libgeotiff_FOUND)
	INCLUDE_DIRECTORIES( ${libgeotiff_INCLUDE_DIR} ${libgeotiff_INCLUDE_DIR}/libxtiff ${VTK_DIR}/../Utilities/vtktiff )
ENDIF () # libgeotiff_FOUND

# Put moc files in a project folder
source_group("UI Files" REGULAR_EXPRESSION "\\w*\\.ui")
source_group("Moc Files" REGULAR_EXPRESSION "moc_.*")


# Create the library
add_library( QtDataView STATIC
	${SOURCES}
	${HEADERS}
	${MOC_HEADERS}
	${MOC_SOURCES}
	#${UI_HEADERS}
	${UIS}
)

# Link Qt library
target_link_libraries( QtDataView
	${QT_LIBRARIES}
	FemLib
	FileIO
	GeoLib
	MeshLib
	QtBase
	DiagramView
	StratView
)

IF (Shapelib_FOUND)
	TARGET_LINK_LIBRARIES( QtDataView ${Shapelib_LIBRARIES} )
ENDIF () # Shapelib_FOUND
IF (libgeotiff_FOUND)
	TARGET_LINK_LIBRARIES( QtDataView ${libgeotiff_LIBRARIES} )
ENDIF () # libgeotiff_FOUND

set_property(TARGET QtDataView PROPERTY FOLDER "DataExplorer")
