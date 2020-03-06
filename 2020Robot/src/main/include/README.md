This is a short term patch to the intellisense problem. Just take all these headers and slap them into the same folder as robot.h in your project. It covers CTRE, REV (motors and color sensors) and WPI headers. You still have to install the vendor libraries like normal for everything to build properly, these headers are just to help out intellisense.

I think I've found the root cause of the problem but it's going to take a couple of days of testing before I am ready to make a pull request with the fix.
