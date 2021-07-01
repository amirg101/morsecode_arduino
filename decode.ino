

#define SIZE 26
const int ledPin=8;
const int dotButton=2;
const int dashButton=7;

String morseCode="";
String text="";
int characterAscii=0;
int startPos=0, endPos=0;
int startPos1=0, endPos1=0;
String characterCode="";
int dashButtonState=0;
int dotButtonState=0;


//Array of MorseCode for letters of English Language A to Z
String letters[SIZE]={

// A to I
".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
// J to R 
".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
  // S to Z
"...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." 
};

        
void setup() {
pinMode(ledPin, OUTPUT);
pinMode(dotButton, INPUT);
pinMode(dashButton, INPUT);
Serial.begin(9600);

Serial.println("1. First Write Your Morse code");
Serial.println("2. When you are done  Write '1' in the input box and Press Enter");
Serial.println("3. For Space between letters write 2 and Press Enter ");
Serial.println("\n\nEnter Your Morse Code :  ");

}


void loop() {
  // put your main code here, to run repeatedly:

while(Serial.available() > 0 ) 
{
      int ascii=Serial.read();

      switch(ascii)
      {
        case 49: // 49 is Ascii value of 1

        Serial.print("\n");
        morseCode.concat('#');// Placeing # at the end of morseCode to simplify further processing

         Serial.print("\nYour Morse code Translation :  ");
         
        endPos1=morseCode.indexOf('#');

        while(endPos1 < morseCode.length() )
        {
            extractLetters(morseCode.substring(startPos1, endPos1)); // This function would extract Letter as name suggest and would convert  code to text SIMPLE!
           startPos1=endPos1+1;
           if(startPos1 == morseCode.length() )
           {
              break; 
           }
           endPos1= morseCode.indexOf('#', startPos1);
        }
        startPos1=0;
        endPos1=0;

        text=""; //  For New Translation   
        morseCode="";
        Serial.println("\n\nEnter Your Morse Code Here ");
        
              
        break;

        case 50: // 50 is Ascii value of 2
        
        morseCode.concat("@");
        Serial.print("@");
        delay(200);
        
        break;

        case 51: // 51 is Ascii value of 3
          
        morseCode.concat("#");
        Serial.print("#");
        delay(200);
        
        break;
        
      }
      
}

process();

}

void turnONLed()
{
  //Turn ON LED
  digitalWrite(ledPin, HIGH);
}

void process()
{
  
  dotButtonState=digitalRead(dotButton);
dashButtonState=digitalRead(dashButton);




  if(dashButtonState == HIGH)
  {
    turnONLed();
   
    morseCode.concat("-"); // Storing code in variable morseCode with the help of concatenation function
    Serial.print("-");//Prints User entered Code
    delay(200);
  }
  else if(dotButtonState == HIGH)
  {
   turnONLed();
  
   morseCode.concat(".");
   Serial.print(".");
   delay(200);
    
  }
  else
  {
    //Turn OFF LED
    digitalWrite(ledPin, LOW);
     
  }

}

char convertIntoText(String characterCode)
{
  characterAscii=65;
  
  for(int index=0; index<SIZE; index++)
  {
    if(characterCode == letters[index])
    {
      return characterAscii;   
    }
   characterAscii++;  
  } 
  
}

void extractLetters(String words)
{
        words.concat('@'); // Placeing @ at the end of word to simplify further processing

        endPos=words.indexOf('@');

        
        //Loop to extracting single character morse Code from string of word        
        while( endPos<words.length() )
       {
         characterCode=words.substring(startPos, endPos);
         
         //Now CharacterCode will now convert in text

         text.concat(convertIntoText(characterCode));
         
         startPos=endPos+1;
         characterCode="";
         
          // if condition is just to terminate loop when our extracting single character code is complete thats all
         if(startPos == words.length() )
         {
           break;
         }
         
         endPos=words.indexOf('@', startPos);   
       
       }
                
        
        Serial.print(text);
        Serial.print(" ");
        startPos=0;
        endPos=0;
        text="";    
  
}