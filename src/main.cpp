#include <Arduino.h>
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup()
{
  DDRB = 0xFF; // Set Port B as output
  DDRC = 0xFF; // Set Port C as output
  DDRD = 0xFF; // Set Port D as output
}

void loop()
{
  //reads the value of the key
  char customKey = customKeypad.getKey();
  //Order of Connection 
  // A ---> A0 LSB
  // B ---> A1
  // C ---> A2
  // D ---> A3
  // E ---> A4
  // F ---> A5
  // G ---> B3 MSB

  if (customKey == '0')
  {
  // A ---> 0
  // B ---> 0
  // C ---> 0
  // D ---> 0
  // E ---> 0
  // F ---> 0
  // G ---> 1
    PORTC = 0x00;
    PORTB |= (1 << PB3);
  }

  if (customKey == '1')
  {
  // A ---> 1
  // B ---> 0
  // C ---> 0
  // D ---> 1
  // E ---> 1
  // F ---> 1
  // G ---> 1
    PORTC = 0x39;
    PORTB |= (1 << PB3);
  }

  if (customKey == '2')
  {
  // A ---> 0
  // B ---> 0
  // C ---> 1
  // D ---> 0
  // E ---> 0
  // F ---> 1
  // G ---> 0
    PORTC = 0x24;
    PORTB &= ~(1 << PB3);
  }

  if (customKey == '3')
  {
  // A ---> 0
  // B ---> 0
  // C ---> 0
  // D ---> 0
  // E ---> 1
  // F ---> 1
  // G ---> 0
    PORTC = 0x30;
    PORTB &= ~(1 << PB3);
  }

  if (customKey == '4')
  {
  // A ---> 1
  // B ---> 0
  // C ---> 0
  // D ---> 1
  // E ---> 1
  // F ---> 0
  // G ---> 1
    PORTC = 0x19;
    PORTB &= ~(1 << PB3);
  }

  if (customKey == '5')
  {
  // A ---> 0
  // B ---> 1
  // C ---> 0
  // D ---> 0
  // E ---> 1
  // F ---> 0
  // G ---> 0
    PORTC = 0x12;
    PORTB &= ~(1 << PB3);
  }

  if (customKey == '6')
  {
  // A ---> 0
  // B ---> 1
  // C ---> 0
  // D ---> 0
  // E ---> 0
  // F ---> 0
  // G ---> 0
    PORTC = 0x02;
    PORTB &= ~(1 << PB3);
  }

  if (customKey == '7')
  {
  // A ---> 0
  // B ---> 0
  // C ---> 0
  // D ---> 1
  // E ---> 1
  // F ---> 1
  // G ---> 1
    PORTC = 0x38;
    PORTB |= (1 << PB3);
  }
  if (customKey == '8')
  {
  // A ---> 0
  // B ---> 0
  // C ---> 0
  // D ---> 0
  // E ---> 0
  // F ---> 0
  // G ---> 0
    PORTC = 0x00;
    PORTB &= ~(1 << PB3);
  }

  if (customKey == '9')
  {
  // A ---> 0
  // B ---> 0
  // C ---> 0
  // D ---> 0
  // E ---> 1
  // F ---> 0
  // G ---> 0
    PORTC = 0x10;
    PORTB &= ~(1 << PB3);
  }
}
