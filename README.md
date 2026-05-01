# Public Application Project

###### Last modified: 2026-05-01

This project is open to anyone interested in joining the Programming subteam at
SC Robotics. Complete the project and submit your solution to be considered for
membership on the team.

## Getting Started

If you don't have a GitHub account, you'll have to make one before continuing.

1.  Fork this repository onto your GitHub account.
2.  Clone the forked repo onto your computer so you can work on it.
3.  Create a new branch named `submission/<your GitHub username>`. As you
    complete the project, commit to this new branch.

*   You may implement your solution either in Python or C++. There is a
    subdirectory for each containing resources and an entrypoint; this is where
    you'll put your code. You do not need to complete the project using both
    languages.
*   Annotate your code while you write, describing your design decisions and
    thought processes as you work.
*   You may use any tools you wish, including LLMs, but you'll be expected to
    have a thorough understanding of any code you submit.
*   Feel free to give the project your own spin if you think you have a
    creative idea or a cool solution that you want to implement. You may add
    things to the driver as long as you retain the existing testcases.

## The Problem

Several robots with either circular or rectangular chassis of arbitrary size
are placed on a two-dimensional field. Your goal is to develop a system capable
of determining at any given time whether any two robots are colliding with each
other.

*   Create classes `CircularRobot` and `RectangularRobot` which inherit from a
    class `Robot`.
*   `CircularRobot` should instantiate with its center position (x, y) and its
    radius.
*   `RectangularRobot` should instantiate with its center position (x, y), and
    its width and height.
*   Write a function `is_colliding(Robot a, Robot b)` to determine
    whether any two colliders are in contact.
    *   Hint: The math that actually checks for a collision shouldn't
        necessarily live within this specific function.

## Testcases

Whether you chose C++ or Python, there is an entrypoint driver written for you
to use. Be sure to follow the API implied by the function calls in the driver
so that your solution can work. The testcases specified in the driver are
designed to thoroughly test your solution. Specific instructions and guidance
for completing the project in either language exist in the subdirectories.

## Submission Instructions

1.  Make sure your code is well-documented and that you've described your
    thought processes.
2.  When you're done working, make sure to commit and push the latest version
    to the fork on your GitHub account.
3.  Open a pull request. In the description, make sure to include your name or
    another way we can identify you.
4.  Fill out the application form
    [here](https://jeweled-lillipilli-a32.notion.site/32c0f8e4ef3e8056a2bfee694c962943).
    Its purpose is just to help us get a better idea of who you are.
5.  If you have any questions or comments, reach out to the programming lead in
    the Discord.

Thank you for your interest in the Programming subteam!
