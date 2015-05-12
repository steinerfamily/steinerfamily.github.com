const int buzzerPin = 9;
const int ledPin = 7;
const int toneFreq = 523;

// constants for tone and rest durations
const int dotLength = 100;
const int dashLength = dotlength * 3;
// inter-element gap - between each dot or dash of a letter
const int inter = dotLength; 
// letter gap is 3 dots - the inter gap is always added - so this is one fewer
const int lgap = dotLength * 2; // inter-letter gap
// word gap is 7 dots - with letter and inter gap already counted, this is -1
const int wgap = dotLength * 4; //inter-word gap


void setup() 
{
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  char thisChar;
  if (Serial.available())
  {
    // read a single character
    thisChar = Serial.read();
    if (thisChar>='a' && thisChar<='z')
    {
      // convert to upper case
      thisChar = thisChar -32; 
    }
    soundLetter(thischar);
    delay(lgap);
  }
}

void dot()
{
  // play a dot
  tone(buzzerPin, toneFreq);
  // LED
  digitalWrite(ledPin, HIGH);
  delay(dotlength);
  noTone(buzzerPin);
  // LED
  digitalWrite(ledPin, LOW);
  delay(inter);
}

void dash()
{
  // play a dash
  tone(buzzerPin, toneFreq);
  // LED
  digitalWrite(ledPin, HIGH);
  delay(dashLength);
  noTone(buzzerPin);
  // LED
  digitalWrite(ledPin, LOW);
  delay(inter);
}

void soundLetter(char letter)
{
  // letters are in order of frequency
  switch(letter)
  {
  case 'E':
    dot();
    return; 
  case 'T':
    dash();
    return; 
  case 'A':
    dot();
    dash();
    return;
  case 'O':
    dash();
    dash();
    dash();
    return; 
  case 'I':
    dot();
    dot();
    return;
  case 'N':
    dash();
    dot();
    return;
  case 'S':
    dot();
    dot();
    dot();
    return;
  case 'H':
    dot();
    dot();
    dot();
    dot();
    return;
  case 'R':
    dot();
    dash();
    dot();
    return;
  case 'D':
    dash();
    dot();
    dot();
    return;
  case 'L':
    dot();
    dash();
    dot();
    dot();
    return;
  case 'C':
    dash();
    dot();
    dash();
    dot();
    return;
  case 'U':
    dot();
    dot();
    dash();
    return;
  case 'M':
    dash();
    dash();
    return;
  case 'W':
    dot();
    dash();
    dash();
    return;
  case 'F':
    dot();
    dot();
    dash();
    dot();
    return;
  case 'G':
    dash();
    dash();
    dot();
    return;
  case 'Y':
    dash();
    dot();
    dash();
    dash();
    return;
  case 'P':
    dot();
    dash();
    dash();
    dot();
    return;
  case 'B':
    dash();
    dot();
    dot();
    dot();
    return;
  case 'V':
    dot();
    dot();
    dot();
    dash();
    return;
  case 'K':
    dash();
    dot();
    dash();
    return;
  case 'J':
    dot();
    dash();
    dash();
    dash();
    return;
  case 'X':
    dash();
    dot();
    dot();
    dash();
    return;
  case 'Q':
    dash();
    dash();
    dot();
    dash();
    return;
  case 'Z':
    dash();
    dash();
    dot();
    dot();
    return;
  case '1':
    dot();
    dash();
    dash();
    dash();
    dash();
    return;
  case '2':
    dot();
    dot();
    dash();
    dash();
    dash();
    return;
  case '3':
    dot();
    dot();
    dot();
    dash();
    dash();
    return;
  case '4':
    dot();
    dot();
    dot();
    dot();
    dash();
    return;
  case '5':
    dot();
    dot();
    dot();
    dot();
    dot();
    return;
  case '6':
    dash();
    dot();
    dot();
    dot();
    dot();
    return;
  case '7':
    dash();
    dash();
    dot();
    dot();
    dot();
    return;
  case '8':
    dash();
    dash();
    dash();
    dot();
    dot();
    return;
  case '9':
    dash();
    dash();
    dash();
    dash();
    dot();
    return;
  case '0':
    dash();
    dash();
    dash();
    dash();
    dash();
    return;    
  case ' ':
    delay(wgap);
    return; 
  }
}
