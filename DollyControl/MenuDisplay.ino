
void draw_menu(Menu menu){
  MenuItem* ptr = menu.items;
  for(int i = 0; i < menu.size; i++){
    draw_rectangle(ptr->area, ptr->bgColor);
    show_label(ptr->label);
    ptr++;
  }
}

void draw_rectangle(DisplayRectangle rectangle, int16_t color){
  lcd.Fill_Rect(rectangle.x1, rectangle.y1, rectangle.x2, rectangle.height, color);
}

void show_label(Label label){
    lcd.Set_Text_Mode(label.mode);
    lcd.Set_Text_Size(label.textSize);
    lcd.Set_Text_colour(label.textColor);
    lcd.Set_Text_Back_colour(label.bgTextColor);
    lcd.Print_String(label.content, label.x, label.y);
}