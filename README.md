# Public Application Project

###### Last modified: 2026-04-24

This project is open to anyone interested in joining the Programming subteam at
SC Robotics. Complete the project and submit your solution to be considered for
membership on the team.

## Getting Started

If you don't have a GitHub account, you'll have to make one before continuing.

1.  Fork this repository onto your GitHub account.
2.  Clone the forked repo onto your computer so you can work on it.
3.  Create a new branch with a unique name, such as your name or username. As
    you complete the project, commit to this new branch.

-   You may use any programming language of your choice to implement your
    solution.
-   Annotate your code while you write, describing your design decisions and
    thought processes as you work.

## The Problem

Two robots, one with a circular chassis and one with a rectangular chassis must
make their way past a set of obstacles. The obstacles are rectangular and
circular objects of arbitrary size. Your goal is to develop a system capable of
determining at any givern time whether a robot is colliding with an obstacle.

*   Create classes `CircleCollider`, and `RectCollider`, which inherit from a
    class `Colider`.
*   `CircleCollider` should instantiate with its center position (x, y) and its
    radius.
*   `RectCollider` should instantiate with its center position (x, y), and its
    width and height.
*   Create classes `CircularRobot` and `RectangularRobot` which inherit from
    `CircleCollider` and `RectCollider` respectively.
*   Similarly, create classes `CircularObstacle` and `RectangularObstacle`.
*   Write a function `is_colliding(Collider a, Collider b)` to determine
    whether any two colliders are in contact.
    *   Hint: The math that actually checks for a collision shouldn't
        necessarily live within this specific function.
*   Make it possible for a robot to quickly calculate the distance and heading
    to an obstacle or another robot.
    *   Distance should be calculated as the Euclidean distance between the
        centers of the two objects.
    *   Heading should be calculated as a number in degrees counterclockwise
        from east (as on a unit circle).

## Testcases

Create an entrypoint for your program which creates the following objects and
performs the following calculations, and displays each result to the user.

Create the following robots and obstacles:\
*Note: a copy-and-paste-friendly version of these coordinates exists in
`testcases.txt`.*

*   A `CircularRobot` `circlebot` with `x = 12.5`, `y = -2.5`, `r = 2`.
*   A `RectangularRobot` `rectbot` with `x = -5`, `y = 5`, `w = 5.5`, `h = 13`.
*   Circular obstacles:
    *   `c1` with `x = 1.5`, `y = 14.5`, `r = 4`.
    *   `c2` with `x = 2.5`, `y = -22.5`, `r = 20`.
    *   `c3` with `x = -13.2`, `y = -0.8`, `r = 0.5`.
*   Rectangular obstacles:
    *   `r1` with `x = 12.5`, `y = 7.5`, `w = 2`, `h = 16.2`.
    *   `r2` with `x = -15.5`, `y = 6.5`, `w = 4`, `h = 14`.
    *   `r3` with `x = 2.5`, `y = 4.5`, `w = 5`, `h = 9`.
    *   `r4` with `x = -7.5`, `y = 20.5`, `w = 10`, `h = 4`.
    *   `r5` with `x = -10`, `y = 4.5`, `w = 7`, `h = 3`.

Perform the following operations and display the results:

1.  Is `circlebot` colliding with `r1`?
2.  Is `circlebot` colliding with `c2`?
3.  Is `rectbot` colliding with `c1`?
4.  Is `rectbot` colliding with `r4`?
5.  Is `rectbot` colliding with `r5`?
6.  Is `c1` colliding with `r4`?
7.  Is `c3` colliding with `r2`?
8.  Is `r2` colliding with `r5`?
9.  Calculate the distance and heading from `circlebot` to `r3`.
10. Calculate the distance and heading from `circlebot` to `r1`.
11. Calculate the distance and heading from `rectbot` to `c2`.

## Submission Instructions

1.  Add enough documentation that we can figure out how to build and test your
    solution.
2.  When you're done working, make sure to commit and push the latest version
    to the fork on your GitHub account.
3.  Open a pull request. In the description, make sure to include your name or
    another way we can identify you.
4.  If you don't hear back after a few days, reach out to the programming lead
    in the Discord.

Thank you for your interest in the Programming subteam!

