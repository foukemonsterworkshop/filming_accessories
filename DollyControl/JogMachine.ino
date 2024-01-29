void init_jog_menu() {
  int x = 5;
  int y = 5;
  int x1 = lcd.Get_Display_Width() - x;
  int y1 = 30;

  int list_position = 0;
  int display_position = 1;

  int labelXOffset = 2 * x;
  int labelYOffset = 12;

  lcd.Set_Draw_color(DARKGREY);
  lcd.Fill_Round_Rectangle(
    x,
    (display_position * y) + (list_position * y1),
    x1,
    display_position * (y + y1),
    3);
  show_label("Jog Machine", labelXOffset, labelYOffset, 2, BLACK, BLACK, 1);

  lcd.Set_Draw_color(GREEN);
  float jogX = lcd.Get_Width() / 4;
  float jogY = lcd.Get_Height() / 4;
  lcd.Fill_Circle(jogX, jogY, 25);

  String label_text = "Left";

  float label_size = 2.0;
  show_label(label_text,
             jogX - label_text.length() * label_size * 6 / 2 + label_size / 2 + 1,
             jogY - label_size * 8 / 2 + label_size / 2 + 1,
             label_size,
             BLACK, BLACK, 1);

  jogX = lcd.Get_Width() * (3.0 / 4.0);

  lcd.Fill_Circle(jogX, jogY, 25);

  label_text = "Right";

  show_label(label_text,
             jogX - label_text.length() * label_size * 6 / 2 + label_size / 2 + 1,
             jogY - label_size * 8 / 2 + label_size / 2 + 1,
             label_size,
             BLACK, BLACK, 1);

  jogY = lcd.Get_Height() / 2;
  jogX = lcd.Get_Width() / 4;

  lcd.Fill_Circle(jogX, jogY, 25);

  label_text = "P Left";

  show_label(label_text,
             jogX - label_text.length() * label_size * 6 / 2 + label_size / 2 + 1,
             jogY - label_size * 8 / 2 + label_size / 2 + 1,
             label_size,
             BLACK, BLACK, 1);

  jogX = lcd.Get_Width() * (3.0/ 4.0);

  lcd.Fill_Circle(jogX, jogY, 25);

  label_text = "P Right";

  show_label(label_text,
             jogX - label_text.length() * label_size * 6 / 2 + label_size / 2 + 1,
             jogY - label_size * 8 / 2 + label_size / 2 + 1,
             label_size,
             BLACK, BLACK, 1);

  draw_nav_button("Home");
}

void interact_jog_menu(int px, int py) {

  /*
    Serial.print("Jog Menu click-> x: ");
    Serial.print(px);
    Serial.print(" y: ");
    Serial.println(py);
  */

  float label_size = 2.0;

  check_home_button(px, py);

  float jogX = lcd.Get_Width() / 4;
  float jogY = lcd.Get_Height() / 4;

  gantry_stepper.setSpeed(30);
  pan_stepper.setSpeed(15);

  if (is_pressed(px, py, jogX - 25, jogY - 25, jogX + 25, jogY + 25)) {
    interact_button(200, jogX, jogY, 25, GREEN, DARKGREEN, label_size, "LEFT");
    Serial.println("Left Click");

    gantry_stepper.step(-200);

    Serial.println("Finished stepping");
  }

  jogX = lcd.Get_Width() * (3.0 / 4.0);
  if (is_pressed(px, py, jogX - 25, jogY - 25, jogX + 25, jogY + 25)) {
    interact_button(200, jogX, jogY, 25, GREEN, DARKGREEN, 2, "RIGHT");
    Serial.println("Right Click");

    gantry_stepper.step(200);
    Serial.println("Finished stepping");
  }
  
  jogX = lcd.Get_Width() / 4;
  jogY = lcd.Get_Height() / 2;

  if (is_pressed(px, py, jogX - 25, jogY - 25, jogX + 25, jogY + 25)) {
    interact_button(200, jogX, jogY, 25, GREEN, DARKGREEN, 2, "P LEFT");
    Serial.println("P Left Click");

    pan_stepper.step(-200);
    Serial.println("Finished stepping");
  }

  jogX = lcd.Get_Width() * (3.0 / 4.0);
  
  if (is_pressed(px, py, jogX - 25, jogY - 25, jogX + 25, jogY + 25)) {
    interact_button(200, jogX, jogY, 25, GREEN, DARKGREEN, 2, "P RIGHT");
    Serial.println("P Right Click");

    pan_stepper.step(200);
    Serial.println("Finished stepping");
  }
}