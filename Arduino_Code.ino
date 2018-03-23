int Sun;     // creates a variable called Sun. In arduino variable have to be created and declared what type of variable they are. In this case Sun is a int variable to store number similar to double in matlab 

void setup() {      // Any part of the code in the void setup is only ran once to setup the  void loop
pinMode(A0, INPUT);       // Activates the pin A0 and sets the pin to receive
pinMode(10, OUTPUT);     // Activates the pin 10, and sets the pin to send
pinMode(8, OUTPUT);      // Activates the pin 8, and sets the pin to send 
pinMode(6, OUTPUT);      // Activates the pin 6, and sets the pin to send 
Serial.begin(9600);     // Initializes the communication between the arduino and the computer at a
			rate of 9600 bits a second
}

void loop() {     // Any part of the code under void loop is repeated over and over
Sun = analogRead(A0);     // Takes the sent fro the photo-resistor and stores the value in the
 			       variable Sun. The highest the value can be is 1023, lowest 0 
Serial.println(Sun);     // Sends the value stored in the variable to the computer
if (Sun >= 800){     // Starts a If statment, if the statement in the parenthesis is true do what is in 
  		        the brackets, if not skip to next section
digitalWrite(10, HIGH);     // Turn pin 10 on
digitalWrite(8, HIGH);      // Turn pin 8 on 
digitalWrite(6, HIGH);      // Turn pin 6 on 
}
else if (Sun < 800 && Sun >= 400){     // continues the if statement. if the previous statement are  
					    untrue then it tests this statement
digitalWrite(10, HIGH);      // Turn pin 10 on 
digitalWrite(8, HIGH);      // Turn pin 8 on 
digitalWrite(6, LOW);      // Turn pin 6 off
}
else if (Sun < 400 && Sun >= 100){       // continues the if statement. if the previous statement 
					      are untrue then it tests this statement
digitalWrite(10, HIGH);      // Turn pin 10 on 
digitalWrite(8, LOW);      // Turn pin 8 off
digitalWrite(6, LOW);      // Turn pin 6 off
}
else if (Sun < 100){      // continues the if statement. if the previous statement are untrue then it 
			  tests this statement
digitalWrite(10, LOW);      // Turn pin 10 off 
digitalWrite(8, LOW);      // Turn pin 8 off 
digitalWrite(6, LOW);      // Turn pin 6 off 
}
delay(2000);     // Cause the code to pause for two seconds before repeating the void loop part 
		  again

}
