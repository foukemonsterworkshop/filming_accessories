void draw_menu(Menu menu){
  Serial.println("Drawing menu: " + menu.name);
  MenuItem* ptr = menu.items;
  for(int i = 0; i < menu.size; i++){
    if(ptr->initialized){
    draw_rectangle(ptr->area, ptr->bgColor);
    show_label(ptr->label);
    //if(ptr->button.separateButton){
      //draw button
    //}
    Serial.println("Drawn menuItem: " + ptr->name);
    }
    ptr++;
  }
  if(menu.homeButton.initialized){
      draw_home_button(menu.homeButton);
  }
  Serial.println("Finished drawing menu: " + menu.name);
}

void draw_rectangle(DisplayRectangle rectangle, int16_t color){
  lcd.Fill_Rect(rectangle.x1, rectangle.y1, rectangle.width, rectangle.height, color);
}

void show_label(Label label){
    lcd.Set_Text_Mode(label.mode);
    lcd.Set_Text_Size(label.textSize);
    lcd.Set_Text_colour(label.textColor);
    lcd.Set_Text_Back_colour(label.bgTextColor);
    lcd.Print_String(label.content, label.x, label.y);
}

void draw_home_button(HomeButton home){
    lcd.Set_Draw_color(home.c_area.bgColor);
    lcd.Fill_Circle(home.c_area.x, home.c_area.y, home.c_area.radius);
    String name = "Home";
    int name_size = 1;
    Label home_label = Label(name, 
      home.c_area.x-name.length()*name_size*6/2+name_size/2+1,
      home.c_area.y-name_size*8/2+name_size/2+1,
      name_size,
      BLACK, BLACK, 1
    );
    show_label(home_label);

}