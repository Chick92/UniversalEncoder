
int debug_led = 13;
int interrupt_1 = 2;
int interrupt_2 = 3;
int previous = 0;
long counter = 0;


void counter(){
	//- CW  states 0b0001, 0b0111, 0b1000, 0b1110
	//- CCW states 0b0010, 0b0100, 0b1011, 0b1101
	static int current;
	int state;
	current = (digitalRead(interrupt_1) << 1) | digitalRead(interrupt_2); // 0bAB
	state = (previous << 3) | current; // 0bApBpAB
	if (state == 0b0001 || state = 0b0111 || state == 0b1000 || state == 0b1110){
		state++;
	}
	else if (state == 0b0010 || state == 0b0100 || state == 0b1011 || state == 0b1101){
		state--;
	}
	else{
		Serial.println("encoder error");
	}
	
	
	previous = current;	
}

void setup(){
	Serial.begin(11500);
	pinMode(debug_led, OUTPUT);
	pinMode(interrupt_1, INPUT_PULLUP);
	pinMode(interrupt_2, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(interrupt_1), counter, CHANGE);
	attachInterrupt(digitalPinToInterrupt(interrupt_2), counter, CHANGE);
}

void loop(){
	Serial.println(counter);
	delay(1000);
	
}