#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;
int scrollAmount;

char out_answer[70];

void setup() {
lcd.begin(16, 2);
pinMode(switchPin,INPUT);
randomSeed(analogRead(0));
printStartText();
}

void loop() {
  switchState = digitalRead(switchPin);

    if(switchState == HIGH){

      char Line1_fixed[] = "YOUR APHORISM:"; //This is the string that will be fixed in the first line of LCD.
      String Line2_scrolling_base = ""; //This string will be scrolled in the second line of LCD.
    
      reply = random(2);
        
        if(reply == 0){
            reply = random(8);

            switch (reply) {
                  case 0:
                    Line2_scrolling_base = "YOU SHOULD JUST TRY HARDER, BECAUSE ";
                    break;
                  case 1:
                     Line2_scrolling_base = "YOU ARE NOT A FAILIOR. ";
                    break;
                  case 2:
                     Line2_scrolling_base = "YOU SHOULD LOVE YOUR JOB, BECAUSE ";
                    break;
                  case 3:
                     Line2_scrolling_base = "JUST REMEMBER THE FACT, THAT ";
                    break;
                  case 4:
                     Line2_scrolling_base = "LIFE CAN BE GOOD, BUT SOMETIMES IT SUCKS BECAUSE ";
                    break;
                  case 5:
                     Line2_scrolling_base = "DO, OR DO NOT. ";
                    break;
                  case 6:
                     Line2_scrolling_base = "LIVE, LOVE, LAUGH. THAT IS A GREAT MOTTO, BECAUSE ";
                    break;
                  case 7:
                     Line2_scrolling_base = "IF YOU ARE FEELING DOWN, JUST THINK ABOUT THE FACT THAT ";
                    break;
                }

                 reply = random(6);

            switch (reply) {
                  case 0:
                    Line2_scrolling_base += "DRUGS ARE AWESOME!";
                    break;
                  case 1:
                    Line2_scrolling_base += "YOU WILL FAIL ANYWAYS.";
                    break;
                  case 2:
                    Line2_scrolling_base += "LIFE SUCKS ANYWAYS.";
                    break;
                  case 3:
                    Line2_scrolling_base += "THAT'S HOW MAFIA WORKS.";
                    break;
                  case 4:
                    Line2_scrolling_base += "UNICORNS ARE REAL.";
                    break;
                  case 5:
                    Line2_scrolling_base += "FARTS ARE FUNNY.";
                    break;
                }
          }
      else{
           reply = random(8);

            switch (reply) {
                  case 0:
                    Line2_scrolling_base = "WHENEVER SOMETHING GOES WRONG IN YOUR LIFE, JUST ";
                    break;
                  case 1:
                     Line2_scrolling_base = "THE MEANING OF LIFE IS TO ";
                    break;
                    case 2:
                     Line2_scrolling_base = "IF YOU TRY HARD ENOUGH, YOU CAN ";
                    break;
                    case 3:
                     Line2_scrolling_base ="IF YOU WANT TO GET NOTICED BY SOMEONE YOU LOVE, ";
                    break;
                    case 4:
                     Line2_scrolling_base = "YOU CAN NEVER SUCCEED IN LIFE, IF YOU DON'T OCCASIONALLY ";
                    break;
                    case 5:
                     Line2_scrolling_base = "EVERYBODY WILL ADMIRE YOU, IF YOU ";
                    break;
                    case 6:
                     Line2_scrolling_base = "WANT TO GET MORE FOLLOWERS ON INSTAGRAM? JUST TAKE A VIDEO WHILE YOU ";
                    break;
                    case 7:
                     Line2_scrolling_base = "NEVER GIVE UP, JUST ";
                    break;
                }
                                 
                 reply = random(11);

            switch (reply) {
                  case 0:
                    Line2_scrolling_base += "HAVE A SHOT OF VODKA.";
                    break;
                  case 1:
                    Line2_scrolling_base += "LIVE, LOVE, LAUGH.";
                    break;
                  case 2:
                    Line2_scrolling_base += "LAUGH AT YOUR OWN JOKES.";
                    break;
                  case 3:
                    Line2_scrolling_base += "FART.";
                    break;
                  case 4:
                    Line2_scrolling_base += "SMELL MY FINGER.";
                    break;
                  case 5:
                    Line2_scrolling_base += "AVOID SHITTING YOUR PANTS.";
                    break;
                  case 6:
                    Line2_scrolling_base += "DIG STRAIGHT DOWN IN MINECRAFT.";
                    break;
                  case 7:
                    Line2_scrolling_base += "DO, OR DO NOT. THERE IS NO TRY.";
                    break;
                  case 8:
                    Line2_scrolling_base += "GET UP AND YELL: PERKELE!!!";
                    break;
                  case 9:
                    Line2_scrolling_base += "STOP READING THESE STUPID AFORISMS AND GO GET A LIFE";
                    break;
                  case 10:
                    Line2_scrolling_base += "BUILD A ROBOT THAT GENERATES BAD APHORISMS.";
                    break;
                }
          }

  lcd.clear();
  lcd.print(Line1_fixed); //Print first line.
  delay(500); //Optional delay. If you omit this, the second line starts scrolling in from bottom right of the display (15,1), rather than entering from outside of the display (16,1). I find the latter visually more appealing, but it is optional.

  String Line2_scrolling =  "                "; // Defining a string consisting of sixteen spaces.
  Line2_scrolling += Line2_scrolling_base; // Adding sixteen spaces in front of the string that we want displayed. This is done so that line 2 will initially be empty in the display. Now we can display the string "Line2_scrolling".

  int Line2_length = Line2_scrolling.length(); // Length of our string (including the sixteen spaces that we added in front).
  int Line2_ChunkNumber = floor(Line2_length / 16 + 2); // Number of sixteen-character chunks in the string, plus one for the last chunk that is less than sixteen characters long.
  int Line2_LastChunkLength = Line2_length - ((Line2_ChunkNumber - 2) * 16); // Length of the last chunk, which is usually less than sixteen.
  int Line2_ChunkLength; // Will be initialized as 16 below, which is the usual length of chunks. But it will be changed if the last chunk is smaller in length.
  if (Line2_LastChunkLength == 0) { // If the string has a character length of a multiple of sixteen, Line2_ChunkNumber is reduced by one, in order to prevent redundant "for" cycles.
    Line2_ChunkNumber--;
  }

  String chunk[Line2_ChunkNumber]; // Create an array that can hold all the divided chunks of our scrolling string inside it.

  for (int j = 0; j < Line2_ChunkNumber - 1; j++) { // Assign all chunks inside chunk[].
    chunk[j] = Line2_scrolling.substring(j * 16 , j * 16 + 16);
  }

  for (int k = 0; k < Line2_ChunkNumber - 1; k++) {
    lcd.clear();
    lcd.print(Line1_fixed); // Print it again to avoid flicker.
    lcd.setCursor(0, 1);
    lcd.print(chunk[k]); // Display the string with the chunk number "k", starting from (0,1). This is the entire visible screen area of line 2 of the LCD.
    lcd.print(chunk[k + 1]); // Print the string with the chunk number "k+1", starting from (16,1). This is the area that is immediately to the right of the visible area of line 2 of the LCD.
      
      if (k != Line2_ChunkNumber - 2) { // If we are not dealing with the last chunk, set the number of iterations in the next "for" cycle to 16. If it is the last chunk and if the length of the last chunk isn't zero, set the number of iterations in the next "for" cycle to size of last chunk.
        Line2_ChunkLength = 16;
      }
      else if (Line2_LastChunkLength != 0) {
        Line2_ChunkLength = Line2_LastChunkLength;
      }

      for (int i = 1; i < Line2_ChunkLength + 1; i++) {
        lcd.scrollDisplayLeft(); // Scroll display left by one position.
        lcd.setCursor(i, 0); // Set cursor on the first line to allign with the scrolling string in the second line of LCD, in order to print the fixed string on the first line above where scrolling string starts. Currently in the algorithm, scrolling string starts at (i,1), hence setting the cursor to (i,0).
        lcd.print(Line1_fixed); // Print the fixed string so that its starting position alligns with the starting position of the scrolling string.
        delay(200); // Delay for visual ease of reading.
      }
  }
  
  printStartText();

 }
}

void printStartText(){
lcd.clear();
lcd.setCursor(0,0);
lcd.print("PRESS BUTTON TO");
lcd.setCursor(0,1);
lcd.print("SEE AN APHORISM!");
}
