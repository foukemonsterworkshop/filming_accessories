void init_main_menu() {
  int x = 5;
  int y = 5;
  int x1 = lcd.Get_Display_Width() - x;
  int y1 = 30;

  int list_position = 0;
  int display_position = 1;

  int labelXOffset = 2 * x;
  int labelYOffset = 12;


  for (int i = 0; i < 6; i++) {
    int16_t color;
    if (i == 0) {
      color = steppers_active ? GREEN : RED;
    } else {
      color = LIGHTGREY;
    }

    lcd.Set_Draw_color(color);
    lcd.Fill_Round_Rectangle(
      x,
      (display_position * y) + (list_position * y1),
      x1,
      display_position * (y + y1),
      3);

    list_position++;
    display_position++;
  }

  show_label(steppers_active ? "Motors Active" : "Motors Inactive", labelXOffset, labelYOffset, 2, BLACK, BLACK, 1);

  show_label("Home Machine", labelXOffset, labelYOffset + (y1 + y), 2, BLACK, BLACK, 1);

  show_label("Jog Machine", labelXOffset, labelYOffset + (2 * (y1 + y)), 2, BLACK, BLACK, 1);

  show_label("Pan Machine", labelXOffset, labelYOffset + (3 * (y1 + y)), 2, BLACK, BLACK, 1);

  show_label("Truck Machine", labelXOffset, labelYOffset + (4 * (y1 + y)), 2, BLACK, BLACK, 1);

  show_label("Parallax Machine", labelXOffset, labelYOffset + (5 * (y1 + y)), 2, BLACK, BLACK, 1);
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
    delay(150);
  }

  list_position++;
  display_position++;

  if (is_pressed(px, py,
                 x,
                 (display_position * y) + (list_position * y1),
                 x1,
                 display_position * (y + y1))) {
    nav_button_reaction(DARKGREY, x, (display_position * y) + (list_position * y1), x1, display_position * (y + y1));
    requires_redraw = true;
    current_state = HOME;
    delay(150);
  }

  list_position++;
  display_position++;

  if (is_pressed(px, py,
                 x,
                 (display_position * y) + (list_position * y1),
                 x1,
                 display_position * (y + y1))) {
    nav_button_reaction(DARKGREY, x, (display_position * y) + (list_position * y1), x1, display_position * (y + y1));
    requires_redraw = true;
    current_state = JOG;
    delay(150);
  }

  list_position++;
  display_position++;

  if (is_pressed(px, py,
                 x,
                 (display_position * y) + (list_position * y1),
                 x1,
                 display_position * (y + y1))) {
    nav_button_reaction(DARKGREY, x, (display_position * y) + (list_position * y1), x1, display_position * (y + y1));
    requires_redraw = true;
    current_state = PAN;
    delay(150);
  }

  list_position++;
  display_position++;

  if (is_pressed(px, py,
                 x,
                 (display_position * y) + (list_position * y1),
                 x1,
                 display_position * (y + y1))) {
    nav_button_reaction(DARKGREY, x, (display_position * y) + (list_position * y1), x1, display_position * (y + y1));
    requires_redraw = true;
    current_state = TRUCK;
    delay(150);
  }

  list_position++;
  display_position++;

  if (is_pressed(px, py,
                 x,
                 (display_position * y) + (list_position * y1),
                 x1,
                 display_position * (y + y1))) {
    nav_button_reaction(DARKGREY, x, (display_position * y) + (list_position * y1), x1, display_position * (y + y1));
    requires_redraw = true;
    current_state = PARALLAX;
    delay(150);
  }
}