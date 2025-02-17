#include <iostream>
#include "include/point.h"
#include "include/rectangle.h"
#include "include/square.h"
#include "include/triangle.h"
#include "include/array.h"

using namespace std;

int main()
{
  Array<Figure<int>> figures;

  while (true)
  {
    cout << "Выберите действие:\n";
    cout << "1. Добавить фигуру\n";
    cout << "2. Удалить фигуру\n";
    cout << "3. Вывести все фигуры\n";
    cout << "4. Вычислить общую площадь\n";
    cout << "5. Выход\n";
    int choice;
    cin >> choice;

    switch (choice)
    {
      case 1:
      {
        cout << "Выберите тип фигуры:\n";
        cout << "1. Прямоугольник\n";
        cout << "2. Квадрат\n";
        cout << "3. Треугольник\n";
        int fig_choice;
        cin >> fig_choice;

        shared_ptr<Figure<int>> fig;

        switch (fig_choice)
        {
          case 1:
            fig = make_shared<Rectangle<int>>();
            break;
          case 2:
            fig = make_shared<Square<int>>();
            break;
          case 3:
            fig = make_shared<Triangle<int>>();
            break;
          default:
            cout << "Неверный выбор фигуры.\n";
            continue;
        }

        cin >> *fig;
        figures.push_back(fig);
        break;
      }
      case 2:
      {
        cout << "Введите индекс фигуры для удаления: ";
        size_t index;
        cin >> index;
        if (index >= figures.get_size())
        {
          cout << "Неверный индекс.\n";
        }
        else
        {
          figures.remove_at(index);
          cout << "Фигура удалена.\n";
        }
        break;
      }
      case 3:
      {
        for (size_t i = 0; i < figures.get_size(); ++i)
        {
          cout << "Фигура " << i << ":\n";
          cout << *figures[i];
          auto center = figures[i]->Center();
          cout << "Центр фигуры: " << *center << endl;
          double area = *figures[i];
          cout << "Площадь фигуры: " << area << endl;
          cout << "-------------------------\n";
        }
        break;
      }
      case 4:
      {
        double total_area = 0.0;
        for (size_t i = 0; i < figures.get_size(); ++i)
        {
          total_area += static_cast<double>(*figures[i]);
        }
        cout << "Общая площадь фигур: " << total_area << endl;
        break;
      }
      case 5:
        return 0;
      default:
        cout << "Неверный выбор действия.\n";
        break;
    }
  }
  return 0;
}