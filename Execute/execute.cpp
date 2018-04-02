#include "FiguresDll.h"
#include <vector>
#include <memory>
#include <algorithm>
bool sort_function(Point* i, Point* j)
{
    return ((*i).Square() < (*j).Square());
}
int main() {
   regular_polygons one_pol(0, 0, 1, 1, 3);//выполнение второго задания
   regular_polygons two_pol(1, 1, 2, 2, 4);
   Triangle two_triangl(0, 0, 1, 1, 1, 0);
   Triangle one_triangl (0, 0, 2, 2, 2, 0);
   Rectangle one_rectangl(0, 0, 1, 1, 1, 0);
   Rectangle two_rectangl(1, 1, 2, 2, 3, 1);
   std::vector<Point*> OurContainer(6);
   OurContainer[0] = &one_triangl;
   OurContainer[1] = &two_triangl;
   OurContainer[2] = &one_rectangl;
   OurContainer[3] = &two_rectangl;
   OurContainer[4] = &one_pol;
   OurContainer[5] = &two_pol;
   std::vector<Point*> OurContainer2;//выполнение третьего задания
   for (size_t i = 0; i < OurContainer.size(); i++)
   {
       if (dynamic_cast<Triangle*>(OurContainer[i])) {
           OurContainer2.push_back(dynamic_cast<Triangle*>(OurContainer[i]));
       }
   }
   std::sort(OurContainer2.begin(), OurContainer2.end(), sort_function);//выполнение четвертого задания
   double sum_square = 0;// выполнение пятого задания
    #pragma omp parallel for reduction(i:sum_square)
   for (size_t i = 0; i < OurContainer2.size(); i++)
   {
       sum_square += OurContainer2[i]->Square();
   }
}