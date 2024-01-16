void init_parallax_menu(){
  int x = 5;
  int y = 5;
  int x1 = lcd.Get_Display_Width()-x;
  int y1 = 30;

  int list_position = 0;
  int display_position = 1;

  int labelXOffset = 2*x;
  int labelYOffset = 12;

  lcd.Set_Draw_color(LIGHTGREY);
  lcd.Fill_Round_Rectangle(
    x, 
    (display_position*y)+(list_position*y1), 
    x1, 
    display_position*(y+y1), 
    3);
  show_label("Main From Parallax",labelXOffset,labelYOffset,2,BLACK, BLACK,1);

  draw_nav_button("Home");
}