void init_main_menu() {
  int x = 5;
  int y = 5;
  int x1 = lcd.Get_Display_Width() - x;
  int y1 = 30;

  int list_position = 0;
  int display_position = 1;

  int labelXOffset = 2 * x;
  int labelYOffset = 12;

  String content = steppers_active ? "Motors Active" : "Motors Inactive";
  int label_size = 2;

  char* labels[6] = { " ", "Home Machine", "Jog Machine", "Pan Machine", "Truck Machine", "Parallax Machine" };

  for (int i = 0; i < 6; i++) {
    int16_t color;
    if (i == 0) {
      color = steppers_active ? GREEN : RED;
    } else {
      color = LIGHTGREY;
      content = labels[i];
    }

    lcd.Set_Draw_color(color);
    lcd.Fill_Round_Rectangle(
      x,
      (display_position * y) + (list_position * y1),
      x1,
      display_position * (y + y1),
      3);

    show_label(content, labelXOffset, labelYOffset + (i * (y1 + y)), label_size, BLACK, BLACK, 1);

    list_position++;
    display_position++;
  }
}

void interact_main_menu(int px, int py) {
  int x = 5;
  int y = 5;
  int x1 = lcd.Get_Display_Width() - x;
  int y1 = 30;

  int list_position = 0;
  int display_position = 1;

  int labelXOffset = 2 * x;
  int labelYOffset = 12;

  if (is_pressed(px, py,
                 x,
                 (display_position * y) + (list_position * y1),
                 x1,
                 display_position * (y + y1))) {
    steppers_active = !steppers_active;
    lcd.Set_Draw_color(steppers_active ? GREEN : RED);
    lcd.Fill_Round_Rectangle(
      x,
      (display_position * y) + (list_position * y1),
      x1,
      display_position * (y + y1),
      3);
    show_label(steppers_active ? "Motors Active" : "Motors Inactive", labelXOffset, labelYOffset, 2, BLACK, BLACK, 1);
    delay(1000);
  }

  list_position++;
  display_position++;

  MenuState state[6] = { MAIN, HOME, JOG, PAN, TRUCK, PARALLAX };

  for (int i = 1; i < 6; i++) {

    if (is_pressed(px, py,
                   x,
                   (display_position * y) + (list_position * y1),
                   x1,
                   display_position * (y + y1))) {
      button_reaction(
        DARKGREY,
        x,
        (display_position * y) + (list_position * y1),
        x1,
        display_position * (y + y1));

      requires_redraw = true;
      prev_state = current_state;
      current_state = state[i];
      delay(150);
    }

    list_position++;
    display_position++;
  }

}