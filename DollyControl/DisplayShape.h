#ifndef DISPLAY_H
#define DISPLAY_H

class DisplayShape{
  public:
    int x,x1,y,y1;

    DisplayType display_type;
    TriangleDirection direction;

    int width,height,radius,size,tail_length;

    int16_t bg_color;

    DisplayShape(){}
    DisplayShape(int x,int y,int x1,int y1, int16_t bg_color){
      this->x=x;
      this->y=y;
      this->x1=x1;
      this->y1=y1;
      this->width = (x1-x);
      this->height = (y1-y);
      this->bg_color = bg_color;
      this->display_type = RECTANGLE;
    }

    DisplayShape(int x, int y, int radius, int16_t bg_color){
      this->x = x;
      this->y = y;
      this->radius = radius;
      this->bg_color = bg_color;
      this->display_type = CIRCLE;
    }

    DisplayShape(int x, int y, int size, TriangleDirection direction, int16_t bg_color) : DisplayShape(){

        this->display_type = TRIANGLE;
        this->direction = direction;

        this->x = x;
        this->y = y;
        this->size = size;
        this->bg_color = bg_color;
    }

    DisplayShape(int x, int y, int size, int tail_length, TriangleDirection direction, int16_t bg_color) : DisplayShape(){

      this->display_type = ARROW;
      this->direction = direction;

      this->x = x;
      this->y = y;
      this->size = size;
      this->tail_length = tail_length;
      this->bg_color = bg_color;
    }

    void set_color(int bg_color){
      this->bg_color= bg_color;
    }

    boolean is_pressed(int px, int py){
      switch(this->display_type){
        case RECTANGLE: return is_r_pressed(px, py);
        case CIRCLE: return is_c_pressed(px, py);
      }
    }

    boolean is_r_pressed(int px, int py){
      return px > x && px < x1 && py > y && py < y1;
    }

    boolean is_c_pressed(int px,int py){
      return (px > x-radius && px < x+radius) && (py > y-radius && py < y+radius);
    }
};

#endif 