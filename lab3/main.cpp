#include "include/Triangle.h"
#include "include/Square.h"
#include "include/Rectangle.h"
#include <memory>

using namespace std;

int main()
{
  vector<shared_ptr<Figure>> figures;

  while (true)
  {
    cout << "\nМеню:\n";
    cout << "1. Добавить треугольник\n";
    cout << "2. Добавить квадрат\n";
    cout << "3. Добавить прямоугольник\n";
    cout << "4. Вывести фигуры\n";
    cout << "5. Вывести центры фигур\n";
    cout << "6. Вывести площади фигур\n";
    cout << "7. Вывести общую площадь\n";
    cout << "8. Удалить фигуру\n";
    cout << "9. Выйти\n";
    cout << "Выберите опцию: ";

    int option;
    cin >> option;

    switch (option)
      {
      case 1:
      {
        auto fig = make_shared<Triangle>();
        cin >> *fig;
        figures.push_back(fig);
        break;
      }
      case 2:
      {
        auto fig = make_shared<Square>();
        cin >> *fig;
        figures.push_back(fig);
        break;
      }
      case 3:
      {
        auto fig = make_shared<Rectangle>();
        cin >> *fig;
        figures.push_back(fig);
        break;
      }
      case 4:
      {
        for (size_t i = 0; i < figures.size(); ++i)
        {
          cout << i << ": " << *figures[i] << endl;
        }
        break;
      }
      case 5:
      {
        for (size_t i = 0; i < figures.size(); ++i)
        {
          auto center = figures[i]->Center();
          cout << i << ": Центр в (" << center.first << ", " << center.second << ")\n";
        }
        break;
      }
      case 6:
      {
        for (size_t i = 0; i < figures.size(); ++i)
        {
          double area = static_cast<double>(*figures[i]);
          cout << i << ": Площадь = " << area << "\n";
        }
        break;
      }
      case 7:
      {
        double total_area = 0;
        for (const auto &fig : figures)
        {
          total_area += static_cast<double>(*fig);
        }
        cout << "Общая площадь: " << total_area << "\n";
        break;
      }
      case 8:
      {
        cout << "Введите индекс для удаления: ";
        size_t index;
        cin >> index;
        if (index < figures.size())
        {
          figures.erase(figures.begin() + index);
          cout << "Фигура с индексом " << index << " удалена\n";
        }
        else
        {
          cout << "Неверный индекс\n";
        }
        break;
      }
      case 9:
      {
        return 0;
      }
      default:
      {
        cout << "Неверная опция\n";
        break;
      }
    }
  }

  return 0;
}