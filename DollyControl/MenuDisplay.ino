void show_label(String content, int x, int y, int size, int16_t f_color, int16_t b_color, boolean mode) {
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