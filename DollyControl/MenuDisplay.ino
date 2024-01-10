void draw_menu(Menu menu){
  Serial.println("Drawing menu: " + menu.name);
  MenuItem* ptr = menu.items;
  for(int i = 0; i < menu.size; i++){
    if(ptr->initialized){
      if(ptr->button_size>0){
        for(int j = 0; j < ptr->button_size; j++){
          draw_shape(ptr->button->area);
          show_label(ptr->button->label);
          ptr->button++;
        }
      }
      else{
        draw_shape(ptr->button->area);
        show_label(ptr->button->label);
      }
      Serial.println("Drawn menuItem: " + ptr->name);
    }
    ptr++;
  }
  Serial.println("Finished drawing menu: " + menu.name);
}

void draw_shape(DisplayShape shape){
  switch(shape.display_type){
    case RECTANGLE:
      Serial.println("Drawing Rectangle");
      draw_rectangle(shape, shape.bgColor);
      break;
    case CIRCLE:
      Serial.println("Drawing Circle");
      draw_circle(shape, shape.bgColor);
      break;
  }
}

void draw_rectangle(DisplayShape rectangle, int16_t color){
  Serial.print("starting y: " + rectangle.y);
  lcd.Fill_Rect(rectangle.x, rectangle.y, rectangle.width, rectangle.height, color);
}

void draw_circle(DisplayShape circle, int16_t color){
    lcd.Set_Draw_color(color);
    lcd.Fill_Circle(circle.x, circle.y, circle.radius);
}

void show_label(Label label){
    Serial.println("Drawing Label: " + label.content);
    lcd.Set_Text_Mode(label.mode);
    lcd.Set_Text_Size(label.textSize);
    lcd.Set_Text_colour(label.textColor);
    lcd.Set_Text_Back_colour(label.bgTextColor);
    lcd.Print_String(label.content, label.x, label.y);
}