#include <iostream>
#include <deque>
#include<algorithm>
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

    int i = 0;
    std::deque<int> deq1;
    std::remove_copy_if(deq.rbegin() + deq.size() / 2, deq.rend(), std::front_inserter(deq1), [&i](int) {return (i++ % 2 == 0);});

    std::deque<int> result_deq;
    std::copy(deq.rbegin(), deq.rend() - deq.size() / 2 +1, std::front_inserter(result_deq));

    result_deq.insert(result_deq.begin(), deq1.begin(), deq1.end());

    std::cout << "Преобразованный дек:" << std::endl;
    for (auto elem : result_deq)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
