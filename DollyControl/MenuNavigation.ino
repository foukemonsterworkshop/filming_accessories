void press_menu_button(MenuState state, int px, int py){
  switch(state){
    case MAIN:
      interact_main_menu(px,py);
      break;
    default:
      interact_standin(px, py);
  }
}

boolean is_pressed(int px, int py, int x, int y, int x1, int y1){
  return px > x && px < x1 && py > y && py < y1;
}

void check_home_button(int px, int py){
  int x = lcd.Get_Width() - 30;
  int y = lcd.Get_Height() - 30;
  
  if(is_pressed(px, py, x-30, y-30, x+30, y+30)){
    requires_redraw = true;
    current_state = MAIN;
  }
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

  if(is_pressed(px, py, border, (display_position*border)+(list_position*selection_height), xOffset, display_position*(border+selection_height))){
    steppers_active = !steppers_active;
    int16_t color = steppers_active ? GREEN : RED;
    char* label = steppers_active ? "Motors Active" : "Motors Inactive";
    lcd.Fill_Rect(border, (display_position*border)+(list_position*selection_height), width, display_position*(border+selection_height)-((display_position*border)+(list_position*selection_height)), color);
    show_label(label,labelXOffset,labelYOffset,2,BLACK, BLACK,1);
    delay(150);
  }

  list_position++;
  display_position++;

  if(is_pressed(px, py, border, (display_position*border)+(list_position*selection_height), xOffset, display_position*(border+selection_height))){
    requires_redraw = true;
    current_state = HOME;
    delay(150);
  }

  list_position++;
  display_position++;

  if(is_pressed(px, py, border, (display_position*border)+(list_position*selection_height), xOffset, display_position*(border+selection_height))){
    requires_redraw = true;
    current_state = JOG;
    delay(150);
  }

  list_position++;
  display_position++;

  if(is_pressed(px, py, border, (display_position*border)+(list_position*selection_height), xOffset, display_position*(border+selection_height))){
    requires_redraw = true;
    current_state = PAN;
    delay(150);
  }

  list_position++;
  display_position++;

  if(is_pressed(px, py, border, (display_position*border)+(list_position*selection_height), xOffset, display_position*(border+selection_height))){
    requires_redraw = true;
    current_state = TRUCK;
    delay(150);
  }

  list_position++;
  display_position++;

  if(is_pressed(px, py, border, (display_position*border)+(list_position*selection_height), xOffset, display_position*(border+selection_height))){
    requires_redraw = true;
    current_state = PARALLAX;
    delay(150);
  }
}

void interact_standin(int px, int py){

  int border = 5;
  int selection_height = 30;
  int xOffset = lcd.Get_Display_Width()-border;
  int width = lcd.Get_Display_Width()-(2*border);

  int list_position = 0;
  int display_position = 1;

  int labelXOffset = 2*border;
  int labelYOffset = 12;

  if(is_pressed(px, py, border, (display_position*border)+(list_position*selection_height), xOffset, display_position*(border+selection_height))){
    requires_redraw = true;
    current_state = MAIN;
  }

  check_home_button(px, py);

}