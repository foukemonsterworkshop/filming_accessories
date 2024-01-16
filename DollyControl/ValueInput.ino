void init_data_input() {

  //erase global current input value;
  current_input = "";

  int input_display_offset = 50;

  int x = 5;
  int y = 5;
  int x1 = 35;
  int y1 = 45;
  int rows = 5;
  int columns = 3;
  int radius = 3;

  int x_offset = 45;
  int y_offset = 50;

  int x_border = (lcd.Get_Width() - (x1 + (x_offset * 2)) - x) / 2;

  int label_division = 3;
  int label_size = 3;

  draw_input_display(DARKGREY);

  char* input_value[5][3] = {
    { "1", "2", "3" },
    { "4", "5", "6" },
    { "7", "8", "9" },
    { ".", "0", "-" },
    { "D", " ", "E" }
  };

  int16_t color = LIGHTGREY;

  //number grid
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      //skip space
      if (i == 4 && j == 1) j++;
      //delete key
      if (i == 4 && j == 0) color = RED;
      //enter key
      if (i == 4 && j == 2) color = GREEN;
      draw_input_button(
        color,
        x_border + (x + (x_offset * j)),
        y + (y_offset * i) + input_display_offset,
        x_border + (x1 + (x_offset * j)),
        y1 + (y_offset * i) + input_display_offset,
        3,
        input_value[i][j],
        x_border + ((x + x1) / label_division) + (j * x_offset),
        (y + y1) / label_division + (i * y_offset) + input_display_offset,
        label_size);
    }
  }
}

void interact_data_input(int px, int py) {

  int input_display_offset = 50;

  int x = 5;
  int y = 5;
  int x1 = 35;
  int y1 = 45;
  int rows = 5;
  int columns = 3;
  int radius = 3;

  int x_offset = 45;
  int y_offset = 50;

  int x_border = (lcd.Get_Width() - (x1 + (x_offset * 2)) - x) / 2;

  int label_division = 3;
  int label_size = 3;

  int16_t primary_color = LIGHTGREY;
  int16_t secondary_color = DARKGREY;

  char* input_value[5][3] = {
    { "1", "2", "3" },
    { "4", "5", "6" },
    { "7", "8", "9" },
    { ".", "0", "-" },
    { "D", " ", "E" }
  };

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      //skip space
      if (i == 4 && j == 1) j++;
      //delete key
      if (i == 4 && j == 0) {
        primary_color = RED;
        secondary_color = DARKRED;
      }
      //enter key
      if (i == 4 && j == 2) {
        primary_color = GREEN;
        secondary_color = DARKGREEN;
      }
      if (is_pressed(
            px, py,
            x_border + x + (x_offset * j),
            y + (y_offset * i) + input_display_offset,
            x_border + x1 + (x_offset * j),
            y1 + (y_offset * i) + input_display_offset)) {
        if (strcmp(input_value[i][j], "D") == 0) {
          //delete last character added
          current_input.remove(current_input.length() - 1);
          draw_input_display(DARKGREY);
        } else if (strcmp(input_value[i][j], "E") == 0) {
          
          MatchState ms;
          //   ^\-?\d*\.?\d+$
          char* regex = "^%-?%d*%.?%d+$";

          ms.Target(current_input.c_str(), current_input.length());

          char result = ms.Match(regex, 0);

          if (result > 0) {
            //update value...

            //redraw previous menu
            requires_redraw = true;
            current_state = prev_state;
          } else {
            //reject input
            draw_input_display(RED);
            //TODO: clear input value or just force user to delete characters
          }

          //return to previous screen
        } else {
          current_input += input_value[i][j];
          Serial.print("New value: ");
          Serial.println(current_input);
          update_content_input_display();
        }

        value_input_button_reaction(primary_color, secondary_color, i, j, input_value[i][j]);
      }
    }
  }
}

void draw_input_display(int16_t color) {
  lcd.Set_Draw_color(color);
  //input field
  lcd.Fill_Round_Rectangle(
    5,
    5,
    lcd.Get_Width() - 5,
    45,
    3);

  if (current_input.length() > 0) update_content_input_display();
}

void update_content_input_display() {
  show_label(current_input, 15, 15, 3, BLACK, BLACK, true);
}

void draw_input_button(int16_t color, int x, int y, int x1, int y1, int radius, char* content, int label_x, int label_y, int label_size) {
  lcd.Set_Draw_color(color);

  lcd.Fill_Round_Rectangle(x, y, x1, y1, radius);

  show_label(content, label_x, label_y, label_size, BLACK, BLACK, true);
}

void value_input_button_reaction(int16_t primary_color, int16_t secondary_color, int i, int j, char* content) {

  int input_display_offset = 50;

  int x = 5;
  int y = 5;
  int x1 = 35;
  int y1 = 45;
  int rows = 5;
  int columns = 3;
  int radius = 3;

  int x_offset = 45;
  int y_offset = 50;

  int x_border = (lcd.Get_Width() - (x1 + (x_offset * 2)) - x) / 2;

  int label_division = 3;
  int label_size = 3;

  draw_input_button(
    secondary_color,
    x_border + (x + (x_offset * j)),
    y + (y_offset * i) + input_display_offset,
    x_border + (x1 + (x_offset * j)),
    y1 + (y_offset * i) + input_display_offset,
    3,
    content,
    x_border + ((x + x1) / label_division) + (j * x_offset),
    (y + y1) / label_division + (i * y_offset) + input_display_offset,
    label_size);

  delay(200);

  draw_input_button(
    primary_color,
    x_border + (x + (x_offset * j)),
    y + (y_offset * i) + input_display_offset,
    x_border + (x1 + (x_offset * j)),
    y1 + (y_offset * i) + input_display_offset,
    3,
    content,
    x_border + ((x + x1) / label_division) + (j * x_offset),
    (y + y1) / label_division + (i * y_offset) + input_display_offset,
    label_size);
}