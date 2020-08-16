"""
`rotation.py` provides a basic Newtonian rotation engine.

Author
------
H Paterson

Copyright
---------
BSL-1
"""

from math import pi
from numpy import zeros  # type: ignore


# (-Too few public methods) pylint: disable=R0903
class Rotation:
    """
    `Rotation` defines an object's rotation in Cartesian 3-space, and how the rotation is changing

    Attributes
    ----------
    angle: numpy.ndarray
        The orientation (in radians) about the axis of reference.
    angular_frequency: numpy.ndarray
        The rate the orientation is changing (in rad / s).
    angular_acceleration: numpy.ndarray
        The angular acceleration of the object (in rad / s).
    """

    def __init__(self) -> None:
        """
        Creates a new `Rotation` instance at rest: Zero angle, zero angular
        frequency, zero angular acceleration.
        """

        self.angle = zeros(3)
        self.angular_frequency = zeros(3)
        self.angular_acceleration = zeros(3)

    def update(self, delta: float) -> None:
        """
        Updates the rotation and angular frequency, assuming a constant angular acceleration.

        Parameters
        ----------
        delta: float
            The time, in seconds, to assume the object has been in motion for.
        """

        self.angle += (self.angular_frequency * delta) % (2 * pi)
        self.angular_frequency += (self.angular_acceleration * delta) % (2 * pi)
