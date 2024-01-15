void init_main_menu(){
  int border = 5;
  int selection_height = 30;
  int width = lcd.Get_Display_Width()-(2*border);

  int list_position = 0;
  int display_position = 1;

  int labelXOffset = 2*border;
  int labelYOffset = 12;

  lcd.Fill_Rect(border, (display_position*border)+(list_position*selection_height), width, display_position*(border+selection_height)-((display_position*border)+(list_position*selection_height)), GREEN);
  show_label("Motors Active",labelXOffset,labelYOffset,2,BLACK, BLACK,1);

  list_position++;
  display_position++;

  lcd.Fill_Rect(border, (display_position*border)+(list_position*selection_height), width, display_position*(border+selection_height)-((display_position*border)+(list_position*selection_height)), LIGHTGREY);
  show_label("Home Machine",labelXOffset,labelYOffset+(selection_height+border),2,BLACK, BLACK,1);

  list_position++;
  display_position++;

  lcd.Fill_Rect(border, (display_position*border)+(list_position*selection_height), width, display_position*(border+selection_height)-((display_position*border)+(list_position*selection_height)), LIGHTGREY);
  show_label("Jog Machine",labelXOffset,labelYOffset+(2*(selection_height+border)),2,BLACK, BLACK,1);

  list_position++;
  display_position++;

  lcd.Fill_Rect(border, (display_position*border)+(list_position*selection_height), width, display_position*(border+selection_height)-((display_position*border)+(list_position*selection_height)), LIGHTGREY);
  show_label("Pan Machine",labelXOffset,labelYOffset+(3*(selection_height+border)),2,BLACK, BLACK,1);

  list_position++;
  display_position++;

  lcd.Fill_Rect(border, (display_position*border)+(list_position*selection_height), width, display_position*(border+selection_height)-((display_position*border)+(list_position*selection_height)), LIGHTGREY);
  show_label("Truck Machine",labelXOffset,labelYOffset+(4*(selection_height+border)),2,BLACK, BLACK,1);

  list_position++;
  display_position++;

  lcd.Fill_Rect(border, (display_position*border)+(list_position*selection_height), width, display_position*(border+selection_height)-((display_position*border)+(list_position*selection_height)), LIGHTGREY);
  show_label("Parallax Machine",labelXOffset,labelYOffset+(5*(selection_height+border)),2,BLACK, BLACK,1);

}

void interact_main_menu(int px, int py){
  int border = 5;
  int selection_height = 30;
  int xOffset = lcd.Get_Display_Width()-border;
  int width = lcd.Get_Display_Width()-(2*border);

  int list_position = 0;
  int display_position = 1;

  int labelXOffset = 2*border;
  int labelYOffset = 12;

  if(is_pressed(px, py, 
                border, 
                (display_position*border)+(list_position*selection_height), 
                xOffset, 
                display_position*(border+selection_height)
  )){
    steppers_active = !steppers_active;
    int16_t color = steppers_active ? GREEN : RED;
    char* label = steppers_active ? "Motors Active" : "Motors Inactive";
    lcd.Fill_Rect(border, (display_position*border)+(list_position*selection_height), width, display_position*(border+selection_height)-((display_position*border)+(list_position*selection_height)), color);
    show_label(label,labelXOffset,labelYOffset,2,BLACK, BLACK,1);
    delay(150);
  }

  list_position++;
  display_position++;

  if(is_pressed(px, py, 
                border, 
                (display_position*border)+(list_position*selection_height), 
                xOffset, 
                display_position*(border+selection_height)
  )){
    requires_redraw = true;
    current_state = HOME;
    delay(150);
  }

  list_position++;
  display_position++;

  if(is_pressed(px, py, 
                border, 
                (display_position*border)+(list_position*selection_height), 
                xOffset, 
                display_position*(border+selection_height)
  )){
    requires_redraw = true;
    current_state = JOG;
    delay(150);
  }

  list_position++;
  display_position++;

  if(is_pressed(px, py, 
                border, 
                (display_position*border)+(list_position*selection_height), 
                xOffset, 
                display_position*(border+selection_height)
  )){
    requires_redraw = true;
    current_state = PAN;
    delay(150);
  }

  list_position++;
  display_position++;

  if(is_pressed(px, py, 
                border, 
                (display_position*border)+(list_position*selection_height), 
                xOffset, 
                display_position*(border+selection_height)
  )){
    requires_redraw = true;
    current_state = TRUCK;
    delay(150);
  }

  list_position++;
  display_position++;

  if(is_pressed(px, py, 
                border, 
                (display_position*border)+(list_position*selection_height), 
                xOffset, 
                display_position*(border+selection_height)
  )){
    requires_redraw = true;
    current_state = PARALLAX;
    delay(150);
  }
}