////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Open Space Toolkit ▸ Physics
/// @file           OpenSpaceToolkitPhysicsPy/Units/Time.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <OpenSpaceToolkit/Physics/Units/Time.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS (OpenSpaceToolkitPhysicsPy_Units_Time_toString_overloads, ostk::physics::units::Time::toString, 0, 1)

inline void                     OpenSpaceToolkitPhysicsPy_Units_Time               ( )
{

    using namespace boost::python ;

    using ostk::core::types::Real ;

    using ostk::physics::units::Time ;

    scope in_Time = class_<Time>("Time", init<Real, Time::Unit>())

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

        .def("__repr__", +[] (const Time& aTime) -> std::string { return aTime.toString() ; })

        .def("isDefined", &Time::isDefined)

        .def("toString", &Time::toString, OpenSpaceToolkitPhysicsPy_Units_Time_toString_overloads())

        .def("Undefined", &Time::Undefined).staticmethod("Undefined")
        .def("StringFromUnit", &Time::StringFromUnit).staticmethod("StringFromUnit")
        .def("SymbolFromUnit", &Time::SymbolFromUnit).staticmethod("SymbolFromUnit")

    ;

    enum_<Time::Unit>("Unit")

        .value("Undefined", Time::Unit::Undefined)
        .value("Nanosecond", Time::Unit::Nanosecond)
        .value("Microsecond", Time::Unit::Microsecond)
        .value("Millisecond", Time::Unit::Millisecond)
        .value("Second", Time::Unit::Second)
        .value("Minute", Time::Unit::Minute)
        .value("Hour", Time::Unit::Hour)
        .value("Day", Time::Unit::Day)
        .value("Week", Time::Unit::Week)

    ;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
