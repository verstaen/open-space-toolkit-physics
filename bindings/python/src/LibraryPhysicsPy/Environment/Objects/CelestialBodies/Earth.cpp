////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Open Space Toolkit ▸ Physics
/// @file           OpenSpaceToolkitPhysicsPy/Environment/Objects/CelestialBodies/Earth.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <OpenSpaceToolkit/Physics/Environment/Objects/CelestialBodies/Earth.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline void                     OpenSpaceToolkitPhysicsPy_Environment_Objects_CelestialBodies_Earth ( )
{

    using namespace boost::python ;

    using ostk::core::types::Real ;
    using ostk::core::types::Shared ;

    using ostk::physics::units::Length ;
    using ostk::physics::units::Derived ;
    using ostk::physics::time::Instant ;
    using ostk::physics::env::Ephemeris ;
    using ostk::physics::env::obj::Celestial ;
    using ostk::physics::env::obj::celest::Earth ;
    using EarthGravitationalModel = ostk::physics::environment::gravitational::Earth ;
    using EarthMagneticModel = ostk::physics::environment::magnetic::Earth ;

    scope in_Earth = class_<Earth, bases<Celestial>>("Earth", init<const Derived&, const Length&, const Real&, const Real&, const Shared<Ephemeris>&, const EarthGravitationalModel::Type&, const EarthMagneticModel::Type&, const Instant&>())

        .def_readonly("GravitationalParameter", &Earth::GravitationalParameter)
        .def_readonly("EquatorialRadius", &Earth::EquatorialRadius)
        .def_readonly("Flattening", &Earth::Flattening)
        .def_readonly("C20", &Earth::C20)
        .def_readonly("J2", &Earth::J2)

        .def(self_ns::str(self_ns::self))
        .def(self_ns::repr(self_ns::self))

        .def("Default", &Earth::Default).staticmethod("Default")
        .def("EGM2008", &Earth::EGM2008).staticmethod("EGM2008")
        .def("WGS84_EGM96", &Earth::WGS84_EGM96).staticmethod("WGS84_EGM96")
        .def("EGM96", &Earth::EGM96).staticmethod("EGM96")
        .def("WGS84", &Earth::WGS84).staticmethod("WGS84")

    ;

    scope in_Models = class_<Earth::Models>("Models", no_init) ;

    class_<Earth::Models::EGM2008>("EGM2008", no_init)

        .def_readonly("GravitationalParameter", &Earth::Models::EGM2008::GravitationalParameter)
        .def_readonly("EquatorialRadius", &Earth::Models::EGM2008::EquatorialRadius)
        .def_readonly("Flattening", &Earth::Models::EGM2008::Flattening)
        .def_readonly("C20", &Earth::Models::EGM2008::C20)
        .def_readonly("J2", &Earth::Models::EGM2008::J2)

    ;

    class_<Earth::Models::WGS84_EGM96>("WGS84_EGM96", no_init)

        .def_readonly("GravitationalParameter", &Earth::Models::WGS84_EGM96::GravitationalParameter)
        .def_readonly("EquatorialRadius", &Earth::Models::WGS84_EGM96::EquatorialRadius)
        .def_readonly("Flattening", &Earth::Models::WGS84_EGM96::Flattening)
        .def_readonly("C20", &Earth::Models::WGS84_EGM96::C20)
        .def_readonly("J2", &Earth::Models::WGS84_EGM96::J2)

    ;

    class_<Earth::Models::EGM96>("EGM96", no_init)

        .def_readonly("GravitationalParameter", &Earth::Models::EGM96::GravitationalParameter)
        .def_readonly("EquatorialRadius", &Earth::Models::EGM96::EquatorialRadius)
        .def_readonly("Flattening", &Earth::Models::EGM96::Flattening)
        .def_readonly("C20", &Earth::Models::EGM96::C20)
        .def_readonly("J2", &Earth::Models::EGM96::J2)

    ;

    class_<Earth::Models::WGS84>("WGS84", no_init)

        .def_readonly("GravitationalParameter", &Earth::Models::WGS84::GravitationalParameter)
        .def_readonly("EquatorialRadius", &Earth::Models::WGS84::EquatorialRadius)
        .def_readonly("Flattening", &Earth::Models::WGS84::Flattening)
        .def_readonly("C20", &Earth::Models::WGS84::C20)
        .def_readonly("J2", &Earth::Models::WGS84::J2)

    ;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
