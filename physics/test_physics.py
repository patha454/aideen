"""
`physics_test.py` provides unit tests for the physics engine.

Author
------
H Paterson.

Copyright
---------
BSL-1.0.
"""

import unittest
from numpy import array  # type: ignore
from physics import translation
from physics import rotation


class TranslationTests(unittest.TestCase):
    """
    Tests the `Translation` class.
    """

    def setUp(self) -> None:
        """
        Creates a test `Translation` object for the testing.
        """

        self.translation = translation.Translation()

    def test_basic(self) -> None:
        """
        Test a basic case of translation: Steady acceleration of 1 m/s^2
        for one second.
        """

        self.translation.acceleration = array([1, 0, 0])
        self.translation.update(1)
        self.assertListEqual(self.translation.acceleration.tolist(), [1, 0, 0])
        self.assertListEqual(self.translation.velocity.tolist(), [1, 0, 0])
        self.assertListEqual(self.translation.displacement.tolist(), [0, 0, 0])


class RotationTests(unittest.TestCase):
    """
    Tests the `Rotation` class.
    """

    def setUp(self) -> None:
        """
        Creates a test `Rotation` object for the tests.
        """

        self.rotation = rotation.Rotation()

    def test_basic(self) -> None:
        """
        Tests a basic case of translation: Steady acceleration of 1 rad / s ^2
        for one second.
        """

        self.rotation.angular_acceleration = array([1, 0, 0])
        self.rotation.update(1)
        self.assertListEqual(self.rotation.angular_acceleration.tolist(), [1, 0, 0])
        self.assertListEqual(self.rotation.angular_frequency.tolist(), [1, 0, 0])
        self.assertListEqual(self.rotation.angle.tolist(), [0, 0, 0])
