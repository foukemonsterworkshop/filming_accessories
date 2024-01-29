void show_label(String content, int x, int y, float size, int16_t f_color, int16_t b_color, boolean mode) {
  lcd.Set_Text_Mode(mode);
  lcd.Set_Text_Size(size);
  lcd.Set_Text_colour(f_color);
  lcd.Set_Text_Back_colour(b_color);
  lcd.Print_String(content, x, y);
}

void draw_nav_button(String label_text) {
  lcd.Set_Draw_color(CYAN);
  int x = lcd.Get_Width() - 30;
  int y = lcd.Get_Height() - 30;
  lcd.Fill_Circle(x, y, 25);

  int label_size = 1.5;
  show_label(label_text,
             x - label_text.length() * label_size * 6 / 2 + label_size / 2 + 1,
             y - label_size * 8 / 2 + label_size / 2 + 1,
             label_size,
             BLACK, BLACK, 1);
}

void button_reaction(int16_t color, int x, int y, int x1, int y1) {
  lcd.Set_Draw_color(color);
  lcd.Fill_Round_Rectangle(
    x,
    y,
    x1,
    y1,
    3);
}

void init_menu(MenuState state) {
  Serial.print("Loading new menu: ");
  Serial.println(state);
  switch (state) {
    case MAIN:
      init_main_menu();
      break;
    case HOME:
      init_home_machine_menu();
      break;
    case JOG:
      init_jog_menu();
      break;
    case PAN:
      init_pan_menu();
      break;
    case TRUCK:
      init_truck_menu();
      break;
    case PARALLAX:
      init_parallax_menu();
      break;
    case VALUE_ENTRY:
      init_data_input();
      break;
    default:
      Serial.println("This is a bad state.");
  }
}

void interact_button(int sleep, int x, int y, int radius, int16_t primary_color, int16_t secondary_color, float label_size, String label_text){

  lcd.Set_Draw_color(secondary_color);
  lcd.Fill_Circle(x, y, 25);

  show_label(label_text,
             x - label_text.length() * label_size * 6 / 2 + label_size / 2 + 1,
             y - label_size * 8 / 2 + label_size / 2 + 1,
             label_size,
             BLACK, BLACK, 1);

  delay(sleep);

  lcd.Set_Draw_color(primary_color);
  lcd.Fill_Circle(x, y, 25);

  show_label(label_text,
             x - label_text.length() * label_size * 6 / 2 + label_size / 2 + 1,
             y - label_size * 8 / 2 + label_size / 2 + 1,
             label_size,
             BLACK, BLACK, 1);

}