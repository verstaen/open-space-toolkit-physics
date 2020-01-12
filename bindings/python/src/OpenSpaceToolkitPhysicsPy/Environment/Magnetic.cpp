////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Open Space Toolkit ▸ Physics
/// @file           bindings/python/src/OpenSpaceToolkitPhysicsPy/Environment/Magnetic.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <OpenSpaceToolkitPhysicsPy/Environment/Magnetic/Earth.cpp>
#include <OpenSpaceToolkitPhysicsPy/Environment/Magnetic/Dipole.cpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline void                     OpenSpaceToolkitPhysicsPy_Environment_Magnetic       ( )
{

    boost::python::object module(boost::python::handle<>(boost::python::borrowed(PyImport_AddModule("ostk.physics.environment.magnetic")))) ;

    boost::python::scope().attr("magnetic") = module ;

    boost::python::scope scope = module ;

    OpenSpaceToolkitPhysicsPy_Environment_Magnetic_Dipole() ;
    OpenSpaceToolkitPhysicsPy_Environment_Magnetic_Earth() ;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////