# Graduate Student Admissions System
Written by: Chris Rosenauer and Yuchun He


# Contents

 * Overview
 * Additional Features
 * IDE Usage Notes
 * Compilation with Makefile
 * Future Improvements


# Overview

This project is a graduate student admissions system written in C++
with the purpose of organizing the admission of registered potential
graduate students. The graduate student admissions system was initially
created as a school project at Simon Fraser University. The project is
fully functional, and while I am not currently updating this project I
intend to improve and expand upon it's functionality in the future.
The graduate student admissions system is currently capible of the following:

 * Storing domestic and international students in seperate amd mergable
   linked lists.
 * Automatic student loading from text files.
 * Manual insertion of students.
 * Searching outputs of studentsbased on name, CGPA, research score,
   and application ID.
 * Removing students by name.
 * Removing the most and least qualified students from database.

Once merged the system can output students based on CGPA and research
proficiency requirements.


# Additional Features

The graduate student admissions system includes some input correcting and
avoiding functionality including:

 * Automatically correcting mis-inputted countries and capitalization on
   names.
 * Detecting misinpputed provinces for domestic students, and detecting
   missing data loaded from text files.


# IDE Usage Notes

Note that this program includes two main functions, one as part of the
regular main file, one as part of the debugmain used for testing
purposes. When using an IDE to run and compile this program, remove or 
comment out the debugmain file to ensure no dupicate main compliation
errors.


# Compilation with Makefile

The graduate student admissions system includes a makefile used for
compiling the program, running the program, and cleaning object code
files. The makefile has been tested on Linux Centos workspaces.
The included makefile includes the following commands:

 * make
   Compliles the program.
 * make clean
   Cleans compilation and executible.
 * ./main
   Runs the program.

Additionally, the makefile contains commands for comiling debug code used
to verify the functionality of some functions used in the graduate student
admissions system. Please note that this functionality verifying "debug
mode" is somewhat primitive and scheduled to be improved and expanded in
the future. The commands for debug mode are as follows:

 * make debug
   Compiles the debug
 * make debugclean
   Cleans the debug compilation and executible.
 * ./debug
   Runs the debug program.
   
   
# Future Improvements

As most work in progess projects, the graduate student admissions
system is far from perfect. Here I have listed some of potential
changes of the graduate student admissions system that would
improve functionality, usability, or modification.

 * Automate testing.
 * Clean up unused code.
 * Generalize specific functions to be used with both the domestic
   and international student linked list members.
 * Improve program modularity.
   
