#include <iostream>
#include <deque>

int main()
{
    std::setlocale(LC_ALL, "RU");

    std::deque<int> deq = { 1, 2, 3, 4, 5, 6, 7, 8 ,9,10,11,12 };

    std::cout << "Исходный дек:" << std::endl;
    for (auto elem : deq)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    if (deq.size() % 4 != 0)
    {
        std::cout << "Число элементов не кратно 4" << std::endl;
        return 1;
    }

    auto r = deq.rbegin() + deq.size() / 2;
    int i = 0;
    for (auto r = deq.rbegin() + deq.size() / 2;r != deq.rend();++r)
    {
        if (i % 2 == 0)
        {
            r = decltype(r)(deq.erase(--r.base()));
            ++i;
        }
        ++i;
    }

    std::cout << "Преобразованный дек:" << std::endl;
    for (auto elem : deq)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
