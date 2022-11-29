# SFWRENG-3K04

Group-9: Aidan, Jibin, Clara, Pragya, Chris

This repository was used for the submission of our groups PACEMAKER project. All relevant Simulink files can be found within the simulink folder.

The main python file is dcmFinal.py, and experimentation with serial communication is found in serialCom.py


How to use the files:
1) To return the value of Pin A0 (Pin 1) and Pin A1 (Pin 2), the pacemaker need to be flashed with the model present in the file "Final_Simulink_Model_assignment_2_PinA0_PinA1.slx".
    Additionally, in the serialComHeartView.py file you have to uncomment the program block from lines 133 to 142
    If the mentioned lines are not comment and you wish test that part leave it as it is 

2)To check if the board is receiving the correct data form the 'doctor' you have to flash the board with the model present in the file "Final_Simulink_Model_assignment_2.slx"
    Additionally, in the serialComHeartView.py file you have to uncomment the program block from lines 147 to 182
    If the mentioned lines are not comment and you wish test that part leave it as it is 