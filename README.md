# Template containers
Template containers and checking their performance using googletest.
# Dycont_t
Шаблон «динамический массив объектов». Размерность массива не изменяется в момент его
переполнения. Начальная размерность задается как параметр конструктора, значение по
умолчанию 0. Метод изменения размера. Добавление/удаление элемента в про извольное
место.
# Stack_t
Шаблон «стек» (внутреннее представление – динамический массив хранимых объектов).
Размерность стека увеличивается в момент его переполнения. Начальная размерность
задается как параметр конструктора, значение по умолчанию 0. Добавление/удаление
элемента в начало и в конец.
# List_t
Шаблон «односвязный список объектов». Добавление/удаление элемента в произвольное
место.
# Queue_t
Шаблон «циклическая очередь» (внутреннее представление – динамический массив
хранимых объектов). Добавление/удаление элемента в произвольное место.
# Tree_t
Шаблон «двоичное дерево объектов». Добавление/удаление элемента в произвольное место.
# Googletest
Для тестирования работоспособности контейнеров была использована библиотека googletest.
