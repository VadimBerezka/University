#include <LiquidCrystal_I2C.h>

const int LCD_ADDR = 0x27;
LiquidCrystal_I2C lcd(LCD_ADDR, 16, 2);

const String firstName = "Vovna Polina";
const String lastName = "Alexsandrovna";

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  static int pos1 = 0;
  static int pos2 = 0;
  static bool lastNameStarted = false;
  static bool firstNameGoingBack = false;
  static bool lastNameGoingBack = false;

  // Очищаем первую строку
  lcd.setCursor(0, 0);
  for (int i = 0; i < 16; i++) {
    lcd.print(" ");
  }

  // Очищаем вторую строку
  lcd.setCursor(0, 1);
  for (int i = 0; i < 16; i++) {
    lcd.print(" ");
  }

  // Вывод первой строки (имя)
  if (!lastNameStarted) {
    lcd.setCursor(pos1, 0);
    lcd.print(firstName.substring(pos1));

    pos1++;
    if (pos1 >= firstName.length()) {
      pos1 = 0; // Сброс pos1 для первой строки
      firstNameGoingBack = true;
      lastNameStarted = true; 
    } else if (firstNameGoingBack) {
      pos1--;
      if (pos1 < 0) {
        pos1 = 0; 
        firstNameGoingBack = false;
        lastNameStarted = true; 
      }
    }
  } else {
    // Вывод второй строки (фамилия)
    lcd.setCursor(pos2, 1);
    lcd.print(lastName.substring(pos2));

    pos2++;
    if (pos2 >= lastName.length()) {
      pos2 = 0; // Сброс pos2 для второй строки
      lastNameStarted = false;  // Возврат к началу, выводим имя
      firstNameGoingBack = false; 
      pos1 = 0;
    } else if (lastNameGoingBack) {
      pos2--;
      if (pos2 < 0) {
        pos2 = 0;
        lastNameGoingBack = false;
        firstNameGoingBack = true; // Переключаем на первую строку
      }
    }
  }

  delay(200);
}