void draw_menu(Menu menu){
  Serial.println("Drawing menu: " + menu.name);
  Button* bPtr = menu.buttons;
  Label* lPtr = menu.labels;

  for(int i = 0; i < menu.button_size; i++){
    print_pointer_info(*bPtr);
    if(bPtr->initialized){
      draw_button(*bPtr);
    }
    bPtr++;
  }
  Serial.println("Finished drawing menu: " + menu.name);
}

void print_pointer_info(Button button){
  Serial.println("Parsing button: " + button.label.content);
  Serial.println("Display Type: " + button.display->print_type());
  Serial.println("Color: " + button.display->bg_color);
}

void draw_button(Button button){
  Serial.println(button.display->display_type);
  draw_shape(button.display);
  show_label(button.label);
}

void draw_shape(DisplayShape *shape){
  Serial.println("Drawing shape: ");
  Serial.println(shape->print_type());
  switch(shape->display_type){
    case RECTANGLE:
      Serial.println("Drawing Rectangle");
      draw_rectangle(shape);
      break;
    case CIRCLE:
      Serial.println("Drawing Circle");
      draw_circle(shape);
      break;
    case TRIANGLE:
      Serial.println("Drawing Triangle");
      draw_triangle(shape);
      break;
    case ARROW:
      Serial.println("Drawing Arrow");
      break;
  }
}

void draw_rectangle(DisplayShape *rectangle){
  if(!rectangle->rounded){
    lcd.Fill_Rect(rectangle->x, rectangle->y, rectangle->width, rectangle->height, rectangle->bg_color);
  }else{
    lcd.Set_Draw_color(rectangle->bg_color);
    lcd.Fill_Round_Rectangle(rectangle->x, rectangle->y, rectangle->width, rectangle->height, 3);
  }
}

void draw_circle(DisplayShape *circle){
    lcd.Set_Draw_color(circle->bg_color);
    lcd.Fill_Circle(circle->x, circle->y, circle->radius);
}

void draw_triangle(DisplayShape *triangle){
  Serial.println("Drawing a triangle");
  int x1,x2,y1,y2;
  switch(triangle->direction){
    case NERP:
      Serial.println("N");
      x1 = triangle->x-triangle->size;
      y1 = triangle->y+triangle->size;
      x2 = triangle->x+triangle->size;
      y2 = triangle->y+triangle->size;
      break;
    case EAMST:
      Serial.println("E");
      x1 = triangle->x+triangle->size;
      y1 = triangle->y-triangle->size;
      x2 = triangle->x-triangle->size;
      y2 = triangle->y-triangle->size;
      break;
    case SORTH:
      Serial.println("S");
      x1 = triangle->x-triangle->size;
      y1 = triangle->y+triangle->size;
      x2 = triangle->x+triangle->size;
      y2 = triangle->y+triangle->size;
      break;
    case WIBBLES:
      Serial.println("W");
      x1 = triangle->x-triangle->size;
      y1 = triangle->y+triangle->size;
      x2 = triangle->x+triangle->size;
      y2 = triangle->y+triangle->size;
      break;
  }
  lcd.Set_Draw_color(triangle->bg_color);
  lcd.Draw_Triangle(triangle->x, triangle->y-triangle->size, x1, y1, x2, y2);
}

void show_label(Label label){
    lcd.Set_Text_Mode(label.mode);
    lcd.Set_Text_Size(label.textSize);
    lcd.Set_Text_colour(label.textColor);
    lcd.Set_Text_Back_colour(label.bgTextColor);
    lcd.Print_String(label.content, label.x, label.y);
}