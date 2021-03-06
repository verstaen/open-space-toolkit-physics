################################################################################################################################################################

# @project        Open Space Toolkit ▸ Physics
# @file           bindings/python/test/time/test_duration.py
# @author         Lucas Brémond <lucas@loftorbital.com>
# @license        Apache License 2.0

################################################################################################################################################################

import pytest

from ostk.physics.units import Time
from ostk.physics.time import Instant
from ostk.physics.time import Duration

################################################################################################################################################################

def test_duration_undefined ():

    assert Duration.undefined() is not None

################################################################################################################################################################

def test_duration_zero ():

    assert Duration.zero() is not None

################################################################################################################################################################

def test_duration_nanoseconds ():

    assert Duration.nanoseconds(123.456) is not None

################################################################################################################################################################

def test_duration_microseconds ():

    assert Duration.microseconds(123.456) is not None

################################################################################################################################################################

def test_duration_milliseconds ():

    assert Duration.milliseconds(123.456) is not None

################################################################################################################################################################

def test_duration_seconds ():

    assert Duration.seconds(123.456) is not None

################################################################################################################################################################

def test_duration_minutes ():

    assert Duration.minutes(123.456) is not None

################################################################################################################################################################

def test_duration_hours ():

    assert Duration.hours(123.456) is not None

################################################################################################################################################################

def test_duration_days ():

    assert Duration.days(123.456) is not None

################################################################################################################################################################

def test_duration_weeks ():

    assert Duration.weeks(123.456) is not None

################################################################################################################################################################

def test_duration_between ():

    assert Duration.between(Instant.now(), Instant.now()) is not None

################################################################################################################################################################

def test_duration_parse ():

    assert Duration.parse('02:03.456.000.000') is not None
    assert Duration.parse('02:03.456.000.000', Duration.Format.Standard) is not None
    assert Duration.parse('PT2M3.456S', Duration.Format.ISO8601) is not None

################################################################################################################################################################

def test_duration_operators ():

    duration_A = Duration.seconds(123)
    duration_B = Duration.seconds(456)

    assert (duration_A == duration_B) is not None
    assert (duration_A != duration_B) is not None

    assert (duration_A < duration_B) is not None
    assert (duration_A <= duration_B) is not None
    assert (duration_A > duration_B) is not None
    assert (duration_A >= duration_B) is not None

    assert (duration_A + duration_B) is not None
    assert (duration_A - duration_B) is not None

    assert (duration_A * 2.0) is not None
    assert (duration_A / 2.0) is not None

    duration_A += duration_B
    duration_A -= duration_B

    duration_A *= 2.0
    duration_A /= 2.0

################################################################################################################################################################

def test_duration_is_defined ():

    assert Duration.seconds(123).is_defined() is not None

################################################################################################################################################################

def test_duration_is_zero ():

    assert Duration.seconds(123).is_zero() is not None

################################################################################################################################################################

def test_duration_is_positive ():

    assert Duration.seconds(123).is_positive() is not None

################################################################################################################################################################

def test_duration_is_strictly_positive ():

    assert Duration.seconds(123).is_strictly_positive() is not None

################################################################################################################################################################

def test_duration_is_near ():

    assert Duration.seconds(123).is_near(Duration.seconds(123), Duration.zero()) is not None

################################################################################################################################################################

def test_duration_get_nanoseconds ():

    assert Duration.seconds(123).get_nanoseconds() is not None

################################################################################################################################################################

def test_duration_get_microseconds ():

    assert Duration.seconds(123).get_microseconds() is not None

################################################################################################################################################################

def test_duration_get_milliseconds ():

    assert Duration.seconds(123).get_milliseconds() is not None

################################################################################################################################################################

def test_duration_get_seconds ():

    assert Duration.seconds(123).get_seconds() is not None

################################################################################################################################################################

def test_duration_get_minutes ():

    assert Duration.seconds(123).get_minutes() is not None

################################################################################################################################################################

def test_duration_get_hours ():

    assert Duration.seconds(123).get_hours() is not None

################################################################################################################################################################

def test_duration_get_days ():

    assert Duration.seconds(123).get_days() is not None

################################################################################################################################################################

def test_duration_get_weeks ():

    assert Duration.seconds(123).get_weeks() is not None

################################################################################################################################################################

def test_duration_in_nanoseconds ():

    assert Duration.seconds(123).in_nanoseconds() is not None

################################################################################################################################################################

def test_duration_in_microseconds ():

    assert Duration.seconds(123).in_microseconds() is not None

################################################################################################################################################################

def test_duration_in_milliseconds ():

    assert Duration.seconds(123).in_milliseconds() is not None

################################################################################################################################################################

def test_duration_in_seconds ():

    assert Duration.seconds(123).in_seconds() is not None

################################################################################################################################################################

def test_duration_in_minutes ():

    assert Duration.seconds(123).in_minutes() is not None

################################################################################################################################################################

def test_duration_in_hours ():

    assert Duration.seconds(123).in_hours() is not None

################################################################################################################################################################

def test_duration_in_days ():

    assert Duration.seconds(123).in_days() is not None

################################################################################################################################################################

def test_duration_in_weeks ():

    assert Duration.seconds(123).in_weeks() is not None

################################################################################################################################################################

def test_duration_in_unit ():

    assert Duration.seconds(123).in_unit(Time.Unit.Second) is not None

################################################################################################################################################################

def test_duration_get_absolute ():

    assert Duration.seconds(123).get_absolute() is not None

################################################################################################################################################################

def test_duration_to_string ():

    assert Duration.seconds(123).to_string() is not None
    assert Duration.seconds(123).to_string(Duration.Format.Standard)
    assert Duration.seconds(123).to_string(Duration.Format.ISO8601)

################################################################################################################################################################
