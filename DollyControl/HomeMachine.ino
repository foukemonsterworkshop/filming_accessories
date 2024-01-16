void init_home_machine_menu(){
  int x = 5;
  int y = 5;
  int x1 = lcd.Get_Display_Width()-x;
  int y1 = 30;

  int list_position = 0;
  int display_position = 1;

  int labelXOffset = 2*x;
  int labelYOffset = 12;

  for(int i = 0; i < 2; i++){
    lcd.Set_Draw_color(LIGHTGREY);
    lcd.Fill_Round_Rectangle(
      x, 
      (display_position*y)+(list_position*y1), 
      x1, 
      display_position*(y+y1), 
      3);

    list_position++;
    display_position++;
  }
  
  show_label("Main From Home",labelXOffset,labelYOffset,2,BLACK, BLACK,1);

  show_label("Data Input Testing",labelXOffset,labelYOffset+(y1+y),2,BLACK, BLACK,1);

  draw_nav_button("Home");
}

void interact_home_machine_menu(int px, int py){
  int x = 5;
  int y = 5;
  int x1 = lcd.Get_Display_Width()-x;
  int y1 = 30;

  int list_position = 0;
  int display_position = 1;

  int labelXOffset = 2*x;
  int labelYOffset = 12;

  check_home_button(px, py);

  if(is_pressed(px, py, 
      x, 
      (display_position*y)+(list_position*y1), 
      x1, 
      display_position*(y+y1)
  )){
    requires_redraw = true;
    current_state = MAIN;
    delay(150);
  }
  
  list_position++;
  display_position++;

  if(is_pressed(px, py, 
      x, 
      (display_position*y)+(list_position*y1), 
      x1, 
      display_position*(y+y1)
  )){
    requires_redraw = true;
    current_state = VALUE_ENTRY;
    delay(150);
  }

}