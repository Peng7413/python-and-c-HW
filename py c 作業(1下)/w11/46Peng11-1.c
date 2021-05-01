#include <stdio.h>
#include <string.h>
#include <math.h>

#define ShapeText(TYPE) \
char name[10];\
float (*perimeter)(struct TYPE*);\
float (*area)(struct TYPE*);
typedef struct _Shape { // Shape 物件，沒有欄位
    ShapeText(_Shape);
} Shape;
typedef struct Circle_s{
    ShapeText(Circle_s);
    float radius;
}Circle_t;
typedef struct Rectangle_s{
    ShapeText(Rectangle_s);
    float width;
    float height;
}Rectangle_t;
typedef struct Square_s{
    ShapeText(Square_s);
    float side;
}Square_t;
typedef struct Triangle_s{
    ShapeText(Triangle_s);
    float side1;
    float side2;
    float side3;
}Triangle_t;

float ShapeArea(Shape *obj){return 0;}
float ShapePerimeter(Shape *obj){return 0;}

float CircleArea(Circle_t *obj){return 3.14*obj->radius*obj->radius;}
float CirclePerimeter(Circle_t *obj){return 2*3.14*obj->radius;}

float RectangleArea(Rectangle_t *obj){return obj->width*obj->height;}
float RectanglePerimeter(Rectangle_t *obj){return 2*obj->height+2*obj->width;}

float SquareArea(Square_t *obj){return obj->side*obj->side;}
float SquarePerimeter(Square_t *obj){return 4*obj->side;}

float TrianglePerimeter(Triangle_t *obj){return obj->side1+obj->side2+obj->side3;}
float TriangleArea(Triangle_t *obj){
    float s;
    s=TrianglePerimeter(obj)/2;
    return sqrt(s*(s-obj->side1)*(s-obj->side2)*(s-obj->side3));
}

void ShapeNew(Shape *obj) {
    strcpy(obj->name,"shape");
    obj->perimeter = ShapePerimeter;
    obj->area = ShapeArea;
}
void CircleNew(Circle_t *obj){
    strcpy(obj->name,"circle");
    obj->perimeter = CirclePerimeter;
    obj->area = CircleArea;
}

int main(){
    int i;
    Shape s;
    Circle_t c;
    ShapeNew(&s);
    CircleNew(&c);
    c.radius=3.0;
    Shape *list[] = {&s,(Shape*)&c};
    for(i=0;i<2;i++){
        Shape *o = list[i];
        printf("%s.perimeter()=%G\n", o->name, o->perimeter(o));
        printf("%s.area()=%G\n", o->name, o->area(o));//多型
    }
}
