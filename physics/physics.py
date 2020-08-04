"""
`physics.py` provides a basic Newtonian physics engine.

Author
------
H Paterson

Copyright
---------
BSL-1.0.
"""

from math import pi
# type: ignore
from numpy import zeros


class Translation:
    """
    `Translation` defines an object's position in Cartesian 3-space, and how the position is
    changing.

    Attributes
    ----------
    displacement: numpy.ndarry
        The position of the object (in meters) from a position of reference
    velocity: numpy.ndarray
        The rate the position is changing (in meters) from a position of reference
    acceleration: numpy.ndarray
        The rate the velocity is changing (in meters per second).
    """

    def __init__(self) -> None:
        """

        """

        self.displacement = zeros(3)
        self.velocity = zeros(3)
        self.acceleration = zeros(3)

    def update(self, delta: float) -> None:
        """
        Updates the displacement and velocity assuming a constant acceleration

        Parameters
        ----------
        delta: float
            The time, in seconds, to assume the object has been in motion for.
        """

        self.displacement += self.velocity * delta
        self.acceleration += self.acceleration * delta


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