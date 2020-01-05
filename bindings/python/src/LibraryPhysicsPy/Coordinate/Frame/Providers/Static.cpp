////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Open Space Toolkit ▸ Physics
/// @file           OpenSpaceToolkitPhysicsPy/Coordinate/Frame/Providers/Static.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <OpenSpaceToolkit/Physics/Coordinate/Frame/Providers/Static.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline void                     OpenSpaceToolkitPhysicsPy_Coordinate_Frame_Providers_Static ( )
{

    using namespace boost::python ;

    using ostk::physics::coord::Transform ;
    using ostk::physics::coord::frame::Provider ;
    using ostk::physics::coord::frame::provider::Static ;

    scope in_Static = class_<Static, bases<Provider>>("Static", init<const Transform&>())

        .def("isDefined", &Static::isDefined)

        .def("getTransformAt", &Static::getTransformAt)

    ;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
