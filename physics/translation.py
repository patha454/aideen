"""
`rotation.py` provides a basic Newtonian translation engine.

Author
------
H Paterson

Copyright
---------
BSL-1
"""

from numpy import zeros  # type: ignore


# (-Too few public methods) pylint: disable=R0903
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
        Creates a new `Translation` instance at rest: Zero displacement, zero
        velocity, zero acceleration.
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
        self.velocity += self.acceleration * delta
