# PROS TEMPLATE

To start you off, you must download PROS and git.

DOWNLOAD PROS: https://github.com/purduesigbots/pros-cli3/releases (pros-windows-3.1.4.0-64bit.exe)

DOWNLOAD GIT: https://git-scm.com/downloads

Then you must fork this repository. Make sure that you have a github account. Click the Fork button near the top of this page. Once it has been forked into your account, click the Clone or download button. Click the little copy button next to the URL it gives you. Then open up Git Bash. You should see a terminal open. Then type in "git clone" followed by the link you copied. Click enter and it should download the folder to your computer somewhere. Locate it in file explorer, open it, then click the project.pros file. It should open in PROS, and then you are all set!

Once your repository has been created, you can easily make changes to the code which will then be synced to github. You will then be able to access you code anywhere, see the full history of your code, easily revert to previous versions, and even create "branches" of the code to make and test changes. Multiple people can work on the code at the same time, as long as you aren't making any conflicting changes. This is the beauty of integrating github with your team's code.

So first you have to have your code open in PROS. Open the opcontrol.cpp file in the src folder. Try making a small change to the code and then saving the file. Once you do so, press the button labeled git in the very bottom left hand corner. This should open a side panel on the right hand side. At the top of this panel is a section entitled "Unstaged Changes". This section shows all of the files that you have made changes to. You should see src/opcontrol.cpp listed in this section if you did indeed make a change to the file and save it. If you do, click the stage all button in the top right hand corner of the panel. Type a message in the text box that says the changes you made, then click the Commit to master button. You should then see a new button appear in the bottom left hand corner entitled "Push" with a number next to it. Click that button. Once it finishes loading, the code should have been uploaded to github! You should be able to see the change reflected on the website if you open up the opcontrol.cpp file online.

If you want to modify your code, but you want to make a copy of your original code to revert to, or you want to separate your code into different paths, you can make a branch. A branch is an alternate version of your code. Branches work by looking at the origin of the split and calculating commits from that point. Here is an example of the use of branches: You have a driver code for a robot. You decide you want to add a new function to automatically shoot a ball. You create a brance and call it "shootBall". Meanwhile, you make some changes on the master branch which adjust the speed of your intake. You finish writing and testing the code and want to add it to the master branch. You can then merge the "shootBall" branch to the master branch, without needing to rewrite the changes to your intake.

To make a branch, click on the little branch button at the bottom of the screen. Now click the New Branch button, and name it your choice. Now, any new commits will be saved to that branch! A good practice with branches is to have your master branch always working and without errors. If you are doing major construction or changes, pull it off to a different branch, and when you are done merge back into the master.

-----------------------------------------------------------------------------------------------------

The API is a great place for you to figure out this new language. I still use it frequently whenever
I forget the how to do something.

API: https://pros.cs.purdue.edu/v5/api/cpp/index.html

------------------------------------------------------------------------------------------------------

You might be concerned about how many files there are, but don't worry. The only files you need to worry
about are all the ones in the src folder and the declareStuff file in the include folder. The src folder
is where you can put all the code that you actually write. Inside you will find four files: autonomous.cpp,
functions.cpp, initialize.cpp, and opcontrol.cpp. What exactly these files are used for is explained Inside
the file itself. The declareStuff.hpp file in the include folder holds everything you want to share between
files, such as motors or variables.

-------------------------------------------------------------------------------------------------------

If you are transitioning from RobotC, you might be wondering how to compile and download the program to the
brain. If you changed any of the header files in the include folder, you must click PROS in the ribbon, then
click Build, then click All. If not, then you can just click the graphical Build-Pros-Project button. You have
to do this every time before downloading the code. Once it successfully completes, you can download the code
by pressing the "Upload PROS Project" button. Then you are ready to go!

--------------------------------------------------------------------------------------------------------

Here's a link to document which lists all of the stuff you need to know to start programming. This is very helpful.
https://docs.google.com/document/d/1O8CkgUyPWN54VRublCWZ8JdiwJlctUDuPkCKcbtpmrA/edit?usp=sharing
