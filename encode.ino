int led12 = 12;      // blink an led on output 12
/*
  Set the speed of your morse code
  Here are the ratios code elements:
    Dash length = Dot length x 3
    Pause between elements = Dot length    
*/
int dotLen = 200;     // length of the morse code 'dot'
int dashLen = dotLen * 3;    // length of the morse code 'dash'
int elemPause = dotLen;// length of the pause between elements of a character
int Spaces = dotLen * 3;     // length of the spaces between characters
int wordPause = dotLen * 7;  // length of the pause between words
char stringToMorseCode[]="abc";
void setup() {                
  // initialize the digital pin as an output for LED lights.
  pinMode(led12, OUTPUT); 
  Serial.begin(9600);
Serial.println("Your morse code:");
}

// Create a loop of the letters/words you want to output in morse code (defined in string at top of code)
void loop()
{ 
 
  // Loop through the string and get each character one at a time until the end is reached
  for (int i = 0; i < sizeof(stringToMorseCode) - 1; i++)
  {
    // Get the character in the current position
  char tmpChar = stringToMorseCode[i];
  // Set the case to lower case
  tmpChar = toLowerCase(tmpChar);
  // Call the subroutine to get the morse code equivalent for this character
  GetChar(tmpChar);
  }
  
  // At the end of the string long pause before looping and starting again
  LightsOff(8000);      
}

// DOT
void MorseDot()
{
  digitalWrite(led12, HIGH);    // turn the LED on 
  delay(dotLen);              // hold in this position
  Serial.print('.');
}

// DASH
void MorseDash()
{
  digitalWrite(led12, HIGH);    // turn the LED on 
  delay(dashLen);               // hold in this position
  Serial.print('_');

}

// Turn Off
void LightsOff(int delayTime)
{
  digitalWrite(led12, LOW);     // turn the LED off   
  delay(delayTime);             // hold in this position
}

// *** Characters to Morse Code Conversion *** //
void GetChar(char tmpChar)
{
  // Take the passed character and use a switch case to find the morse code for that character
  switch (tmpChar) {
    case 'a': 
    MorseDot();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    Serial.print(" ");
    break;
    case 'b':
    MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
        Serial.print(" ");

    break;
    case 'c':
      MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);    Serial.print(" ");

    break;
    case 'd':
    MorseDash();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);    Serial.print(" ");

    break;
    case 'e':
    MorseDot();
    LightsOff(elemPause);    Serial.print(" ");

    break;
    case 'f':
      MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);    Serial.print(" ");

    break;
    case 'g':
    MorseDash();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);    Serial.print(" ");

    break;
    case 'h':
      MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);    Serial.print(" ");

    break;
    case 'i':
      MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);    Serial.print(" ");

    break;
    case 'j':
      MorseDot();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);    Serial.print(" ");

    break;
      case 'k':
      MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);    Serial.print(" ");

    break;
    case 'l':
      MorseDot();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);    Serial.print(" ");

    break;
      case 'm':
      MorseDash();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);    Serial.print(" ");

    break;
    case 'n':
      MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);    Serial.print(" ");

    break;
    case 'o':
      MorseDash();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);    Serial.print(" ");

    break;
    case 'p':
      MorseDot();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);    Serial.print(" ");

    break;
    case 'q':
      MorseDash();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);    Serial.print(" ");

    break;
    case 'r':
      MorseDot();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);    Serial.print(" ");

    break;
    case 's':
      MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);    Serial.print(" ");

    break;
    case 't':
      MorseDash();
    LightsOff(elemPause);    Serial.print(" ");

    break;
    case 'u':
      MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);    Serial.print(" ");

    break;
    case 'v':
      MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);    Serial.print(" ");

    break;
    case 'w':
      MorseDot();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);    Serial.print(" ");

    break;
    case 'x':
      MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);    Serial.print(" ");

    break;
    case 'y':
      MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);    Serial.print(" ");

    break;
    case 'z':
      MorseDash();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);    Serial.print(" ");

    break;
    default: 
    // If a matching character was not found it will default to a blank space
    LightsOff(Spaces);      
  }
}