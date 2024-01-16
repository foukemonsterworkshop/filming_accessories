void init_data_input(){
  
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

  int label_division = 3;
  int label_size = 3;

  char* input_value[5][3] = {{"1", "2", "3"}, {"4", "5", "6"}, {"7", "8", "9"}, {".", "0", "-"}, {"D", " ", "E"}};
  int16_t color = LIGHTGREY;

  lcd.Set_Draw_color(DARKGREY);
  //input field
  lcd.Fill_Round_Rectangle(
    5, 
    5, 
    lcd.Get_Width()-5, 
    45, 
    3
  );

  //number grid
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < columns; j++){
      //skip space
      if(i == 4 && j == 1) j++;
      //delete key
      if(i == 4 && j == 0) color = RED;
      //enter key
      if(i == 4 && j == 2) color = GREEN;
      lcd.Set_Draw_color(color);
        lcd.Fill_Round_Rectangle(
          x+(x_offset*j), 
          y+(y_offset*i)+input_display_offset, 
          x1+(x_offset*j), 
          y1+(y_offset*i)+input_display_offset, 
          3
        );
        show_label(input_value[i][j], ((x+x1)/label_division)+(j*x_offset), (y+y1)/label_division+(i*y_offset)+input_display_offset, label_size, BLACK, BLACK, true);
    }
  }

  draw_nav_button("Home");
}

void interact_data_input(int px, int py){

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

  int label_division = 3;
  int label_size = 3;

  int16_t color = LIGHTGREY;

  char* input_value[5][3] = {{"1", "2", "3"}, {"4", "5", "6"}, {"7", "8", "9"}, {".", "0", "-"}, {"D", " ", "E"}};

  for(int i = 0; i < rows; i++){
    for(int j = 0; j < columns; j++){
      //skip space
      if(i == 4 && j == 1) j++;
      //delete key
      if(i == 4 && j == 0) color = RED;
      //enter key
      if(i == 4 && j == 2) color = GREEN;
      if(is_pressed(px, py, x+(x_offset*j), y+(y_offset*i)+input_display_offset, x1+(x_offset*j), y1+(y_offset*i)+input_display_offset)){

        lcd.Set_Draw_color(DARKGREY);
        lcd.Fill_Round_Rectangle(
          x+(x_offset*j), 
          y+(y_offset*i)+input_display_offset, 
          x1+(x_offset*j), 
          y1+(y_offset*i)+input_display_offset, 
          3
        );
        show_label(input_value[i][j], ((x+x1)/label_division)+(j*x_offset), (y+y1)/label_division+(i*y_offset)+input_display_offset, label_size, BLACK, BLACK, true);

        delay(100);

        lcd.Set_Draw_color(color);
        lcd.Fill_Round_Rectangle(
          x+(x_offset*j), 
          y+(y_offset*i)+input_display_offset, 
          x1+(x_offset*j), 
          y1+(y_offset*i)+input_display_offset, 
          3
        );
        show_label(input_value[i][j], ((x+x1)/label_division)+(j*x_offset), (y+y1)/label_division+(i*y_offset)+input_display_offset, label_size, BLACK, BLACK, true);
      }
    }
  }

  check_home_button(px, py);
}