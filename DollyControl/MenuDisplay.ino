void draw_menu(Menu menu){
  Serial.println("Drawing menu: " + menu.name);
  MenuItem* ptr = menu.items;
  for(int i = 0; i < menu.size; i++){
    if(ptr->initialized){
    draw_rectangle(ptr->area, ptr->area.bgColor);
    show_label(ptr->label);
    //if(ptr->button.separateButton){
      //draw button
    //}
    Serial.println("Drawn menuItem: " + ptr->name);
    }
    ptr++;
  }
  Serial.println("Finished drawing menu: " + menu.name);
}

void draw_shape(MenuItem item){
  switch(item.area.display_type){
    case RECTANGLE:
      draw_rectangle(item.area, item.area.bgColor);
      break;
    case CIRCLE:
      draw_circle(item.area, item.area.bgColor);
      break;
  }
}

void draw_rectangle(DisplayShape rectangle, int16_t color){
  lcd.Fill_Rect(rectangle.x, rectangle.y, rectangle.width, rectangle.height, color);
}

void draw_circle(DisplayShape circle, int16_t color){
    lcd.Set_Draw_color(color);
    lcd.Fill_Circle(circle.x, circle.y, circle.radius);
}

void show_label(Label label){
    lcd.Set_Text_Mode(label.mode);
    lcd.Set_Text_Size(label.textSize);
    lcd.Set_Text_colour(label.textColor);
    lcd.Set_Text_Back_colour(label.bgTextColor);
    lcd.Print_String(label.content, label.x, label.y);
}