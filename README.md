# Aideen

Aideen is a close loop fly-by-wire (or "drive/sail/move-by-wire") control system.

The fundamental problem Aideen aims to solve is "given an object with a velocity, subject to arbitrary forces, what forces are required to move the object to a new velocity?"

## Design Principals

1. High Reliability.

    - Aideen is flight software, at least in principle, and needs to be highly reliability. Ideally any code that compiles using Aideen would be guaranteed to never crash, and always work as intended. Aideen aims to prevent as many common causes of failure as possible using:

    1. No dynamic allocation.

        - Aideen should never allocate memory dynamically - required memory must be allocated by the user and passed to Aideen at initialization time, so the user can check for a single point of allocation failures.

    2. Aggressive use of `assert` statements and unit testing.

        - Aideen should be able to catch as many invalid use cases as possible during debugging, to catch possible bugs early, before deployment.

    3. Hide internal details.

        - The user should never be able to modify Aideen data directly - the user may provide invalid inputs, structure layouts may change between versions, the user may try to modify data at unexpected times while Aideen is using it. All requests to set and read Aideen data should be forced through exported function which can check for correct usage, and use opaque handles to data the user can not readily modify.