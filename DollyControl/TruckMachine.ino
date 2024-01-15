void init_truck_menu(){
  int border = 5;
  int selection_height = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  int position = 0;
  int offset = 1;

  int labelXOffset = 2*border;
  int labelYOffset = 12;

  lcd.Fill_Rect(border, (offset*border)+(position*selection_height), xOffset, offset*(border+selection_height), LIGHTGREY);
  show_label("Main From Truck",labelXOffset,labelYOffset,2,BLACK, BLACK,1);

  draw_nav_button("Home");
}