#include<cstdio.h>
  
struct punto *nuevoPunto(float x, float y) {
    struct punto a= { x, y };
    return &a;  /* ¡No haga esto! */
  }
  
  int main() {
    struct punto *p= nuevoPunto(1.0, 2.0);
    printf("(%f,%f)\n", p->x, p->y);  /* ¡Despliega los valores correctos! */
    printf("(%f,%f)\n", p->x, p->y);  /* ¡Despliega basura! */
    return 0;
  }
