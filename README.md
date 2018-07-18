# Buzzer_System
A combination of hardware and software using Cypress's PSOC 049 to design a buzzer system similar to that used in High School Science Bowl

The end goal of this project is to have a functioning buzzer system that works similar to the product found here: http://www.buzzersystems.com/JrBibleQuiz/index.htm titled "Junior Bible Quiz JBQ Buzzer System".

The Junior Bible Quiz JBQ Buzzer System is a standard science bowl buzzer system (also the one my High School used).  It takes up to 5 input buttons for two teams to indicate a player is ready to answer a question.  The first player that buzzes in causes their light to illuminate and a buzzing sound corresponding to their team.  This light stays on and no other light can illuminate until a reset button is pressed turning off that player's light.  I may also add a countdown timer functionality so the players know how much time they have remaining to buzz in to answer a question.

I created this project with the intention of creating a system that could be used in High School Science Bowl practices and to help me learn how to use Cypress's PSOC embedded boards.  The project will rely upon code written in the language C but also hardware connections set up in the PSOC Creator software.  I am using a CY8CKIT-049-42XX board from Cypress to run the programs, but this requires a programming board to load the program.  The programming board I am using is the CY8C5868LTI-LP039.

![alt text](https://github.com/chasejohnson3/Buzzer_System/blob/master/Buzzer%20Prototype.jpg)
