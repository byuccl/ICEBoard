// Sample code for Multiple Choice game

// Idea of how to show how for loops work
// Try to flip a string of chars and see what different code does
// Question: Which for loop will successfully write the words backwards?
// Depending on which answer is selected, it prints out the string



void setup() {
  // put your setup code here, to run once:
  String words = "Hi my friend";
  int selection = 1;
  if (selection == 1) //flips properly
  {
    for(int i = words.length() - 1; i >= 0; i--)
    {
      Serial.print(words.charAt(i));
    }
  }
  else if(selection == 2) //Misses first character
  {
    for(int i = words.length() - 1; i > 0; i--)
    {
      Serial.print(words.charAt(i));
    }
  }
  else if(selection == 3) //Skips every other letter
  {
    for(int i = words.length() - 1; i >= 0; i=i-2)
    {
      Serial.print(words.charAt(i));
    }
  }
  else if(selection == 4) //prints forwards
  {
    for(int i = 0; i <= words.length() - 1; i++)
    {
      Serial.print(words.charAt(i));
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
