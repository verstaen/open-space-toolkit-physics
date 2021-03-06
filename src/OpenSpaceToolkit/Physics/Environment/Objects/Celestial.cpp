////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Open Space Toolkit ▸ Physics
/// @file           OpenSpaceToolkit/Physics/Environment/Objects/Celestial.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <OpenSpaceToolkit/Physics/Environment/Objects/Celestial.hpp>
#include <OpenSpaceToolkit/Physics/Coordinate/Frame/Utilities.hpp>
#include <OpenSpaceToolkit/Physics/Coordinate/Frame/Providers/Static.hpp>
#include <OpenSpaceToolkit/Physics/Unit.hpp>

#include <OpenSpaceToolkit/Core/Error.hpp>
#include <OpenSpaceToolkit/Core/Utilities.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace ostk
{
namespace physics
{
namespace env
{
namespace obj
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                Celestial::Celestial                        (   const   String&                     aName,
                                                                                const   Celestial::Type&            aType,
                                                                                const   Derived&                    aGravitationalParameter,
                                                                                const   Length&                     anEquatorialRadius,
                                                                                const   Real&                       aFlattening,
                                                                                const   Real&                       aJ2,
                                                                                const   Shared<Ephemeris>&          anEphemeris,
                                                                                const   Shared<GravitationalModel>& aGravitationalModel,
                                                                                const   Shared<MagneticModel>&      aMagneticModel,
                                                                                const   Instant&                    anInstant                                   )
                                :   Object(aName, anInstant),
                                    type_(aType),
                                    gravitationalParameter_(aGravitationalParameter),
                                    equatorialRadius_(anEquatorialRadius),
                                    flattening_(aFlattening),
                                    j2_(aJ2),
                                    ephemeris_(anEphemeris),
                                    gravitationalModelSPtr_(aGravitationalModel),
                                    magneticModelSPtr_(aMagneticModel)
{

}

                                Celestial::Celestial                        (   const   String&                     aName,
                                                                                const   Celestial::Type&            aType,
                                                                                const   Derived&                    aGravitationalParameter,
                                                                                const   Length&                     anEquatorialRadius,
                                                                                const   Real&                       aFlattening,
                                                                                const   Real&                       aJ2,
                                                                                const   Shared<Ephemeris>&          anEphemeris,
                                                                                const   Shared<GravitationalModel>& aGravitationalModel,
                                                                                const   Shared<MagneticModel>&      aMagneticModel,
                                                                                const   Instant&                    anInstant,
                                                                                const   Object::Geometry&           aGeometry                                   )
                                :   Object(aName, anInstant, aGeometry),
                                    type_(aType),
                                    gravitationalParameter_(aGravitationalParameter),
                                    equatorialRadius_(anEquatorialRadius),
                                    flattening_(aFlattening),
                                    j2_(aJ2),
                                    ephemeris_(anEphemeris),
                                    gravitationalModelSPtr_(aGravitationalModel),
                                    magneticModelSPtr_(aMagneticModel)
{

}

                                Celestial::~Celestial                       ( )
{

}

Celestial*                      Celestial::clone                            ( ) const
{
    return new Celestial(*this) ;
}

bool                            Celestial::isDefined                        ( ) const
{
    return Object::isDefined() && (ephemeris_ != nullptr) && ephemeris_->isDefined() ;
}

Shared<const Ephemeris>         Celestial::accessEphemeris                  ( ) const
{

    if (!this->isDefined())
    {
        throw ostk::core::error::runtime::Undefined("Celestial") ;
    }

    return ephemeris_ ;

}

Shared<const GravitationalModel> Celestial::accessGravitationalModel        ( ) const
{

    if (!this->isDefined())
    {
        throw ostk::core::error::runtime::Undefined("Celestial") ;
    }

    return gravitationalModelSPtr_ ;

}

Shared<const MagneticModel>     Celestial::accessMagneticModel              ( ) const
{

    if (!this->isDefined())
    {
        throw ostk::core::error::runtime::Undefined("Celestial") ;
    }

    return magneticModelSPtr_ ;

}

Celestial::Type                 Celestial::getType                          ( ) const
{

    if (!this->isDefined())
    {
        throw ostk::core::error::runtime::Undefined("Celestial") ;
    }

    return type_ ;

}

Derived                         Celestial::getGravitationalParameter         ( ) const
{

    if (!this->isDefined())
    {
        throw ostk::core::error::runtime::Undefined("Celestial") ;
    }

    return gravitationalParameter_ ;

}

Length                          Celestial::getEquatorialRadius              ( ) const
{

    if (!this->isDefined())
    {
        throw ostk::core::error::runtime::Undefined("Celestial") ;
    }

    return equatorialRadius_ ;

}

Real                            Celestial::getFlattening                    ( ) const
{

    if (!this->isDefined())
    {
        throw ostk::core::error::runtime::Undefined("Celestial") ;
    }

    return flattening_ ;

}

Real                            Celestial::getJ2                            ( ) const
{

    if (!this->isDefined())
    {
        throw ostk::core::error::runtime::Undefined("Celestial") ;
    }

    return j2_ ;

}

Shared<const Frame>             Celestial::accessFrame                      ( ) const
{

    if (!this->isDefined())
    {
        throw ostk::core::error::runtime::Undefined("Celestial") ;
    }

    return ephemeris_->accessFrame() ;

}

Position                        Celestial::getPositionIn                    (   const   Shared<const Frame>&        aFrameSPtr                                  ) const
{

    if ((aFrameSPtr == nullptr) || (!aFrameSPtr->isDefined()))
    {
        throw ostk::core::error::runtime::Undefined("Frame") ;
    }

    if (!this->isDefined())
    {
        throw ostk::core::error::runtime::Undefined("Celestial") ;
    }

    return ephemeris_->accessFrame()->getOriginIn(aFrameSPtr, this->accessInstant()) ;

}

Velocity                        Celestial::getVelocityIn                    (   const   Shared<const Frame>&        aFrameSPtr                                  ) const
{
    return Velocity::MetersPerSecond(this->getTransformTo(aFrameSPtr).applyToVelocity(Vector3d::Zero(), Vector3d::Zero()), aFrameSPtr) ;
}

Transform                       Celestial::getTransformTo                   (   const   Shared<const Frame>&        aFrameSPtr                                  ) const
{

    if ((aFrameSPtr == nullptr) || (!aFrameSPtr->isDefined()))
    {
        throw ostk::core::error::runtime::Undefined("Frame") ;
    }

    if (!this->isDefined())
    {
        throw ostk::core::error::runtime::Undefined("Celestial") ;
    }

    return ephemeris_->accessFrame()->getTransformTo(aFrameSPtr, this->accessInstant()) ;

}

Axes                            Celestial::getAxesIn                        (   const   Shared<const Frame>&        aFrameSPtr                                  ) const
{

    if ((aFrameSPtr == nullptr) || (!aFrameSPtr->isDefined()))
    {
        throw ostk::core::error::runtime::Undefined("Frame") ;
    }

    if (!this->isDefined())
    {
        throw ostk::core::error::runtime::Undefined("Celestial") ;
    }

    return ephemeris_->accessFrame()->getAxesIn(aFrameSPtr, this->accessInstant()) ;

}

Vector                          Celestial::getGravitationalFieldAt          (   const   Position&                   aPosition                                   ) const
{

    using ostk::physics::Unit ;
    using ostk::physics::units::Time ;

    if (!aPosition.isDefined())
    {
        throw ostk::core::error::runtime::Undefined("Position") ;
    }

    if (!this->isDefined())
    {
        throw ostk::core::error::runtime::Undefined("Celestial") ;
    }

    if (gravitationalModelSPtr_ == nullptr)
    {
        throw ostk::core::error::runtime::Undefined("Gravitational model") ;
    }

    const Vector3d positionInBodyFrame = aPosition.inFrame(ephemeris_->accessFrame(), this->accessInstant()).getCoordinates() ;

    const Vector3d gravitationalFieldValue = gravitationalModelSPtr_->getFieldValueAt(positionInBodyFrame, this->accessInstant()) ;

    const static Unit gravitationalFieldUnit = Unit::Derived(Derived::Unit::Acceleration(Length::Unit::Meter, Time::Unit::Second)) ;

    return { gravitationalFieldValue, gravitationalFieldUnit, ephemeris_->accessFrame() } ;

}

Vector                          Celestial::getMagneticFieldAt               (   const   Position&                   aPosition                                   ) const
{

    using ostk::physics::Unit ;
    using ostk::physics::units::Time ;

    if (!aPosition.isDefined())
    {
        throw ostk::core::error::runtime::Undefined("Position") ;
    }

    if (!this->isDefined())
    {
        throw ostk::core::error::runtime::Undefined("Celestial") ;
    }

    if (magneticModelSPtr_ == nullptr)
    {
        throw ostk::core::error::runtime::Undefined("Magnetic model") ;
    }

    const Vector3d positionInBodyFrame = aPosition.inFrame(ephemeris_->accessFrame(), this->accessInstant()).getCoordinates() ;

    const Vector3d magneticFieldValue = magneticModelSPtr_->getFieldValueAt(positionInBodyFrame, this->accessInstant()) ;

    const static Unit magneticFieldUnit = Unit::Derived(Derived::Unit::Tesla()) ;

    return { magneticFieldValue, magneticFieldUnit, ephemeris_->accessFrame() } ;

}

Shared<const Frame>             Celestial::getFrameAt                       (   const   LLA&                        aLla,
                                                                                const   Celestial::FrameType&       aFrameType                                  ) const
{

    using StaticProvider = ostk::physics::coord::frame::provider::Static ;

    if (!aLla.isDefined())
    {
        throw ostk::core::error::runtime::Undefined("LLA") ;
    }

    if (!this->isDefined())
    {
        throw ostk::core::error::runtime::Undefined("Celestial") ;
    }

    switch (aFrameType)
    {

        case Celestial::FrameType::NED:
        {

            const String frameName = String::Format("{} NED @ {}", this->accessName(), aLla.toString()) ;

            if (const auto frameSPtr = Frame::WithName(frameName))
            {
                return frameSPtr ;
            }

            const Transform transform = ostk::physics::coord::frame::utilities::NorthEastDownTransformAt(aLla, this->getEquatorialRadius(), this->getFlattening()) ;

            const Shared<const Frame> nedSPtr = Frame::Construct(frameName, false, ephemeris_->accessFrame(), std::make_shared<const StaticProvider>(transform)) ;

            return nedSPtr ;

        }

        default:
            throw ostk::core::error::runtime::Wrong("Frame type") ;
            break ;

    }

    return nullptr ;

}

// Object::Geometry                Celestial::getTerminatorGeometry            ( ) const
// {

//     if (!this->isDefined())
//     {
//         throw ostk::core::error::runtime::Undefined("Celestial") ;
//     }

//     sss

// }

Celestial                       Celestial::Undefined                        ( )
{
    return { String::Empty(), Celestial::Type::Undefined, Derived::Undefined(), Length::Undefined(), Real::Undefined(), Real::Undefined(), nullptr, nullptr, nullptr, Instant::Undefined() } ;
}

String                          Celestial::StringFromFrameType              (   const   Celestial::FrameType&       aFrameType                                  )
{

    switch (aFrameType)
    {

        case Celestial::FrameType::Undefined:
            return "Undefined" ;

        case Celestial::FrameType::NED:
            return "NED" ;

        default:
            throw ostk::core::error::runtime::Wrong("Frame type") ;
            break ;

    }

    return String::Empty() ;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
