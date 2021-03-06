////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Open Space Toolkit ▸ Physics
/// @file           bindings/python/src/OpenSpaceToolkitPhysicsPy/Time/Scale.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <OpenSpaceToolkit/Physics/Time/Scale.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline void                     OpenSpaceToolkitPhysicsPy_Time_Scale                 ( )
{

    using namespace boost::python ;

    using ostk::physics::time::Scale ;

    enum_<Scale>("Scale")

        .value("Undefined", Scale::Undefined)
        .value("UTC", Scale::UTC)
        .value("TT", Scale::TT)
        .value("TAI", Scale::TAI)
        .value("UT1", Scale::UT1)
        .value("TCG", Scale::TCG)
        .value("TCB", Scale::TCB)
        .value("TDB", Scale::TDB)
        .value("GMST", Scale::GMST)
        .value("GPST", Scale::GPST)
        .value("GST", Scale::GST)
        .value("GLST", Scale::GLST)
        .value("BDT", Scale::BDT)
        .value("QZSST", Scale::QZSST)
        .value("IRNSST", Scale::IRNSST)

    ;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
