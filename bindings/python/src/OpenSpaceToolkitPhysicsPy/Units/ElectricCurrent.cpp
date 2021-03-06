////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Open Space Toolkit ▸ Physics
/// @file           bindings/python/src/OpenSpaceToolkitPhysicsPy/Units/ElectricCurrent.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <OpenSpaceToolkitPhysicsPy/Utilities/IterableConverter.hpp>

#include <OpenSpaceToolkit/Physics/Units/ElectricCurrent.hpp>

#include <OpenSpaceToolkit/Mathematics/Objects/Interval.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS (OpenSpaceToolkitPhysicsPy_Units_ElectricCurrent_toString_overloads, ostk::physics::units::ElectricCurrent::toString, 0, 1)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS (OpenSpaceToolkitPhysicsPy_Units_ElectricCurrent_Interval_toString_overloads, ostk::math::obj::Interval<ostk::physics::units::ElectricCurrent>::toString, 0, 1)

inline void                     OpenSpaceToolkitPhysicsPy_Units_ElectricCurrent      ( )
{

    using namespace boost::python ;

    using ostk::core::types::Real ;

    using ostk::physics::units::ElectricCurrent ;

    scope in_ElectricCurrent = class_<ElectricCurrent>("ElectricCurrent", init<Real, ElectricCurrent::Unit>())

        .def(self == self)
        .def(self != self)

        // .def(self < self)
        // .def(self <= self)
        // .def(self > self)
        // .def(self >= self)

        // .def(self + self)
        // .def(self - self)

        // .def(self * other<Real>())
        // .def(self / other<Real>())

        // .def(self += self)
        // .def(self -= self)

        // .def(self *= other<Real>())
        // .def(self /= other<Real>())

        // .def(self_ns::str(self_ns::self))

        .def("__repr__", +[] (const ElectricCurrent& aElectricCurrent) -> std::string { return aElectricCurrent.toString() ; })

        .def("is_defined", &ElectricCurrent::isDefined)

        .def("get_unit", &ElectricCurrent::getUnit)
        .def("in_unit", &ElectricCurrent::in)
        .def("in_amperes", &ElectricCurrent::inAmperes)
        .def("to_string", &ElectricCurrent::toString, OpenSpaceToolkitPhysicsPy_Units_ElectricCurrent_toString_overloads())

        .def("undefined", &ElectricCurrent::Undefined).staticmethod("undefined")
        .def("amperes", &ElectricCurrent::Amperes).staticmethod("amperes")
        // .def("parse", &ElectricCurrent::Parse).staticmethod("parse")
        .def("string_from_unit", &ElectricCurrent::StringFromUnit).staticmethod("string_from_unit")
        .def("symbol_from_unit", &ElectricCurrent::SymbolFromUnit).staticmethod("symbol_from_unit")

    ;

    enum_<ElectricCurrent::Unit>("Unit")

        .value("Undefined", ElectricCurrent::Unit::Undefined)
        .value("Ampere", ElectricCurrent::Unit::Ampere)

    ;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
