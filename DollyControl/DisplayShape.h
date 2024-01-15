#ifndef DISPLAY_H
#define DISPLAY_H

class DisplayShape{
  public:
    int x,x1,y,y1;

    int press_region[4];

    DisplayType display_type;
    TriangleDirection direction;

    int width,height,radius,size,tail_length;

    int16_t bg_color;

    DisplayShape(){}
    DisplayShape(int x,int y,int x1,int y1, int16_t bg_color){

      this->display_type = RECTANGLE;

      this->x=x;
      this->y=y;
      this->x1=x1;
      this->y1=y1;
      this->width = (x1-x);
      this->height = (y1-y);
      this->bg_color = bg_color;
    }

    DisplayShape(int x, int y, int radius, int16_t bg_color){

      this->display_type = CIRCLE;

      this->x = x;
      this->y = y;
      this->radius = radius;
      this->bg_color = bg_color;
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

    int* press_area(){
      int array[4];
      switch(this->display_type){
        case RECTANGLE:  
          array[0] = this->x;
          array[1] = this->y;
          array[2] = this->x1;
          array[3] = this->y1;
          break;
        case CIRCLE: 
          array[0] = this->x-this->radius;
          array[1] = this->y-this->radius;
          array[2] = this->x+this->radius;
          array[3] = this->y+this->radius;
          break;
        case TRIANGLE:
          break;
        case ARROW: 
          break;
      }
      return array;
    }
};

#endif 