////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Open Space Toolkit ▸ Physics
/// @file           OpenSpaceToolkit/Physics/Data/Providers/Nadir.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <OpenSpaceToolkit/Physics/Data/Providers/Nadir.hpp>
#include <OpenSpaceToolkit/Physics/Coordinate/Spherical/LLA.hpp>

#include <OpenSpaceToolkit/Core/Error.hpp>
#include <OpenSpaceToolkit/Core/Utilities.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace ostk
{
namespace physics
{
namespace data
{
namespace providers
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Direction                       Nadir                                       (   const   Position&                   aPosition,
                                                                                const   Celestial&                  aCelestialObject,
                                                                                const   Environment&                anEnvironment                               )
{

    using ostk::physics::coord::spherical::LLA ;

    if (!aPosition.isDefined())
    {
        throw ostk::core::error::runtime::Undefined("Position") ;
    }

    if (!aCelestialObject.isDefined())
    {
        throw ostk::core::error::runtime::Undefined("Celestial object") ;
    }

    if (!anEnvironment.isDefined())
    {
        throw ostk::core::error::runtime::Undefined("Environment") ;
    }

    const LLA lla = LLA::Cartesian(aPosition.inFrame(aCelestialObject.accessFrame(), anEnvironment.getInstant()).getCoordinates(), aCelestialObject.getEquatorialRadius(), aCelestialObject.getFlattening()) ;

    const Shared<const Frame> nedFrameSPtr = aCelestialObject.getFrameAt(lla, Celestial::FrameType::NED) ;

    const Vector3d z_NED_FIXED = nedFrameSPtr->getAxesIn(aCelestialObject.accessFrame(), anEnvironment.getInstant()).z() ;

    return { z_NED_FIXED, aCelestialObject.accessFrame() } ;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
