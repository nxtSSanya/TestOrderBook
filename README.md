# OrderBook

Задача: дан набор реальных биржевых данных (формат сообщений прилагается в файле huobi.json). В первой строчке находится снепшот стакана, далее следуют сообщения об апдейтах. Реализовать программу на языке C++, которая восстанавливает снепшоты стаканов на каждый апдейт. В выходной файл необходимо вывести цены и объемы лучших уровней best bid и best ask с временной меткой. 

Решение состоит из 6 файлов:
- OrderBookMap.h / OrderBookMap.cpp является структурой данных для хранения снепшота. Решение построено на основе std::map, также реализованы методы для получения best bid и best ask, удаления уровня с нулевой валютой (сделка) и вставки элемента.
- Reverser.h возвращает ReverseIterator и нужен для обратного итерирования по контейнеру.
- benchmark.h / benchmark.cpp класс для получения времени работы части кода. Используется для вывода времени вставки/получения best bid и best ask.
- Source.cpp содержит точку входа. Чтение входных данных, парсинг, заполнение структуры данных, логирование. Парсинг производится с помощью std::string и boost::property_tree.

# Дополнительные библиотеки/программы
1. Для запуска нужна библиотека [Boost](https://www.boost.org/)
2. Также нужна система сборки [CMake](https://cmake.org/download/)
# Запуск
Если предыдущий раздел выполнен и нужные библиотеки/системы сборки установлены, то:
- Клонируем репозиторий командой `git clone https://github.com/nxtSSanya/TestOrderBook` или можно скачать архивом.
- Создаем поддиректорию с любым именем 
`mkdir cmakeout`
- Переходим в созданную директорию 
`cd cmakeout/`
- Выполняем следующие команды в консоли:
`cmake ..`
`cmake --build .`

- Перейдем в поддиректорию Debug:
`cd Debug`

В данной директории находится исполняемый файл, для работы нужно вставить файл с исходными данными `"huobi.json"` в текущую директорию, после чего запустить программу.
# Запуск бенчмарков
Для работы бенчмарка нужно создать объект типа `Benchmark`, затем поместить "измеряемый" участок кода между функциями `start()` и `stop()`. Функция `getNanos()` вернет время работы кода в наносекундах. Пример:
```
Benchmark timer;
timer.start();
/*Some magic*/
timer.end();
time_bid = timer.getMicros();
```
# Оценка сложности
Так как в решении используется std::map, которая построена на основе [Красно-черного дерева](https://ru.wikipedia.org/wiki/Красно-чёрное_дерево), то вставка/удаление/min/max будут выполняться за O(logN). В данной реализации, вычисление best bid/best ask имеет сложность O(1).
# Возможные улучшения
На мой взгляд, решение с использованием std::map хоть и является стабильным, но как вариант можно получать из цены индекс массива и использовать std::vector, который имеет доступ к элементу за O(1). Так как мы знаем, что max_size стакана равен 40, и реаллокация происходить не будет, то данный вариант будет оптимальнее для вставки. Для получения max/min не все тривиально: либо стоит использовать stl алгоритмы за O(n), либо вставлять в конкретное место, что усложнит реализацию.
Также, стоит создать отдельный класс для загрузки и обработки данных, а не делать это в main)
